# 不具合

## cpupower.r Ver0.1
* 実行時にMFP TCDR($e88023; Timer-Cデータレジスタ)の値を本来の値200から256相当に書き換えるが、
終了時に戻さないためTimer-C割り込みの間隔が1.28倍に変わってしまう。
([@kg68k/1492793567512711170](https://twitter.com/kg68k/status/1492793567512711170))
  * カーソル点滅速度やSystem Informationのprocessor performance値に影響する。

## GNU Make version 3.79 human68k-1.2
* version 3.79 human68k-1.4で修正済み。ただし仮想ディレクトリまわりの処理がまだ完全には解決していないはず。
  * ~~リモートファイルシステム上でMakefileを読み込めない。~~
  * ~~リモートファイルシステム上で別のディレクトリを同一視してしまう。~~

## C Compiler PRO-68K ver2.1 NewKit
* STUDIO KAMADA &gt; X680x0 のメーカー純正ソフトウェアの不具合について &gt; [4. XC ライブラリの不具合](https://stdkmd.net/bugsx68k/#xclib)
* INCLUDE\\TIME.Hで`CLOCKS_PER_SEC`が定義されていない。
([@towser_meow/1638474969494724609](https://twitter.com/towser_meow/status/1638474969494724609))
  * 代わりにINCLUDE\\STDDEF.Hで`CLOCKS_PAR_SEC`が定義されている。

## RAM DISK DRIVER 「GRAD.r」 Version 1.30
* DOS \_MALLOC2でメモリを確保しているプロセスがあるときにGRAD.rを`-g -b`オプションで登録しようとするとエラー終了するが、
その際にグラフィック画面の使用モード(IOCS \_TGUSEMD)が「1:システムが使用中」に変更されてしまう。

## PD LIBC
* [TODO](../prog/libc.md#todo)

## X68k RCD: RC play driver v3.01q
* `DOS _KEEPPR`に渡す常駐バイト数にデータセクションの大きさが含まれておらず、またスタック範囲外の値を加算している。
  他の部分のコードの影響により結果として問題が顕在化しないことが多いと思われるが、場合(値)によっては異常動作を引き起こす。

## HAS060.X version 3.09+89
* HAS060.X - アセンブラ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY &gt;
  [既知の不具合](http://retropc.net/x68000/software/develop/as/has060/knownbug.htm)
* `-c4`オプションを指定すると、`ADDA.W #$8000,An`が`SUBA.W #$8000,An`に変更されてしまう。
  [Xperiment68k - has060c4](https://github.com/kg68k/xperiment68k#has060c4)
* ベースディスプレースメントにサイズを指定しないと「オフセットが範囲外です」になることがある。
```
.cpu 68020
  moveq #0,d0
  tst.b (foo,pc,d0.l)  ;Error: オフセットが範囲外です
  tst.b (bar,pc,d0.l)

; tst.b (foo,pc,d0.l)  ;barに.lをつければOK
; tst.b (bar.l,pc,d0.l)

; tst.b (foo+1,pc,d0.l)  ;foo+1またはfoo-1にしてもOK
; tst.b (bar,pc,d0.l)
  .dc $ff00

  .ds.b 32755
foo: .ds.b 9
bar: .ds.b 1
.end
```

## Pure PASCAL Compiler v1.01
* DEKOのアヤシいお部屋。 &gt; ぴゅあぱすかる。 &gt;
  [既知の問題 (ver 1.01)](https://ht-deko.com/pure.html#%E6%97%A2%E7%9F%A5%E3%81%AE%E5%95%8F%E9%A1%8C-ver-101)



----
# 2000年問題

この節では修正パッチや改造版があるソフトウェアも掲載しています。

## Binary file updater v1.2 rel.2
bup -l/-lm でファイルの日付の表示が乱れる。パッチあり。

## Ease Filer (95/04/07 版)
ファイルの日付の表示が乱れる。パッチあり。

## EDR-plus version 2.0.1(yakko-chan)
セレクタ画面のファイルの日付の表示が乱れる。
[パッチあり](patch/edrp201.pat)。

## lhv version 0.95.2
セレクタ画面のファイルの日付の表示が乱れる。パッチあり。

## WS v0.90
現在の日付の表示が乱れる。パッチあり。

## 時計.X (SX-Window version 3.10)
西暦の表示が乱れる。パッチあり。


----
goto [index](../README.md) / [ツール](./README.md)
