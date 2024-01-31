# 不具合

## 開発ツール

### PD LIBC
* [TODO](../prog/libc.md#todo)

### GNU Make version 3.79 human68k-1.4
* 仮想ディレクトリまわりの処理がまだ完全には解決していないはず。

### C Compiler PRO-68K ver2.1 NewKit
* STUDIO KAMADA &gt; X680x0 のメーカー純正ソフトウェアの不具合について &gt; [4. XC ライブラリの不具合](https://stdkmd.net/bugsx68k/#xclib)
* INCLUDE\\TIME.Hで`CLOCKS_PER_SEC`が定義されていない。
([@towser_meow/1638474969494724609](https://twitter.com/towser_meow/status/1638474969494724609))
  * 代わりにINCLUDE\\STDDEF.Hで`CLOCKS_PAR_SEC`が定義されている。
* ライブラリディスクの\ASK30\FILES.Cの93行目の条件式が`ftotal <= MAXFILES`となっているため、ファイルが多いとバッファオーバーフローが起きる。
  ```c
  		} while (nfiles() == 0 && ftotal <= MAXFILES);
  ```
* [無償公開版](http://retropc.net/x68000/software/sharp/xc21/)に特有と思われる不具合。
  * XC2103.LZH, XC2103I.LZH: \ASK30\MAKEFILEの内容がACI.Hと同一。

### HAS060.X version 3.09+91
* HAS060.X - アセンブラ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY &gt;
  [既知の不具合](http://retropc.net/x68000/software/develop/as/has060/knownbug.htm)
* ベースディスプレースメントにサイズを指定しないと「オフセットが範囲外です」になることがある。
```
.cpu 68020
b:
  lea (a,pc,d0.l),a0
  .ds.b 32758
  lea (b,pc,d0.l),a0
a:
```
あるいは
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

### Pure PASCAL Compiler v1.01
* DEKOのアヤシいお部屋。 &gt; ぴゅあぱすかる。 &gt;
  [既知の問題 (ver 1.01)](https://ht-deko.com/pure.html#%E6%97%A2%E7%9F%A5%E3%81%AE%E5%95%8F%E9%A1%8C-ver-101)

### こ-BASIC ver.0.01 (H8/11/11 版)
* kofunc.docの
  ```
  DrawCardMono( wno;int, x;int, y;int, num;int, card;int )
  ```
  の関数名は`DrawMonoCard`が正しい。
  ([@ShirohSuzuki/1672859593654022146](https://twitter.com/ShirohSuzuki/status/1672859593654022146))

### X-BASIC version 2.02
* `print using "#,";1e308`で「おかしな命令を実行しました」等のエラーが発生する。

### ぺけ-ＢＡＳＩＣ ver.0.02
* [X-BASIC'(X-BASIC for iOS)サポート(日本語): ぺけ-BASICのバグについて（見つけ次第更新）](http://x-basicforios.blogspot.com/2013/04/basic.html)

### Ko-Window 開発基本セット Version 2.24+14
* corlib.a::`DefGraphicPalet()`が動作しない([libcor.aのバグを見つけました](https://spyffe68k.blogspot.com/2023/09/libcora.html))。
  インラインアセンブラの記述に`trap #15`が抜けているため。
  * コンパイル済みのライブラリファイルはないが、
    [Ko-Window ソースセット 2.24+14.2](https://www.vector.co.jp/soft/x68/util/se027930.html)
    のソースコードは修正されている。詳しく調査はしていないが、他にも更新されたファイルがある。

### newlib-1.19.0-human68k 
* [crt0.S](https://github.com/Lydux/newlib-1.19.0-human68k/blob/master/newlib/libc/sys/human68k/crt0.S#L39-L46)
  で間違ったサイズでBSSをクリアしている
  ([Charlie Balogh: "Did I catch a bug in the X6800…" - Mastodon](https://mastodon.social/@chainq/111461500478055714))。
  * そもそもOSがクリアしているのでプログラム側によるクリアは不要。


## 情報表示

### cpupower.r Ver0.1
* 実行時にMFP TCDR($e88023; Timer-Cデータレジスタ)の値を本来の値200から256相当に書き換えるが、
  終了時に戻さないためTimer-C割り込みの間隔が1.28倍に変わってしまう。
  ([@kg68k/1492793567512711170](https://twitter.com/kg68k/status/1492793567512711170))
  * カーソル点滅速度やSystem Informationのprocessor performance値に影響する。

### Winner2.X v1.33R4
* 最新バージョンはv1.33R4だが実行時の表示はVer 1.30R4となっている(integerの綴りが直っているのがv1.33R4)。
* float performanceは実質的に「integer performance」の別バージョン。
  ([@kamadox/1684887533090660352](https://twitter.com/kamadox/status/1684887533090660352))
* 日曜日に実行すると時計の曜日が「？」になる。
  ([@kamadox/1684880439541215232](https://twitter.com/kamadox/status/1684880439541215232))


<!-- ## デバイスドライバ -->


## ディスク

### RAM DISK DRIVER 「GRAD.r」 Version 1.30
* `DOS _MALLOC2`でメモリを確保しているプロセスがあるときにGRAD.rを`-g -b`オプションで登録しようとするとエラー終了するが、
その際にグラフィック画面の使用モード(`IOCS _TGUSEMD`)が「1:システムが使用中」に変更されてしまう。

### SUSIE V1.21A
* SCSI IOCS未登録時に実行すると白帯エラー($01F5)が発生する。なおV1.14Aでは問題なく、V1.15Aはエラーになる。
  * トラブルシューティングの手順(OPT.1によるFD起動、`SCSIDEV=OFF`)で発生する。


## 音源ドライバ

### X68k RCD: RC play driver v3.01q
* `DOS _KEEPPR`に渡す常駐バイト数にデータセクションの大きさが含まれておらず、またスタック範囲外の値を加算している。
  他の部分のコードの影響により結果として問題が顕在化しないことが多いと思われるが、場合(値)によっては異常動作を引き起こす。

### ZMSC3LIB Version 0.01
* ZMCHECKZMSC.HAS `zm_check_zmsc()`: スーパーバイザモードで呼び出すとアドレスエラーが発生する。
  * スーパーバイザになるための`IOCS _B_SUPER`の返り値を見てユーザーモードに戻るための`_B_SUPER`を省略しなければならないが、
    その処理が抜けているため。
* ZMADPCM1.HAS `zm_se_adpcm1()`: スタックに積まれた引数を正しく受け取れず、正しく動作しない。
  * `move.b param2(sp),d1`ではなく`move.b param2+3(sp),d1`のように読み込む必要がある。
* ZMADPCM2.HAS `zm_se_adpcm2()`: スタックに積まれた引数を正しく受け取れず、正しく動作しない。

### Z-MUSIC Ver.3.02C
* ZMSC3.X
  * ファンクション`$13 ZM_SE_ADPCM1`
    * MPCM.X非常駐時、優先度が低くて再生されない場合の戻り値`d0.l`の値が不定(0以外の値にはなる)。
    * MPCM.X常駐時、成功すると`d0.l`に0以外の値が返る。
      * MPCMの不具合の影響を受けているが、それだけではなく、マニュアル記載の仕様ではMPCM`M_EFCT_OUT`は「d0.l≧0 正常終了」であるのに対し、
        ZMSC3.X`ZM_SE_ADPCM1`は「d0.l=0:正常終了」であるので、戻り値の上書きが必要だがこれをしていない。
* ZMC.X
  * 上限下限あり8ビット値の配列で、値の直後の2連続セパレータが単独のセパレータとして解釈されてしまう。
    ([@kg68k/1482025079017926658](https://twitter.com/kg68k/status/1482025079017926658))
  * 上限下限あり16ビット値の配列で、上限値・下限値が正しく適用されないことがある。
  ([@kg68k/1482027532736245763](https://twitter.com/kg68k/status/1482027532736245763))
  * `.FM_TUNE_SETUP`をint16_tではなくint8_tとしてコンパイルしてしまう。
  ([@arith_rose/1481388558246051842](https://twitter.com/arith_rose/status/1481388558246051842))
* ZP3.R
  * ファイル名を大文字ドライブ名指定すると、そのドライブに対し特殊ブロックデバイス用の`DOS _DRVCTRL (MD=$34xx)`
    を発行し、返り値によってはファイルがあってもオープンできない。  
    FOPEN.HAS::check_drvchgで`d0`レジスタ(の上位バイト)を初期化していないため、。
* マニュアル(ZM302_M.LZH)
  * ZM4.MAN: `.FM_TUNE_SETUP`、`.ADPCM_TUNE_SETUP`のt1～t128の値の上限が+32768と書かれている(本文は正しい)。
  * ZM15.MAN: ファンクション`$10xx M_EFCT_OUT`の項目の「ファンクション$8005」は、正しくは「ファンクション$8006」。

### Z-MUSIC v2 (詳細未確認)
* ピッチベンドの際に時折計算を間違えてデータ2バイトの最上位ビットが立ってしまう事がある
  ([A ♪SOUND mind in a SOUND <body> : Z-MUSIC for the Web - Qiita](https://qiita.com/toyoshim/items/38dafc97629a98434267))


## PCMドライバ

### MPCM version 0.45A
* ファンクション`$10xx M_EFCT_OUT`
  * 再生中(DMA使用中)であっても常にDMAの転送開始設定を行ってしまい、音が乱れることがある。
    * ほかのファンクションと違い、ここだけ`func_00xx_DMA_start`を呼ぶ前に`play_flag`を見ていないため。
  * 成功時に`d0.l`に戻り値が代入されないため、エラーを正しく検出することができない。
    * チャンネル番号0～7または`$ff`を指定した場合、`d0.l`には負数を含む不定値が返る。
    * チャンネル番号`$e0`を指定した場合、`d0.l`の上位ワードには負数を含む不定値が返る
      (一応、下位ワードには割り当てたチャンネル番号が返される)。


## 画面制御

### 768.x v1.23
* `IOCS _CRTMOD`を`d1.w = $ffff`(現在の画面モードの取得)で呼び出すと、常に`d0.l = $10`が返される。

### CRT_Hi.x Ver 1.00
* `IOCS _CRTMOD`を呼び出した際に低解像度から高解像度への変更が正しく行われない(例:モード3を指定するとモード2に変更される)。
* 画面モード18以上に対応していない(例:モード18を指定するとモード17に変更される)。


----
# 2000年問題

この節では修正パッチや改造版があるソフトウェアも掲載しています。

### Binary file updater v1.2 rel.2
* bup -l/-lm でファイルの日付の表示が乱れる。パッチあり。

### Ease Filer (95/04/07 版)
* ファイルの日付の表示が乱れる。パッチあり。

### EDR-plus version 2.0.1(yakko-chan)
* セレクタ画面のファイルの日付の表示が乱れる。[パッチあり](patch/edrp201.pat)。

### lhv version 0.95.2
* セレクタ画面のファイルの日付の表示が乱れる。パッチあり。

### WS v0.90
* 現在の日付の表示が乱れる。パッチあり。

## SX-Window

### 時計.X (SX-Window version 3.10)
* 西暦の表示が乱れる。パッチあり。

## 市販ゲーム
* [アクアレス](#アクアレス)


----
# SHARP純正ソフトウェア
* STUDIO KAMADA &gt; [X680x0 のメーカー純正ソフトウェアの不具合について](https://stdkmd.net/bugsx68k/)

### FASTOPEN.X
* ヘルプメッセージの誤字「常時使用可能な**な**オプション」。


----
# 市販ゲーム

### アクアレス
* セーブデータの日付の表示が乱れる。
([@huye_4589/1720698235961155723](https://twitter.com/huye_4589/status/1720698235961155723))

### ボスコニアン
* 4月8日に起動するとデモプレイ開始直後にバスエラーが発生する。
  ([@bml3mk5/1512402885682012163](https://twitter.com/bml3mk5/status/1512402885682012163))
  * 4月8日、4月9日、6月1日でメインメモリ6MB未満の場合？
    ([@bml3mk5/1512694332721344520](https://twitter.com/bml3mk5/status/1512694332721344520))


----
goto [index](../README.md) / [ツール](./README.md)
