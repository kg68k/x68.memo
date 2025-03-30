# XCコンパイラ

* [C Compiler PRO-68K ver2.1 NEW KITの不具合](bugs.md)


## 事前定義マクロ
```
#define __LINE__ ソースファイル中の行番号を表す10進定数
#define __FILE__ ソースファイル名を表す文字列定数
#define __STDC__ ANSI規格版番号(準拠している場合は1、オプション/X指定時は定義されない)
#define __DATE__ コンパイルの日時を表す文字列定数("Mmm dd yyyy")
#define __TIME__ コンパイルの時間を表す文字列定数("hh:mm:ss")

#define X68000 1
#define Human68K 1
```

----

# XCライブラリ

## スプライト関数の垂直帰線待ち機能

XCライブラリのスプライト関数はIOCSコールをほぼそのまま呼び出すだけなので、垂直帰線待ち機能も有効となっています。  
詳しくはIOCSコールのリファレンスマニュアルを参照してください。

確認用コード: [iocs_sp_vsync.c](iocs_sp_vsync.c)


----
goto [index](../../README.md) / [プログラミング](../README.md)
