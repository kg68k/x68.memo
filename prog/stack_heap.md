# スタックサイズとヒープサイズの指定

## XCでスタックとヒープサイズを指定する仕組み

XCでは`main()`関数を含むファイルのコンパイル時に、
オプション指定でスタックサイズやヒープサイズを指定できます。
* `/Gs<n>` ... スタックサイズ(`<n>`はバイト数、末尾に`k`を付けるとキビバイト単位)
* `/Gh<n>` ... ヒープサイズ(`<n>`はバイト数、末尾に`k`を付けるとキビバイト単位)

例えばこのようなアセンブラソースファイルが出力されます(主要部分のみ)。
```
        .GLOBL  _main
        .XDEF   _STACK_SIZE
_STACK_SIZE     EQU     1230
        .XDEF   _HEAP_SIZE
_HEAP_SIZE      EQU     4560
        .XREF   __main
        .TEXT
_main:
        LINK    A6,#0
        MOVEQ.L #0,D0
        UNLK    A6
        RTS
```

オプションを指定しない場合は`_STACK_SIZE`や`_HEAP_SIZE`の定義は出力されません。
また、オプションを指定しても`main()`関数を含まないファイルでは出力されません。

これらのシンボルは、CLIB.Lに含まれている\_\_MAIN.Oファイルから参照されています。
```
__STACK:        dc.l    _STACK_SIZE
__HEAP:         dc.l    _HEAP_SIZE
```

サイズが格納された`__STACK`や`__HEAP`をスタートアップルーチンが参照して、
動的にスタックやヒープが設定されます。

さて、オプションを指定せず`_STACK_SIZE`や`_HEAP_SIZE`が定義されなかった場合は
どうなるでしょうか。

CLIB.Lに含まれている\_DEDFSTK.Oにて標準のスタックサイズが定義されています。
```
_STACK_SIZE     equ     65536           . スタック・サイズ
```
同じく\_DEDFHEAP.Oに標準のヒープサイズが定義されています。
```
_HEAP_SIZE      equ     65536           . ヒープ領域サイズ
```

リンカは、リンクするオブジェクトファイル中に参照されているシンボルが見つからなかった場合、
アーカイブ(\*.a)やライブラリ(\*.l)に含まれるオブジェクトファイルからシンボルを探しますので、
`_STACK_SIZE`や`_HEAP_SIZE`が定義されなかった場合はCLIB.L内のこれらのオブジェクトファイルが
リンクされます。


### (XC) シンボル定義によるスタックとヒープサイズの指定

リンク時に規定のシンボルが定義されていればよいので、例えば
```
.xdef _STACK_SIZE
_STACK_SIZE: .equ 32768
```
といったファイルをアセンブルし、一緒にリンクさせるといった方法でも指定できます。


### (XC) ファイル実行時のスタックとヒープサイズの指定

XCライブラリがリンクされた実行ファイルは、実行時にコマンドライン引数で
オプションを指定すればスタックサイズ、ヒープサイズを指定できます。
* `/stack:<n>` ... スタックサイズ(`<n>`はバイト数、末尾に`k`を付けるとキビバイト単位)
* `/heap:<n>` ... ヒープサイズ(`<n>`はバイト数、末尾に`k`を付けるとキビバイト単位)


## 真里子版GCCでスタックとヒープサイズを指定する仕組み

真里子版GCCでは実行ファイルの生成時に
オプション指定でスタックサイズやヒープサイズを指定できます。
* `-z-stack:<n>` ... スタックサイズ(`<n>`はバイト数)
* `-z-heap:<n>` ... ヒープサイズ(`<n>`はバイト数)

XCとは異なり、アセンブラソースファイルやオブジェクトファイルにサイズ指定の情報は出力されません。

リンカ(hlk)実行時にリンカのオプションとして情報が渡されます。
* `-d_STACK_SIZE=<x>` ... スタックサイズ(`<x>`はバイト数の16進数表記)
* `-d_HEAP_SIZE=<x>` ... ヒープサイズ(`<x>`はバイト数の16進数表記)

定数シンボルとして`_STACK_SIZE`や`_HEAP_SIZE`が定義されるので、CLIB.L内の
\_DEDFSTK.Oや\_DEDFHEAP.Oはリンクされず、シンボルの値が使用されます。


### リンカを直接実行する場合のスタックとヒープサイズの指定

コンパイルにのみGCCを使い、オブジェクトファイルから実行ファイルを
生成するのにリンカを直接実行したいという状況になることもあります。

このような場合は、前述の`-d_STACK_SIZE=<x>`や`-d_HEAP_SIZE=<x>`オプションを
自分で渡すことでスタックサイズ、ヒープサイズを指定できます。


## LIBCでスタックとヒープサイズを指定する仕組み

LIBCはライブラリのオブジェクトファイルの構成や内部の構造はXCと異なりますが、
XCとの互換性が考慮されておりスタックサイズやヒープサイズもXCと同じ方法で指定できます。

ただしコンパイラはGCCを使うのが基本となるため、具体的な手順もGCC用のやり方になります。

LIBCでは`_STACK_SIZE`、`_HEAP_SIZE`の値を保持する変数がスタートアップルーチンのファイルに
埋め込まれているのではなく、個別のファイルに分離されているため、それぞれのファイルをリンクする代わりに
独自に用意した変数をリンクするという方法もできます。

参考：当該部分のソースコード
* [_start.c](https://github.com/kg68k/libc-src/blob/main/src/startup/_start.c)
  ... スタートアップルーチン。
* [_stackdef.s](https://github.com/kg68k/libc-src/blob/main/src/startup/_stackdef.s)
  ... `_STACK_SIZE`が指定されなかった場合の既定の定義。
* [_stacksiz.s](https://github.com/kg68k/libc-src/blob/main/src/startup/_stacksiz.s)
  ... `_STACK_SIZE`の値を保持する変数。
* [_heapdef.s](https://github.com/kg68k/libc-src/blob/main/src/startup/_heapdef.s)
  ... `_HEAP_SIZE`が指定されなかった場合の既定の定義。
* [_heapsiz.s](https://github.com/kg68k/libc-src/blob/main/src/startup/_heapsiz.s)
  ... `_HEAP_SIZE`の値を保持する変数。


### (LIBC) ファイル実行時のスタックとヒープサイズの指定

LIBCがリンクされた実行ファイルは、実行時にコマンドライン引数でオプションを
指定すればスタックサイズ、ヒープサイズを指定できます。
* `-+-s:<n>` ... スタックサイズ(`<n>`はバイト数)
* `-+-h:<n>` ... ヒープサイズ(`<n>`はバイト数)

余談：LIBCのスタートアップルーチンには、ほかに`-+-p`、`-+-f`、`-+-g`オプションもあります。


## elf2x68k (newlib)でスタックとヒープサイズを指定する仕組み

既定のスタックサイズを納めた変数`_stack_size`が
[_stacksize.S](https://github.com/yunkya2/elf2x68k/blob/master/src/libx68k/_stacksize.S)にて
```
_stack_size:
	.long	STACK_SIZE
```
として、また規定のヒープサイズを納めた変数`_heap_size`が
[_heapsize.S](https://github.com/yunkya2/elf2x68k/blob/master/src/libx68k/_heapsize.S)にて
```
_heap_size:
	.long	HEAP_SIZE
```
として定義されています。  
(elf2x68kはgccのオプションが既定で`-fno-leading-underscore`のため、C言語からもアセンブリ言語からも変数名が
`_stack_size`、`_heap_size`として見えます)。

ただしXCやLIBCとは異なりこの`STACK_SIZE`、`HEAP_SIZE`は外部参照値ではなく、インクルードしている
[config.h](https://github.com/yunkya2/elf2x68k/blob/master/src/libx68k/config.h)にて
```
/* Set a default stack size */
#ifndef STACK_SIZE
#define STACK_SIZE      32768
#endif

/* Allocate at least some space for heap */
#ifndef HEAP_SIZE
#define HEAP_SIZE       65536
#endif
```
として定義されており、プリプロセスとアセンブルの結果、それぞれ定数値`32768`としてオブジェクトファイル\_stacksize.o、
\_heapsize.oに埋め込まれます。

通常はこの\_stacksize.oと\_heapsize.oがリンクされ、`_stack_size`と`_heap_size`の値をスタートアップルーチンが参照して
動的にスタックとヒープが設定されます。

### elf2x68k (newlib) 変数定義によるスタックとヒープサイズの指定

スタックサイズを指定する場合は\_stacksize.oをリンクさせず、代わりとなる`_stack_size`を用意すればいいので、
[スタックサイズ、ヒープサイズの指定](https://github.com/yunkya2/elf2x68k/tree/master?tab=readme-ov-file#%E3%82%B9%E3%82%BF%E3%83%83%E3%82%AF%E3%82%B5%E3%82%A4%E3%82%BA%E3%83%92%E3%83%BC%E3%83%97%E3%82%B5%E3%82%A4%E3%82%BA%E3%81%AE%E6%8C%87%E5%AE%9A)
で説明されている通り、以下のようなコードを追加するかまたは新規ソースコードに書き込んで一緒にリンクします。
```c
int _stack_size = 128 * 1024;   // 128KB stack
int _heap_size = 256 * 1024;    // 256KB heap
```


## elf2x68kでXCライブラリを使用する場合
`-specs=xc.specs`

### elf2x68k (XC lib) シンボル定義によるスタックとヒープサイズの指定

elf2x68kにはXCの`/Gs<n>`、`/Gh<n>`オプションがないので、それ以外の方法でシンボル値`_STACK_SIZE`、`_HEAP_SIZE`を設定します。

例えばm68k-xelf-gccでリンクする際に`-Wl,--defsym,STACK_SIZE=262144`オプションを指定します。  

ただし、Release 20251124にはファイル変換に不具合があり指定が正しく反映されません。
この不具合は`develop`ブランチの
[Commit a45ad3d](https://github.com/yunkya2/elf2x68k/commit/a45ad3d23b6f56c1edb22ac8ad83ec7a86908bf0)
で修正されています。
修正版がリリースされるまでは
[elf2x68k.py](https://github.com/yunkya2/elf2x68k/blob/develop/src/elf2x68k.py)
を差し替えてください。


----
goto [index](../README.md) / [プログラミング](./README.md)
