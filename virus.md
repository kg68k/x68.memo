# ウイルス

## FORCEウイルス
ファーサイドムーンに感染していたウイルス。
1990年7月になるとディスクの内容を破壊する。

* [我が国におけるコンピュータウィルスの現状と対策](https://ipsj.ixsq.nii.ac.jp/ej/?action=pages_view_main&active_action=repository_view_main_item_detail&item_id=4468&item_no=1&page_id=13&block_id=8)
  * IPAの命名法によるとDBf-1となる。  
* [今朝の朝日新聞に日本占い師連盟理事長山本隆雄と出ています。 - ハッカー伝言板改めえむびーまんの日記帳（山本隆雄ブログ）](https://blog.goo.ne.jp/nichikon1/e/c551134dcc5577b3935906d556c28786)
* https://twitter.com/kitami_kukuku/status/1769902921976852682
* https://twitter.com/AdditiveK50000/status/1647598510840348684

### Oh!X 1990年6月号 p.56
付録ディスクにdoctor.r収録。

`Initial Program Loader` `X68k Force`という文字列があるとのこと。
バージョンは1.00、1.02、1.05が確認されている。

アートディンクの告知によるとウイルス名称は`NX68K IPL V1.02`。

### Oh!X 1991年1月号 p.123
付録にdoctor2.x収録。

感染したIPLは`Human Ver 2.0`の部分が`Human Ver Pro`になっているとのこと。

## SUR-GEONウィルス
「SURGEON買ってね！ウヒョ」

ref. [2009-Semi1-Yuusuke_Miyazaki.pdf](http://www.wata-lab.meijo-u.ac.jp/file/seminar/2009/2009-Semi1-Yuusuke_Miyazaki.pdf)  
『コンピュータ・ウィルスが伝染るのはなんでだろう！？』(武井純考、小学館)を基に作成されたスライド。

## BEEPウイルス(仮)
* [復刻版「ヴァリスト・レスナルト」の不具合に関して｜BEEP](https://www.beep-shop.com/blog/19808/)
* [X68000用ゲーム「ヴァリストレスナルト」SRAMに侵入してFDに感染する謎のIPL - posfie](https://posfie.com/@rentan_org/p/6c6XvOO)
* [X68000用ゲーム「ヴァリストレスナルト」IPLについて販売元からの発表 - posfie](https://posfie.com/@rentan_org/p/FRcVmkk)

## DBh-4
* SRAMとディスクのIPLセクタに感染する。
* 起動時に「エラーが発生しました。リセットしてください。」と表示される。
* https://x.com/tkt_kwsk/status/1984211549918269519
* [volatilityの作法 その19 #Security - Qiita](https://qiita.com/ohisama@github/items/aaca71cf982b2b68f4a7)


# ツール
* WAC.X ... ワクチンプログラム by CARROT PARTY
* [HUYEの開発室](http://park7.wakwak.com/~huye/x68000_tool.html)
  * X68K用FD IPLチェックツール
  * X68K用 SRAMチェックツール
* BOOTMENU ... FD IPLの感染チェック機能あり
* ch30*_omake.sys ... FD IPLの感染チェック機能あり
* 電脳クラブ84号「X680x0 に感染するコンピュータ・ウイルスの確認報告」(鎌田誠氏)。
  ウイルスが2種確認されている(名称不明)。
  * IPLVCK (IPL Virus Checker)
  * SPAIM (SRAM Program Area Initializer Maker)


----
[goto index](README.md)
