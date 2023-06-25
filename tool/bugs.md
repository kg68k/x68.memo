# 不具合

## PD LIBC
* [TODO](../prog/libc.md#todo)

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

## ZMSC3LIB Version 0.01
* スーパーバイザモードで`zm_check_zmsc()` (ZMCHECKZMSC.HAS)を呼び出すとアドレスエラーが発生する。
  * スーパーバイザになるための`IOCS _B_SUPER`の返り値を見てユーザーモードに戻るための`_B_SUPER`を省略しなければならないが、
    その処理が抜けているため。

## Z-MUSIC Ver.3.02C
* ZMC.X
  * 上限下限あり8ビット値の配列で、値の直後の2連続セパレータが単独のセパレータとして解釈されてしまう。
    ([@kg68k/1482025079017926658](https://twitter.com/kg68k/status/1482025079017926658))
  * 上限下限あり16ビット値の配列で、上限値・下限値が正しく適用されないことがある。
  ([@kg68k/1482027532736245763](https://twitter.com/kg68k/status/1482027532736245763))
  * `.FM_TUNE_SETUP`をint16_tではなくint8_tとしてコンパイルしてしまう。
  ([@arith_rose/1481388558246051842](https://twitter.com/arith_rose/status/1481388558246051842))
* 未検証
  * https://twitter.com/T_Forth_3/status/1630378141385654272
  * https://twitter.com/T_Forth_3/status/1630425279058542592
  * mpcm.x非常駐時に`zm_se_adpcm1`でADPCMが再生されない。
    ([@DD_samidare_kai/1662447722979532801](https://twitter.com/DD_samidare_kai/status/1662447722979532801))  
    `se_mode`をセットして`adpcmout:`を呼ぶ → `adpcm_end:`で`se_mode`がセットされているためDMAを停止しない、という動作が影響？
* マニュアル(ZM302_M.LZH)
  * ZM4.MAN - `.FM_TUNE_SETUP`、`.ADPCM_TUNE_SETUP`のt1～t128の値の上限が+32768と書かれている(本文は正しい)。

## こ-ＢＡＳＩＣ ver.0.01 (H8/11/11 版)
* kofunc.docの
  ```
  DrawCardMono( wno;int, x;int, y;int, num;int, card;int )
  ```
  の関数名は`DrawMonoCard`が正しい。
  ([@ShirohSuzuki/1672859593654022146](https://twitter.com/ShirohSuzuki/status/1672859593654022146))


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
