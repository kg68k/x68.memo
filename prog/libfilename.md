# ライブラリのファイル名の選択

結論：各人の好みで選んで構いませんが、lib\*.a形式を推奨します。

## ライブラリのファイル形式

X680x0/Human68kで使用できるライブラリの形式には以下の二つがあります。
* XArchiver(AR.X)で作成するアーカイブファイル形式：拡張子 .a
* XLibrarian(LIB.X)で作成するライブラリファイル形式：拡張子 .l

### アーカイブファイル形式：拡張子 .a

長所
* ファイルサイズが小さいです。
* [Object ARchiver(oar.x)](http://retropc.net/x68000/software/develop/ar/oar/)、
  Hi-Speed Archiver(har.x)など、AR.Xより便利な代替ツールがあります。
* 条件により左右されますが、ファイルサイズが小さいためか
  HLKでリンクすると.lより僅かに速いようです。

短所
* .lからの変換に手間がかかります。
* ファイル一覧のインデックスがありません。
  ただし、大抵の場合はファイル全域を一括読み込みするので実質的にデメリットはありません。

### ライブラリファイル形式：拡張子 .l

長所
* .aからは簡単に変換できます。
* ファイル先頭にファイル一覧のインデックスを持ちます。

短所
* ファイルサイズが大きいです。
* LIB.X以外にツールがありません。

## ライブラリのファイル名

ライブラリにはファイル名にlibを付ける慣例がありますが、
ライブラリ名の前後どちらに付けるかの違いがあります。
* 前に付ける：ファイル名 lib\*
* 後に付ける：ファイル名 \*lib

なおファイル名にlibを付けていない独自形式のライブラリも、
数は多くありませんが存在します。

### ファイル名 lib\*

長所
* 世間での一般的なライブラリのファイル名形式です。

短所
* ファイル名の判別が8.3文字だと、ライブラリ名として実質5文字しか使えません
  (TwentyOne組み込みなどで18.3文字になっていれば問題ありません)。
  * 例えば、XCのFLOATFNC.L FLOATEML.L FLOATDRV.Lを
    libfloatfnc.l libfloateml.l libfloatdrv.l
    というファイル名に変更すると、8.3では区別できません。

### ファイル名 \*lib

長所
* ファイル名の判別が8.3文字でも、ライブラリ名として8文字使えます。

## ファイル形式とファイル名の組み合わせ

ファイル形式とファイル名の組み合わせで、2×2で4通りになります。
* lib\*.a
* lib\*.l
* \*lib.a
* \*lib.l

### lib\*.a

LIBCなどフリーソフトウェアのライブラリで多く採用されています
(ただしLIBCではインストールスクリプトで他の形式に変更可能)。  
フリーソフトウェアでは事実上の標準と言ってよいでしょう。

HLKXの`-l`オプションで扱うことができます。

### lib\*.l

フリーソフトウェアでの採用例は少ないです。

### \*lib.a

フリーソフトウェアでの採用例は少ないです(lib\*.lや\*lib.lよりは多いようです)。

### \*lib.l

XCで採用されています(ファイル名はすべて大文字)。
ただしlibなしのFLOATFNC.L FLOATEML.L FLOATDRV.Lというファイル名もあります。

フリーソフトウェアでの採用例は少ないです。


----
goto [index](../README.md) / [プログラミング](./README.md)
