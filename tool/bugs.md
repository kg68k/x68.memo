# 不具合

* 市販ゲーム、同人ゲーム、フリーゲームは[ゲーム](../game.md)へ。

## 開発ツール

### PD LIBC
* [LIBC TODO](../prog/libc/README.md#todo)

### C Compiler PRO-68K ver2.1 NEW KIT
* [C Compiler PRO-68K ver2.1 NEW KITの不具合](../prog/xc/bugs.md)

### GNU Make version 3.79 human68k-1.4
* 仮想ディレクトリまわりの処理がまだ完全には解決していないはず。

### HAS060.X version 3.09+91
* [HAS060.X 既知の不具合](http://retropc.net/x68000/software/develop/as/has060/knownbug.htm)
* [HAS060X.X KNOWNBUGS.md](https://github.com/kg68k/has060xx/blob/main/KNOWNBUGS.md)

### Pure PASCAL Compiler v1.01
* DEKOのアヤシいお部屋。 &gt; ぴゅあぱすかる。 &gt;
  [Pure PASCAL 既知の問題 (ver 1.01)](https://ht-deko.com/pure.html#%E6%97%A2%E7%9F%A5%E3%81%AE%E5%95%8F%E9%A1%8C-ver-101)

### こ-BASIC ver.0.01 (H8/11/11 版)
* kofunc.docの下記関数名は`DrawMonoCard`が正しい。
  ([@ShirohSuzuki/1672859593654022146](https://x.com/ShirohSuzuki/status/1672859593654022146))
  ```
  DrawCardMono( wno;int, x;int, y;int, num;int, card;int )
  ```

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
* crt0.Sでメモリブロックのサイズを確認していない。
  * [elf2x68kでは修正済み](https://github.com/yunkya2/elf2x68k/issues/7)。該当コードは同じなので詳細はそちらを参照。
* [crt1.c](https://github.com/Lydux/newlib-1.19.0-human68k/blob/master/newlib/libc/sys/human68k/crt1.c)
  で環境変数領域が確保されていない場合にアドレスエラーが発生する(MPU 68020以降ではバスエラー)。
  * [elf2x68k](https://github.com/yunkya2/elf2x68k/issues/8)でも該当。

### PCM to SMP Version 1.0
* (参考情報) ヘッダ構造: PCMデータ数 1バイト、{ID 1バイト、データサイズ 2バイト}×データ数、PCMデータ×データ数
* PCMファイルのサイズが131072バイトを超えるとバスエラー等が発生する(読み込みバッファが固定サイズでファイルサイズをチェックしていないため)。
* PCMファイルのサイズの下位16ビットしかヘッダに書き込まれない。
  このためPCMファイルがサイズが65536(0x10000)バイト以上の場合に問題が発生する。
  * 未確認だがSFXVIでのゲーム中、途中までしか再生されない、別IDのPCMが途中から再生される、などの問題があるかもしれない。
  * SMP2PCM.Xで正しくないファイルサイズで書き出される。

### nm.x version 1.02.1
* バージョン表示のロングオプション形式`--version`が`-version`になっている。

### TCPPACKB - TCP/IPドライバ無償配布パッケージ(B PACK) 1996/07/03
* `gethostbyname()`、`getaddrinfo()`にIPv4アドレス形式の文字列を渡したときに、
  IPv4アドレスとして解釈されずDNSサーバに問い合わせを行ってしまう。
  ([@yunkya2/1991158863392133619](https://x.com/yunkya2/status/1991158863392133619))

### gcc2.x: gcc version 2.6.3 (68k, Human68k, revision 5)
* 長い文字列(4KB弱)を記述すると文字化けする。
  [Cソースコード](https://github.com/kg68k/x68.memo/blob/main/prog/gcc2/gcc2_longstr.c)
  [コンパイル結果](https://github.com/kg68k/x68.memo/blob/main/prog/gcc2/gcc2_longstr.s)
  (どちらも文字コードはShift_JIS)


## 情報表示

### cpupower.r Ver0.1
* 実行時にMFP TCDR($e88023; Timer-Cデータレジスタ)の値を本来の値200から256相当に書き換えるが、
  終了時に戻さないためTimer-C割り込みの間隔が1.28倍に変わってしまう。
  ([@kg68k/1492793567512711170](https://x.com/kg68k/status/1492793567512711170))
  * カーソル点滅速度やSystem Informationのprocessor performance値に影響する。
* システムスタックが$00010000以上だと、CPU速度比率に非常に小さい値が表示される。
  ([@kg68k/1931729625731985481](https://x.com/kg68k/status/1931729625731985481))
* 高速・低速環境で計測値がおかしくなる。本来の実機の速度では起きないので不具合ではなく制限と考える。
  ([@kg68k/1931743334516838566](https://x.com/kg68k/status/1931743334516838566))

### Winner2.X v1.33R4
* 最新バージョンはv1.33R4だが実行時の表示はVer 1.30R4となっている(integerの綴りが直っているのがv1.33R4)。
* float performanceは実質的に「integer performance」の別バージョン。
  ([@kamadox/1684887533090660352](https://x.com/kamadox/status/1684887533090660352))
* 日曜日に実行すると時計の曜日が「？」になる。
  ([@kamadox/1684880439541215232](https://x.com/kamadox/status/1684880439541215232))


<!-- ## デバイスドライバ -->


## ディスク

### RAM DISK DRIVER 「GRAD.r」 Version 1.30
* `DOS _MALLOC2`でメモリを確保しているプロセスがあるときにGRAD.rを`-g -b`オプションで登録しようとするとエラー終了するが、
その際にグラフィック画面の使用モード(`IOCS _TGUSEMD`)が「1:システムが使用中」に変更されてしまう。
  * [GRADX](https://github.com/kg68k/gradx)で修正されている。

### SUSIE V1.21A
* SCSI IOCS未登録時に実行すると白帯エラー($01F5)が発生する。なおV1.14Aでは問題なく、V1.15Aはエラーになる。
  * トラブルシューティングの手順(OPT.1によるFD起動、`SCSIDEV=OFF`)で発生する。
  * [SUSIEX](https://github.com/kg68k/susiex)で修正されている。

### 9SCDRV.X Version 3.14+2
* L002568 にある divu.w L00072A(pc),d2 を実行するとき d2 の上位ワードが不定。
  ([XEiJ (X68000 Emulator in Java)](https://stdkmd.net/xeijtest/#changes_0251031))
  * IBMフォーマット(1.44MB)のアクセスに失敗する。
    ([@kunichiko/1978806645003268385](https://x.com/kunichiko/status/1978806645003268385))
  * /Dスイッチを指定すれば回避できる。
    ([@kamadox/1979132819411734627](https://x.com/kamadox/status/1979132819411734627))
  * [XEiJ](https://stdkmd.net/xeij/) 0.25.11.08以降に同梱の060turbo.sys 0.61に対策コードが追加されている。


## 音源ドライバ

### mxw.x version 2.06+16 Rel.13a
* 音楽再生中にmxp -pやmmdspでF6キーを押すなどして再演奏するとおかしな命令の白帯になることがある。

### X68k RCD: RC play driver v3.01q
* `DOS _KEEPPR`に渡す常駐バイト数にデータセクションの大きさが含まれておらず、またスタック範囲外の値を加算している。
  他の部分のコードの影響により結果として問題が顕在化しないことが多いと思われるが、場合(値)によっては異常動作を引き起こす。

### Z-MUSIC Version 2.08
* [Z-MUSIC Version 2.08 KNOWNBUGS.md](https://github.com/kg68k/zmusic2/blob/main/KNOWNBUGS.md)

### Z-MUSIC Version 3.02C
* [Z-MUSIC Version 3.02C KNOWNBUGS.md](https://github.com/kg68k/zmusic3/blob/main/KNOWNBUGS.md)

### OPMDRV3.X version 1.11
* ファンクションコールの不具合は[ぷにぐらま～ずまにゅある](https://github.com/kg68k/puni)のopmdrv.txtに記載あり。
* カレントディレクトリにMIDIBEというファイルが存在すると、OPMDRV3.Xが登録済みと誤認されて常駐できない。
* カレントディレクトリにOPMというファイルが存在すると、他の音源ドライバが登録済みと誤認されて常駐できない。
* カレントディレクトリにPCMというファイルが存在すると、PCMDRV.SYSが登録済みと誤認されて常駐できない。


## PCMドライバ

### MPCM version 0.45A
* ファンクション`$10xx M_EFCT_OUT`
  * 再生中(DMA使用中)であっても常にDMAの転送開始設定を行ってしまい、音が乱れることがある。
    * ほかのファンクションと違い、ここだけ`func_00xx_DMA_start`を呼ぶ前に`play_flag`を見ていないため。
  * 成功時に`d0.l`に戻り値が代入されないため、エラーを正しく検出することができない。
    * チャンネル番号0～7または`$ff`を指定した場合、`d0.l`には負数を含む不定値が返る。
    * チャンネル番号`$e0`を指定した場合、`d0.l`の上位ワードには負数を含む不定値が返る
      (一応、下位ワードには割り当てたチャンネル番号が返る)。
  * チャンネル番号`$e0`を指定した場合、IOCS用のチャンネルで再生されることがある(`d0.l`の下位ワードには8が返る)。
* ファンクション`$8006 M_SET_ECHCNT`
  * 起動時の初期状態および`d1.l = 0`を指定すると、効果音発声数が不正な値に設定される
    (チャンネル0-7とIOCS用チャンネルの合計9チャンネルで発声される挙動)。

### PCM8 v0.48b
* Z-MUSIC v2のファンクション`$13 se_adpcm1`または`$14 se_adpcm2`でADPCMデータが再生されない、再生周波数がおかしい、
  パンポットがおかしいなどの不具合が生じることがある。
  * Z-MUSICがショートカットで`IOCS _ADPCMOUT`を呼び出す(zmsc_int.s PCM8KON)。このときd0.lの内容は不定。
    PCM8がDMA再起動する(func2.inc rst_dma_s)。周波数(play_freq)とパンポット(play_pan)から設定値テーブル(ppi_c_table)を引くが、
    d0レジスタをクリアせずに使用しているため、d0.wの上位バイトが0でなかった場合に不正なメモリアドレスを参照する。
    周波数やパンポットの設定値が正しくないため、正しく再生されない。
  * PCM8 v0.48b+2や、PCM8A、MPCM + P8EMUなどの互換ドライバでは問題ない。

### XAPNEL.R version 1.04
* [XAPNEL.R 既知の不具合](https://github.com/kg68k/xapnel-src?tab=readme-ov-file#%E6%97%A2%E7%9F%A5%E3%81%AE%E4%B8%8D%E5%85%B7%E5%90%88)


## 画面制御

### 768.x v1.23
* `IOCS _CRTMOD`を`d1.w = $ffff`(現在の画面モードの取得)で呼び出すと、常に`d0.l = $10`が返される。

### CRT_Hi.x Ver 1.00
* `IOCS _CRTMOD`を呼び出した際に低解像度から高解像度への変更が正しく行われない(例:モード3を指定するとモード2に変更される)。
* 画面モード18以上に対応していない(例:モード18を指定するとモード17に変更される)。


## その他ツール

### patexec.sys version 0.3
* パッチデータの数が16(`NTABLES`)を超えるとバッファオーバーフローしてメモリを破壊する。
  その結果バスエラーやハングアップなど重大なエラーが発生する。
  * 運良く破滅的な状況にならなくても、パッチデータの数が257(`16 * NTABLES + 1`)を超えると
    おそらく無限ループで停止する。

### FA: Filecopy Advanced V1.07A 
* FA.TXT
  * 7.11の見出しと冒頭がCASEではなくBCMPになっている。
  * 7.11の表の2つ目の「-u」(ファイル名を小文字化)は「-l」が正しい。

### MAGIC4.X version 2.08
* CONFIG.SYSのdevice=で組み込み後に再度組み込もうとすると使用法が表示されるが、CONFIG.SYSの残りが実行されない(`d7`レジスタを破壊している)。
  * OSワーク$1c1c(1.l)の値(最後のデバイスヘッダ)もおかしくなる(`a2`レジスタを破壊している。
    このワークはコマンドラインからデバイスドライバとして組み込めるツールでは更新されないことがあるので、実害はないかも)。
  * CONFIG.SYSがオープンされたままになる。

### MAGIC4patched.X version 2.08
* (備考) SION II 030 for X680x0 に同梱されている改造版。
  * コマンドがF系列の`$FDxx`からA系列の`$ADxx`に変更されている。
  * デバッガでファンクションコール呼び出しをトレースするとリターン時に止まらない。
* オリジナルの不具合も参照。
* 常駐解除しようとすると「ベクタが変更されています。」と表示され、解除できない。
  * 修正パッチ: `00000197: 2C 28`

### zx.r version 1.21 patchlevel 2
* パスデリミタに`\`が使用されている不正なアーカイブがエラーとして扱われず、そのまま書き出そうとする。
  * 同名ディレクトリがすでに存在すれば書き出せる。
  * 何らかの脆弱性があるかもしれない。
  * 参考: [軽減策: ZipArchiveEntry.FullName パスの区切り文字 - .NET Framework | Microsoft Learn](https://learn.microsoft.com/ja-jp/dotnet/framework/migration-guide/mitigation-ziparchiveentry-fullname-path-separator)

### MSX Simulator MS.X v0.8.2-release
* X68000機で起動すると「エラー($01AC)が発生しました」の白帯が表示される。
  * MPU判別をするのに`IOCS _SYS_STAT`を使用しているため。


----
# 2000年問題

この節では修正パッチや改造版があるソフトウェアも掲載しています。  
(カテゴリがあるものは各カテゴリ内に記載しているます)

### Binary file updater v1.2 rel.2
* bup -l/-lmでファイルの日付の表示が乱れる。パッチあり。

### Ease Filer (95/04/07 版)
* ファイルの日付の表示が乱れる。パッチあり。

### EDR-plus version 2.0.1(yakko-chan)
* セレクタ画面のファイルの日付の表示が乱れる。[パッチあり edrp201.pat](patch/edrp201.pat)。

### lhv version 0.95.2
* セレクタ画面のファイルの日付の表示が乱れる。パッチあり。

### WS v0.90
* 現在の日付の表示が乱れる。パッチあり。

### DI (DImain Ver0.93、DImain Ver0.93.4c)
* 現在日時やファイルの日付の表示が乱れる。
* DI V0.51+14Aは問題なし。


----
# SHARP純正ソフトウェア
(カテゴリがあるものは各カテゴリ内に記載しています)

* STUDIO KAMADA &gt; [X680x0 のメーカー純正ソフトウェアの不具合について](https://stdkmd.net/bugsx68k/)
* [C Compiler PRO-68K ver2.1 NEW KIT](#c-compiler-pro-68k-ver21-new-kit)

## ドライバ

### FASTIO.X
* バッファ容量指定で大きい数値を指定した場合に「バッファーサイズが正しくありません」のエラーにならず、小さい容量として扱われることがある。
  ([@kg68k/1887513728209563689](https://x.com/kg68k/status/1887513728209563689))

### FASTOPEN.X
* ヘルプメッセージの誤字「常時使用可能な**な**オプション」。

## SX-Window

### 時計.X (SX-Window version 3.10)
* 西暦2000年以降で表示が乱れる。パッチあり。

## その他ツール

### SWITCH.X Version 2.20
* switch2.x: 最優先ブートデバイスが`$b000`でSRAM起動アドレスが未知の値の場合、`BOOT ROM5 $EEC000`と表示される(詳細は未調査)。


----
# 他機種用ソフトウェア

### DiskExplorer Version 1.69 (editdisk.exe)
* ファイルサイズがクラスタサイズの倍数でFATの確保数が余計に1だけ多いファイル(例:2HDイメージ内の1024バイトのファイル)
  を取り出すと、ファイルサイズがクラスタサイズだけ大きくなる。


----
goto [index](../README.md) / [ツール](./README.md)
