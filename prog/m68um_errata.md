そのうち体裁を整えてまとめたいと考えていますが、いつになるかわからないのでとりあえず情報を列挙しておきます。

# M68000PRM.pdf
MOTOROLA M68000 FALMILY Programmer's Reference Manual REV.1

* M68000PRMER.pdf - 68K Programmer’s Reference Manual Errata Rev.1
* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ：M68000PRM.pdf 正誤表

* p.1-16 https://x.com/kg68k/status/1364229639598612487
  >EXP 0が二つあることが知られてる図だけど(正しくは左がEXP 2)、ビット番号の96、65、32も間違ってる。

* p.1-22 Table 1-5 NANs欄のBiased Exponent Format Maximum https://x.com/kg68k/status/1955316865422811353
  >誤 255 ($7FF)  
  >正 2047 ($7FF)

* p.1-27 (PDF p.38) https://x.com/kamadox/status/1055037518666584067
  >M68000 Family Programmer's Reference Manual の 1.7.1 に書かれている supervisor function code (SFC) and data function code (DFC) は
  > source ～ と destination ～ の間違い。その後の bits 0P2 は bits 0-2。
  > https://www.nxp.com/files-static/archives/doc/ref_manual/M68000PRM.pdf

* p.2-12 Memory Indirect Preindexed Mode https://x.com/kg68k/status/2103166974268493968
  >GENERATIONがポストインデックスと同じになっています。正しくは  
  >EA = (bd + An + Xn.SIZE*SCALE) + od

* p.2-17 Program Counter Memory Indirect Preindexed Mode https://x.com/kg68k/status/2103167702844281170
  >PCメモリ間接も同様。  
  >EA = (bd + PC + Xn.SIZE*SCALE) + od

* p2-20 Table 2-4. https://x.com/kg68k/status/2100221103734215075
  >Long (xxx).L 111 001  
  >が正しい(末尾の0→1)。

* p.2-20 Table 2-4. https://x.com/kg68k/status/2101623126358667368
  > この表だと絶対ロングと絶対ショートのモードに可変が含まれていませんが、可変あり

* p.2-27 Figure 2-7. Memory Indirect with Postindex https://x.com/kg68k/status/2103169476762251366
  >右上一つ目の od.OD SIZE は Xn.SIZE*SCALE が正しい。
  >(あるいは内部処理によっては二つ目と言うべきかもしれない)

* [XEiJ &gt; MC68060.java](https://stdkmd.net/xeij/source/MC68060.htm)
  * ノンブル4-93(PDF p.197) DIVS.W、アドレッシングモード「data alterable」(データ可変)は「data」(データ)が正しい。
  * ノンブル4-93(PDF p.198) DIVS.LとDIVSL.L、アドレッシングモード「data alterable」(データ可変)は「data」(データ)が正しい。
  * ノンブル4-97(PDF p.201) DIVU.W、NOTEのオーバーフロー条件「16-bit signed integer」は「16-bit unsigned integer」が正しい。
  * ノンブル5-105(PDF p.407) FREM、INEX2の「Cleared」は「Refer to inexact result in the appropriate user’s manual.」
    (結果に誤差があるときセット、それ以外はクリア)が正しい。

* p.4-114 (LSL, LSR) https://x.com/kg68k/status/2082893933512929658
  >「10 ― Long operation i/r field」とあるが、「i/r field」は改行して小見出しになっているのが正しい。  
  >紙版は問題ない。

* p.5-84 https://x.com/kg68k/status/1364232300452483072
  >×1n ○ln、×100 ○10⁰ が知られている図。$32から10のn乗が続いてる。
  >手元にある紙の本だと$32は10⁰になってるので、PDF化の時に100に化けた？

* p.6-26 https://x.com/kg68k/status/1954852631735615696
  >最後の段落に2か所ある OinstructionO は、紙の書籍(M68000PM/AD REV.1、MOTOROLA、1992年)を確認したところ “instruction” でした。

* p.B-4 (PDF p.631) https://x.com/kg68k/status/1787837754682003505
  >Format $3の+$06の値がFormat $2と同じ0010になっているが、0011が正しい。

* https://x.com/kg68k/status/1507365691921661960
  >M68040 User's ManualやM68060 User's Manualにあるmove16命令の注釈、PROGRAMMER'S REFERENCE MANUAL (M68000PM/AD REV.1)には見当たらない。
  >>&#x37;. MOVE16 (ax)+,(ay)+ is functionally the same as MOVE16 (ax),(ay)+ when ax = ay. The address register is
  >>only incremented once, and the line is copied over itself rather than to the next line.

* https://zenn.dev/link/comments/3374282d808748
  >BFEXTUとBFFFO、公式リファレンスだと定数ビットが丸かぶりしてるんだけど、もしかしたらリファレンスがミスってるかも。


# MC68030UM.pdf
MC68030 ENHANCED 32-BIT MICROPROCESSOR USER'S MANUAL Therd Edition

* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ2：MC68030UM.pdf 正誤表


# MC68030 ユーザーズ・マニュアル 第1版

* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ3:「MC68030ユーザーズ・マニュアル」(日本語版) 正誤表

* https://x.com/isaki68k/status/1561694664305979393
  >MC68030ユーザーズマニュアル(日本語) p.457 表9-3、透過(T)の行、レベル0欄の説明の後半の一文。  
  >×「Iビットがセットされている場合は未定義。」  
  >○「Tビットがセットされている場合は他のすべてのビットは未定義」  
  >久しぶりに逆ですやんていうレベルの誤植に遭遇した。(1日悩んだ

  * https://x.com/tsutsuii/status/1646160392819728388
    >日本語版 MC68030 UM の第9章 メモリ管理ユニット で 表9-3 MMUSRの各ビットの定義 の PTEST, レベル0 の時の「透過(T)」には「Iビットがセットされているときは未定義」と書かれているのに 図9-39 PTEST Level 0による MMUステータスの取得 では Iビットより先にTビットをチェックしている矛盾がある


# MC68040 ユーザーズ・マニュアル 第1版

* P.222 表9-2 左下 誤「実効後」正「実行後」。


----
goto [index](../README.md) / [プログラミング](./README.md)
