そのうち体裁を整えてまとめたいと考えていますが、いつになるかわからないのでとりあえず情報を列挙しておきます。

# M68000PRM.pdf
MOTOROLA M68000 FALMILY Programmer's Reference Manual REV.1

* M68000PRMER.pdf - 68K Programmer’s Reference Manual Errata Rev.1
* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ：M68000PRM.pdf 正誤表

* https://twitter.com/kamadox/status/1055037518666584067
  >M68000 Family Programmer's Reference Manual の 1.7.1 に書かれている supervisor function code (SFC) and data function code (DFC) は source ～ と destination ～ の間違い。その後の bits 0P2 は bits 0-2。 https://www.nxp.com/files-static/archives/doc/ref_manual/M68000PRM.pdf

  PDFのページ数でいうと38、ノンブルは1-27

* https://twitter.com/kg68k/status/1364229639598612487
  >『M68000 FAMILY PROGRAMMER'S REFERENCE MANUAL』P.1-16。EXP 0が二つあることが知られてる図だけど(正しくは左がEXP 2)、ビット番号の96、65、32も間違ってる。

* https://twitter.com/kg68k/status/1364232300452483072
  >『M68000 FAMILY PROGRAMMER'S REFERENCE MANUAL』P.5-84。×1n ○ln、×100 ○10⁰ が知られている図。$32から10のn乗が続いてる。手元にある紙の本だと$32は10⁰になってるので、PDF化の時に100に化けた？

* https://twitter.com/kg68k/status/1507365691921661960
  >M68040 User's ManualやM68060 User's Manualにあるmove16命令の注釈、PROGRAMMER'S REFERENCE MANUAL (M68000PM/AD REV.1)には見当たらない。

* https://zenn.dev/link/comments/3374282d808748
  >BFEXTUとBFFFO、公式リファレンスだと定数ビットが丸かぶりしてるんだけど、もしかしたらリファレンスがミスってるかも。


# MC68030UM.pdf
MC68030 ENHANCED 32-BIT MICROPROCESSOR USER'S MANUAL Therd Edition

* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ2：MC68030UM.pdf 正誤表

# MC68030 ユーザーズ・マニュアル 第1版

* https://twitter.com/isaki68k/status/1561694664305979393
  >MC68030ユーザーズマニュアル(日本語) p.457 表9-3、透過(T)の行、レベル0欄の説明の後半の一文。
×「Iビットがセットされている場合は未定義。」
○「Tビットがセットされている場合は他のすべてのビットは未定義」
久しぶりに逆ですやんていうレベルの誤植に遭遇した。(1日悩んだ

  * https://twitter.com/tsutsuii/status/1646160392819728388
    >日本語版 MC68030 UM の第9章 メモリ管理ユニット で 表9-3 MMUSRの各ビットの定義 の PTEST, レベル0 の時の「透過(T)」には「Iビットがセットされているときは未定義」と書かれているのに 図9-39 PTEST Level 0による MMUステータスの取得 では Iビットより先にTビットをチェックしている矛盾がある





----
goto [index](../README.md) / [プログラミング](./README.md)
