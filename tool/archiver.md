# アーカイバ

X680x0で使用されるアーカイバは、主にLHA、ZIP、tar(tar+gzip)があります。

ただし、LHAは安全上の問題があるため、新たに書庫を作る場合には使うべきではありません。
* [LZHファイルの使用は危険！作者が使用中止を呼びかけ | 日経クロステック（xTECH）](https://xtech.nikkei.com/it/pc/article/trend/20100810/1026829/)
* [「LZH」の開発中止--企業などは使用しないよう作者が注意喚起 - CNET Japan](https://japan.cnet.com/article/20414735/)
* [国産の圧縮形式「LZH」のUNLHA32.DLLの開発中止へ、LZH形式使用中止を呼びかけ - GIGAZINE](https://gigazine.net/news/20100607-lzh-end/)
* [Vector: LZH形式でファイルをご登録いただいている作者のみなさまへ](http://www.vector.co.jp/for_authors/upload/warn_lzh.html)

また、tar(tar+gzip)は複数のファイルをまとめた後に圧縮を掛けるという仕組みのため、扱いにくいところがあります。

よって、ZIPの使用をおすすめします。


* [桑島技研Online | kg68k.github.io](https://kg68k.github.io/)  
  Zip 2.3 human68k-1.2、UnZip 5.50 human68k-1.4
* [zx.r - アーカイバ / ファイル圧縮 / ファイル差分 - ツール - ソフトウェアライブラリ - X68000 LIBRARY](http://retropc.net/x68000/software/tools/archiver/zx/)  
  zx.r version 1.2


----
goto [index](../README.md) / [ツール](./README.md)
