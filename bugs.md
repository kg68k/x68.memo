# 不具合

## cpupower.r Ver0.1
実行時にMFP TCDR($e88023; Timer-Cデータレジスタ)の値を本来の値200から256相当に書き換えるが、
終了時に戻さないためTimer-C割り込みの間隔が1.28倍に変わってしまう。  
カーソル点滅速度やSystem Informationのprocessor performance値に影響する。

参考：[@kg68k/1492793567512711170](https://twitter.com/kg68k/status/1492793567512711170)

## GNU Make version 3.79 human68k-1.2
* リモートファイルシステム上でMakefileを読み込めない。
* リモートファイルシステム上で別のディレクトリを同一視してしまう。


----
[goto index](README.md)
