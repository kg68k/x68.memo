そのうち体裁を整えてまとめたいと考えていますが、いつになるかわからないのでとりあえず情報を列挙しておきます。

M68000PRM.pdfについては確認しやすいように以下の内容も引用してあります。詳しくはそれぞれの資料を参照してください。
* M68000PRMER.pdf (68K Programmer’s Reference Manual Errata Rev. 1, 03/2007)
* [X68000 関係資料正誤表のコーナー](http://www.pastel-flower.jp/~isaki/inside-bug2.php) &gt; おまけ：M68000PRM.pdf 正誤表

# M68000PRM.pdf
MOTOROLA M68000 FALMILY Programmer's Reference Manual REV.1

* p.1-16 https://x.com/kg68k/status/1364229639598612487
  >EXP 0が二つあることが知られてる図だけど(正しくは左がEXP 2)、ビット番号の96、65、32も間違ってる。
  * 一つ目の`EXP 0`は`EXP 2`が正しい。

* p.1-22 Table 1-5 NANs欄のBiased Exponent Format Maximum https://x.com/kg68k/status/1955316865422811353
  >誤 255 ($7FF)  
  >正 2047 ($7FF)

* p.1-22 Table 1-5. Double-Precision Real Format Summary 情報源:井崎さんの正誤表
  >下から3行目、Maximum Positive Normalized は Maximum Positive Normalized は 18×10<sup>308</sup> ではなく 1.8×10<sup>308</sup>。 

* p.1-24 情報源:井崎さんの正誤表
  >Table 1-6. Extended-Precision Real Format Summary の下から2行目、
  >Minimum Positive Denormalized は 3.7×10<sup>4951</sup> ではなく 1.8×10<sup>-4951</sup>。 
  * 未確認。表の下2行は要検証。

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

* p2-20 Table 2-4 https://x.com/kg68k/status/2100221103734215075
  >Long (xxx).L 111 001  
  >が正しい(末尾の0→1)。

* p.2-20 Table 2-4. https://x.com/kg68k/status/2101623126358667368
  >この表だと絶対ロングと絶対ショートのモードに可変が含まれていませんが、可変あり

* p.2-27 Figure 2-7. Memory Indirect with Postindex https://x.com/kg68k/status/2103169476762251366
  >右上一つ目の od.OD SIZE は Xn.SIZE*SCALE が正しい。
  >(あるいは内部処理によっては二つ目と言うべきかもしれない)

* p.3-31 情報源:井崎さんの正誤表
  >表 3-23 の IEEE Aware Tests のうち以下の3つの式が違うようです。
  >また IEEE Nonaware Tests、Miscellaneous Tests の欄にもオーバーライン抜けがあるような気がしますが調べてません。

* p.4-43 https://zenn.dev/link/comments/3374282d808748
  >BFEXTUとBFFFO、公式リファレンスだと定数ビットが丸かぶりしてるんだけど、もしかしたらリファレンスがミスってるかも。
  * `BFFFO`は`%1110_1101_11mm_mrrr ($edc0)`が正しい。

* [XEiJ &gt; MC68060.java](https://stdkmd.net/xeij/source/MC68060.htm)
  * ノンブル4-93(PDF p.197) DIVS.W、アドレッシングモード「data alterable」(データ可変)は「data」(データ)が正しい。
  * ノンブル4-93(PDF p.198) DIVS.LとDIVSL.L、アドレッシングモード「data alterable」(データ可変)は「data」(データ)が正しい。
  * ノンブル4-97(PDF p.201) DIVU.W、NOTEのオーバーフロー条件「16-bit signed integer」は「16-bit unsigned integer」が正しい。
  * ノンブル5-105(PDF p.407) FREM、INEX2の「Cleared」は「Refer to inexact result in the appropriate user’s manual.」
    (結果に誤差があるときセット、それ以外はクリア)が正しい。

* p.4-114 (LSL, LSR) https://x.com/kg68k/status/2082893933512929658
  >「10 ― Long operation i/r field」とあるが、「i/r field」は改行して小見出しになっているのが正しい。  
  >紙版は問題ない。

* p.4-126 https://x.com/kg68k/status/1507365691921661960
  >M68040 User's ManualやM68060 User's Manualにあるmove16命令の注釈、PROGRAMMER'S REFERENCE MANUAL (M68000PM/AD REV.1)には見当たらない。
  >>&#x37;. MOVE16 (ax)+,(ay)+ is functionally the same as MOVE16 (ax),(ay)+ when ax = ay. The address register is
  >>only incremented once, and the line is copied over itself rather than to the next line.

* p.5-20 情報源:井崎さんの正誤表
  >FATANH 命令の Description: の中、  
  >誤：and the result is equal to -infinity or +infinity if the source is equal to +1 or -1,  
  >正：and the result is equal to -infinity or +infinity if the source is equal to -1 or +1,  
  >のような気がします。

* p.5-35 情報源:M68000PRMER.pdf
  >In the Instruction Fields section of the FDBcc instruction summary, the displacement field
  >description should be: “Specifies the branch distance (from the address of the instruction plus
  >four) to the destination in bytes.”
  * 井崎さんの正誤表に補足あり。

* p.5-67 情報源:井崎さんの正誤表
  >FLOGNP1 の Operation Table の NOTES: 2 の2行目  
  >誤?：exception byte and returns a NAN. …  
  >とありますが、返すのは NAN ではなく -infinity だと思います。 

* p.5-71 情報源:M68000PRMER.pdf
  >In the Instruction Format figure of the FMOD instruction summary, bits 6:0 of the second word
  >should be 0100001 (matching the figure on page 8-33), not 0101101.

* p.5-78 情報源:M68000PRMER.pdf
  >In the Instruction Format figure of the FMOVE instruction summary:
  >• The COPROCESSOR ID field should be located in bits 9-11
  >• Bit 12 has a fixed value of 1

* p.5-84 情報源:井崎さんの正誤表
  >定数表の写植か OCR のミスのようです。  
  >誤：	$30     1n(2)  
  >$31     1n(10)  
  >$32     100  
  >正：	$30     ln(2)  
  >$31     ln(10)  
  >$32     10<sup>0</sup>  
  >要するに $30 は loge(2)、 $31 は loge(10)、 $32 は 1 ということです。 
  * p.5-84 https://x.com/kg68k/status/1364232300452483072
    >×1n ○ln、×100 ○10⁰ が知られている図。$32から10のn乗が続いてる。
    >手元にある紙の本だと$32は10⁰になってるので、PDF化の時に100に化けた？

* p.6-6 情報源:井崎さんの正誤表
  >cpRESTORE 命令の EA の表 (右側)、cpRESTORE に即値は指定出来ません。 

* p.6-12 情報源:M68000PRMER.pdf
  >In the FRESTORE instruction summary, the description for the BUSY state frame should begin
  >with “This state frame is 100 ($64) bytes long in the MC68040...”
  * 情報源:井崎さんの正誤表
    >FRESTORE 命令のフレーム長の説明で、 BUSY のほうは M68000PRMER.pdf で既出ですが、そのすぐ上の UNIMP のほうも誤っています。  
    >誤：	UNIMP: This state frame is generated only by the MC68040. It is 48 ($30) bytes long. …  
    >正：	UNIMP: This state frame is generated only by the MC68040. It is 52 ($34) bytes long. …  
    >誤：	BUSY: This state frame is 96($60) bytes long in the MC68040, …  
    >正：	BUSY: This state frame is 100($64) bytes long in the MC68040, … 

* p.6-26 情報源:井崎さんの正誤表
  >MOVES 命令の NOTE の最後の段落の2行目以降、データ空間を命令空間に読み替えると読めますが逆のような気がします。
  >またこの段落に2箇所ある OinstructionO は物理本では “instruction” (Left Double Quotation Mark と Right Double Quotation Mark) だそうです。  
  >誤?：	data space, the MC68040's integer unit into data references  
  >(SFC/DFC = 5 or 1) translates MOVES accesses to the  
  >OinstructionO address spaces (SFC/DFC = 6 or 2).  
  >一方、MC68040UM.pdf の p.3-22 の本文2行目以降にはこう書いてあり、命令空間をデータ空間に読み替えると読めます。こちらのほうが正しそうです。  
  >正?：	… Because the M68040 implements a merged  
  >instruction and data space, the integer unit translates MOVES accesses to instruction  
  >address spaces (SFC/DFC = $6 or $2) into data references (SFC/DFC = $5 or $1). 
  * p.6-26 https://x.com/kg68k/status/1954852631735615696
    >最後の段落に2か所ある OinstructionO は、紙の書籍(M68000PM/AD REV.1、MOTOROLA、1992年)を確認したところ “instruction” でした。

* p.A-4 情報源:井崎さんの正誤表
  >Table A-1 中ほどの FSGLDIV、FSGLMUL の 68040 の欄が「<sup>2,3</sup>」 (ソフトウェアサポートの意) になっていますが、
  >「X<sup>2</sup>」(ハードウェアサポート)では? (要確認) 

* p.B-4 (PDF p.631) https://x.com/kg68k/status/1787837754682003505
  >Format $3の+$06の値がFormat $2と同じ0010になっているが、0011が正しい。


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
