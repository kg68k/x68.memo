# C Compiler PRO-68K ver2.1 NEW KITの不具合

* STUDIO KAMADA &gt; X680x0 のメーカー純正ソフトウェアの不具合について &gt; [4. XC ライブラリの不具合](https://stdkmd.net/bugsx68k/#xclib)
* [無償公開版](http://retropc.net/x68000/software/sharp/xc21/)

## SCD.X
* (おそらくv3系すべて?) gcc -gで生成した実行ファイルのソースコードデバッグでステップ実行するとアドレスエラーが発生することがある。
  -finline-functionsを指定する(または環境変数`GCC_OPTION1=I`)と発生しない。SCD.X側の問題かどうかは不明。

## 無償公開版に特有と思われる問題
* XC2103.LZH, XC2103I.LZH: \ASK30\MAKEFILEの内容がACI.Hと同一。

## サンプルコード
* ライブラリディスクの\ASK30\FILES.Cの93行目の条件式が`ftotal <= MAXFILES`となっているため、ファイルが多いとバッファオーバーフローが起きる。
  ```c
  		} while (nfiles() == 0 && ftotal <= MAXFILES);
  ```

## INCLUDE\\TIME.H
* `CLOCKS_PER_SEC`が定義されていない。
  ([@towser_meow/1638474969494724609](https://x.com/towser_meow/status/1638474969494724609))
  * 代わりにINCLUDE\\STDDEF.Hで`CLOCKS_PAR_SEC`が定義されている。

## `IOCTRLFDCTL()`、`IOCTRLDVCTL()`
* (おそらく全バージョン) 関数の機能が入れ替わっている。  
  * NEW KITの拡張マニュアルには`IOCTRLFDCTL()`がドライブ番号`drive`を指定する関数という説明が記載されている。

## `IOCTRLRTSET()`
* `md`の値が間違っているため正しく動作しない。

## `spawnl()`、`spawnle()`、`spawnv()`、`spawnve()`
* 環境変数pathで指定したディレクトリから実行ファイルを検索してしまう。


# マニュアルの不具合

## CライブラリマニュアルVOL2
* (参考情報) ver2.0では、P.370 SP_REGSTにMODEという引数があるが間違い。
  垂直帰線期間検出は`SPRITENO`の最上位ビットで設定する。
  NEW KITでは訂正されている。

## 拡張マニュアル
* P.111 _B_SCROLL
  * 機能のMODE=16、MODE=17はMODE=17、MODE=18が正しい。
* P.221 B_CONMOD
  * 解説のD1.L = 1～4はD1.L = 0～3が正しい。


----
goto [index](../../README.md) / [プログラミング](../README.md) / [XC](README.md)
