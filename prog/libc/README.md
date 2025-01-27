# リンク

* [LIBC 1.1.32A - ライブラリ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY](http://retropc.net/x68000/software/develop/lib/libc1132a/)
* [LIBC 1.1.32A ぱっち DON 版 - ライブラリ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY](http://retropc.net/x68000/software/develop/lib/libcdon/)
* https://github.com/kg68k/libc-tests

----
# TODO
整理が行き届いていないため、LIBCとLIBCぱっちの話が混在しています。ご留意願います。

## 不具合の修正

### テキストモードのファイル位置
https://twitter.com/kg68k/status/1601896787207258112

### access()が失敗時にも成功を返す
https://twitter.com/kg68k/status/1562037717994651649

### include/sys/xstdio.h `#define __sys_xglob_h__`
インクルードガードが `__sys_xglob_h__` になっている。
src\stdio\tempnam.c で xglob.h と同時にインクルードしているが、xstdio.h
側の関数を使用していないので問題になっていなかった。

### _pathexpand() (_fullpath())
* TwentyOneのSYSROOTを正しく展開できない。
* ルートディレクトリを指定すると`D://`のようにルートのパスデリミタが重複する。

### _isremotefs()
間違ったドライブを調べてしまう。

### _statsub() (stat())
* 仮想ディレクトリを正しく処理できない。
* ボリュームラベルの`st_ino`の下位桁が`0`であることを仕様に明記する
  (同一ドライブ上で同一inode値のボリュームラベルが存在することがある)。
* `st_ino`の上位桁にドライブ番号を入れないようにする(include/sys/xstat.h `MAKEINODE()`マクロ)。

### iocslib.hでTLINEPTRが定義されない(未確認、要調査)
XC iocslib.h struct TLINEPTR

### 未実装機能のヘッダファイル
注意書きに「supprted」という脱字がある。

### sys/dos.hのstruct _dpbptrのメンバ`id`が`ide`になっている。
リファレンスは`id`となっており、またXCとの互換が必要なため、単なる誤字。

### mkstemp()
* `mktemp()`を使うのをやめ、`DOS _MAKETMP`でファイル名の作成とファイルの作成オープンを同時に行う。

### wabs()
* src/stdlib/wabs.s: 引数が0または正数のときd0.wを符号拡張(`ext.l d0`)しないため、d0.lの上位ワードが不定の値となる。実害はない。

### char* sys_errlist[]
* `[0]`に`"Unknown error"`が挿入されているため、`sys_errlist[errno]`でエラー文字列を得ることができない。
  * XC互換のための仕様かもしれない。
  * GCC真理子版のLIBCビルド時に対処が必要。
  * UN*X環境では現在は非推奨、XCと仕様が違う、などの理由からいっそ削除したほうが良い。

### _dos_ioctrlfdctl()、_dos_ioctrldvctl()、IOCTRLFDCTL()、IOCTRLDVCTL()
* 機能が入れ替わっているが、XCのDOSLIBがそうなっている。
  * 互換性維持のため入れ替わったままにしておき、ドキュメントでの説明で対応する。
  * 正しい関数を用意したい。暫定案: `_dos_ioctrlfdctl12()`、`_dos_ioctrldvctl13()`

### opendir()
* `opendir("")`をエラーにする(WSL2/Ubuntuではエラーになっている)。
* その他機能テスト用のマクロを定義するなど、direntの仕様を改善する。

### readdir()
* `d_reclen`メンバーが`d_namlen`と同じ値になっているので、レコード(`struct dirent`)の大きさにする。
  * opendir()実行時にすべてのエントリを読み込んでいるので実際の処理はopendir()内にある。

### closedir()
* 返り値が`void`になっているので、`int`にする。

### _fullpath()
* 仮想ディレクトリに割り当てたドライブ名が割り当て先のパス名に展開されてしまう。
  * `opendir()`、`ftw()`、`stat()`、`lstat()`において使用できないドライブ名を指定できてしまう
    (例えば`subst d:\dir x:`としたときx:はアクセスできないが、`opendir("x:/")`が成功してしまう)。

### strftime()
* `form()`でバッファサイズが足りないと`va_end()`マクロを呼び出さずに`return`している(未定義動作)。
* `count`が負数の場合にデクリメントしてしまう、`strout:`ラベルでバッファ不足のとき`strptr`をデクリメントしてしまう、
  という挙動も気になるが特に問題はおきないはず。

### sleep()
* 単位時間ごとの分割処理の最中にシグナルが発生すると中断しない。未確認、要調査。
* `sleep()`がシグナルにより中断した場合に、残り時間ではなく常に0を返してしまう。未確認、要調査。

### usleep()
* 単位時間ごとの分割処理の最中にシグナルが発生すると中断しない。未確認、要調査。
* `usleep()`がシグナルにより中断した場合に、残り時間(マイクロ秒)ではなく常に0を返してしまう。未確認、要調査。
  * ただし、`errno = EINTR;`として-1を返す仕様に変更すべき。
* `usleep()`の引数を`useconds_t`型にする。


## 機能の追加改善

### C23、C2yに対応(需要のあるものから)
* stdbool.h
* stdint.h
* inttypes.h
* [C23の改善点：文字列検索関数でのconst性の維持](https://zenn.dev/mod_poppo/articles/c23-constness)

### Visual C++との互換性向上
* fopen_s()
* _O_BINARY
* _countof()
* _fileno()
* _setmode()

### getexecname(): 実行ファイルのフルパス名を返す
https://twitter.com/kg68k/status/1610270055765520384

### getopt.hの追加
* getopt() (unistd.hでの宣言と重複する)
* getopt_long()
* getopt_long_only()

### XCとの互換性向上
* include/class.h
  * doslib.h、iocslib.hから読み込まれる。

### X-BASIC用ライブラリ
* include/basic.h
* include/basic0.h
* lib/libbas.a

### ディスク入出力(unistd.h)
* sync()
* fsync()

### 時計操作(time.h)
* asctime_r() ... POSIX.1-2024では廃止されている。
* ctime_r() ... POSIX.1-2024では廃止されている。
* gmtime_r()
* localtime_r()
  * C11で追加された拡張のlocaltime_s()は、glibcでサポートされていない、MSVCで同名の関数があるが仕様が異なる、
    という状況のため当面は対応しない。

### その他チューンナップ
* __inline_strlen() ... notを使う手法を検討。


## 近代的なGCC環境(elf2x68k)への対応

### vfprintf()などでbuiltin-declaration-mismatch警告が発生する
https://twitter.com/kamadox/status/1476568081996849153

### flexible array memberをGCCかつC99未満の場合のみ`[0]`と記述する
https://twitter.com/kg68k/status/1603411122329190401

### sys/iocs_i.h
インラインアセンブラの仕様変更に対応する。

### sys/dos_i.h
`__DOSCALL`宣言がないので、全てインラインアセンブラにする。

### 未確認、要調査
* NaN、Inf
* long longのエンディアン
* long double


## 機能の削減

* `gets()`
* I/O接続のコプロセッサ(68881/68882)を直接制御する数学関数(マクロ `__DIRECT_IOFPU__`)
* `_spawn()`でコマンドラインが256バイト以上かつ実行ファイルがHUPAIR準拠でない場合の強制実行、インダイレクト実行(環境変数 `HUGEARG`)
* `_dos_link()`、`_dos_unlink()`


## ドキュメント (X680x0 libc Vol.2 Programmer's Reference)

* p.533 `_dos_vernum` 下位16ビットと上位16ビットが逆。


## その他

* 改造版の名称、ライセンスを再検討してリブート(2025年を目標)
* Cコンパイラをelf2x68k(gcc-13.2.0)に変更する
* X680x0固有のヘッダファイルをinclude/x68k/ディレクトリに移動する。
  * sys/dos.h、sys/iocs.hは互換性維持のため`#include <x68k/*.h>`という内容のエイリアスにする。
  * ライブラリ内部で使用しているヘッダファイルはまた別のディレクトリにしたほうが良いかも。


----
goto [index](../../README.md) / [プログラミング](../README.md)
