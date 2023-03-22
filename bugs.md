# 不具合

## cpupower.r Ver0.1
* 実行時にMFP TCDR($e88023; Timer-Cデータレジスタ)の値を本来の値200から256相当に書き換えるが、
終了時に戻さないためTimer-C割り込みの間隔が1.28倍に変わってしまう。  
  * カーソル点滅速度やSystem Informationのprocessor performance値に影響する。

参考：[@kg68k/1492793567512711170](https://twitter.com/kg68k/status/1492793567512711170)

## GNU Make version 3.79 human68k-1.2
* リモートファイルシステム上でMakefileを読み込めない。
* リモートファイルシステム上で別のディレクトリを同一視してしまう。

## C Compiler PRO-68K ver2.1 NewKit
* INCLUDE\TIME.Hで`CLOCKS_PER_SEC`が定義されていない。
  * 代わりにINCLUDE\STDDEF.Hで`CLOCKS_PAR_SEC`が定義されている。

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
