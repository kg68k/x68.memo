# C Compiler PRO-68K ver2.1 NEW KITの不具合

* STUDIO KAMADA &gt; X680x0 のメーカー純正ソフトウェアの不具合について &gt; [4. XC ライブラリの不具合](https://stdkmd.net/bugsx68k/#xclib)
* [無償公開版](http://retropc.net/x68000/software/sharp/xc21/)

## AS.X v3.00
* 余計なカンマがエラーにならない。
  ```
  move (a0,),d0
  move ([a0],),d0
  move ([a0],,0),d0
  move ([a0,]),d0
  ```
* `([d16,An])`が`(d16,An)`として解釈される。
  ```
      3 00000000 3028000a           move (10,a0),d0
      4 00000004 3028000a           move ([10,a0]),d0
  ```
* `([d32,An])`がillegal relative errorになる。
  ```
  test.s               3:   illegal relative error
      3 00000000 3028               move ([$10000,a0]),d0
  ```
* `([d16])`、`([d32])`がexpression errorになる。
  ```
  test.s               3:   expression error
      3 00000000                    move ([10]),d0
  test.s               4:   expression error
      4 00000000                    move ([$10000]),d0
  ```
* `([An])`が`(0,An)`として解釈される。
  ```
      3 00000000 30280000           move (0,a0),d0
      4 00000004 30280000           move ([a0]),d0
  ```
* `([a0],0)`が`($15,a0,d0.w)`として解釈される。また、リストファイルの出力が化ける。  
  ```
      3 00000000 30300015           move ([a0],,),d0    ;ソースコードは move ([a0],0),d0
  ```
* `([An],ZXn)`、`([bd,An],ZXn)`がexpression errorになる。また、リストファイルの出力が化ける。  
  ```
  test.s               3:   expression error
      3 00000000                    move ((a0],zd0.w),d0    ;ソースコードは move ([a0],zd0.w),d0
  test.s               4:   expression error
      4 00000000                    move ([10(a0],zd0.w),d0    ;ソースコードは move ([10,a0],zd0.w),d0
  ```


## SCD.X
* (おそらくv3系すべて?) gcc -gで生成した実行ファイルのソースコードデバッグでステップ実行するとアドレスエラーが発生することがある。
  -finline-functionsを指定する(または環境変数`GCC_OPTION1=I`)と発生しない。SCD.X側の問題かどうかは不明。

## サンプルコード
* ライブラリディスクの\ASK30\FILES.Cの93行目の条件式が`ftotal <= MAXFILES`となっているため、ファイルが多いとバッファオーバーフローが起きる。
  ```c
  		} while (nfiles() == 0 && ftotal <= MAXFILES);
  ```
  * 無償公開版以外で、出荷ロットによっては`ftotal < MAXFILES`に直っているかも。

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

## CLIB __MAIN.O (__MAIN.S)
* 環境変数領域が確保されていない場合、起動時にアドレスエラーが発生する(MPU 68020以降ではバスエラー)。
  * CONFIG.SYSでENVSET=を記述せず、PROGRAM=でプログラムを起動した場合など。


# 無償公開版に特有と思われる問題

## ライブラリディスク (XC2103.LZH, XC2103I.LZH)
* \ASK30ディレクトリ内のファイルについて。
  * MAKEFILEの内容がACI.Hと同一。
  * FILES_TOUROKU.Sのファイル名がFILES_TO.Sになっている。
  * KANJI_TOUROKU.Sのファイル名がKANJI_TO.Sになっている。


# マニュアルの不具合

## CライブラリマニュアルVOL2
* P.370 SP_REGST
  * (参考情報) ver2.0では、にMODEという引数があるが間違い。垂直帰線期間検出は`SPRITENO`の最上位ビットで設定する。
    NEW KITでは訂正されている。

## プログラマーズマニュアル
* P.536 FPコール番号: 2
  * 実際には、その時点で変換ありのモードであれば現在の変換モードを返し、変換なしであればキー操作で変換ありのモードに
    したときに選択されるモードを返す。0が返されることはない。詳しくはぷにぐらま～ずまにゅある参照。

## 拡張マニュアル
* P.58 acc_mes
  * 見出し以外の内容がP.57 acc_funcと同一になっている(情報源: AKIGO002.LZH)。
* P.67 FPコール番号: 62
  * 引数をスタックに積む順番が間違っている。正しくは以下の通り(情報源: AKIGO002.LZH)。
    ```
    move.l #KIND,-(sp)
    pea MBUF
    pea STR
    ```
* P.67 FPコール番号: 63
  * 引数をスタックに積む順番が間違っている。正しくは以下の通り(情報源: AKIGO002.LZH)。
    ```
    move.l #KIND,-(sp)
    move.l #LEN,-(sp)
    pea MBUF
    ```
* P.111 _B_SCROLL
  * 機能のMODE=16、MODE=17はMODE=17、MODE=18が正しい。
* P.221 B_CONMOD
  * 解説のD1.L = 1～4はD1.L = 0～3が正しい。

## インストラクションコードマニュアル
* P.140 BTST\{.B/.L\} Dn,&lt;ea&gt;
  * `#<data>`が30となっているが○が正しい(MPU 68000でも使える)。


----
goto [index](../../README.md) / [プログラミング](../README.md) / [XC](README.md)
