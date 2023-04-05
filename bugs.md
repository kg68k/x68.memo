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
https://gist.github.com/kg68k/4b64e5de6b5be72492640b8ec41c46dd  
LIBCとLIBCぱっちをまとめて書き連ねてるのでご了承願います。

----
# 2000年問題

この節では修正パッチや改造版があるソフトウェアも掲載しています。

## Binary file updater v1.2 rel.2
bup -l/-lm でファイルの日付の表示が乱れる。パッチあり。

## Ease Filer (95/04/07 版)
ファイルの日付の表示が乱れる。パッチあり。

## EDR-plus version 2.0.1(yakko-chan)
セレクタ画面のファイルの日付の表示が乱れる。パッチあり。

## lhv version 0.95.2
セレクタ画面のファイルの日付の表示が乱れる。パッチあり。

## WS v0.90
現在の日付の表示が乱れる。パッチあり。

## 時計.X (SX-Window version 3.10)
西暦の表示が乱れる。パッチあり。


----
[goto index](README.md)
