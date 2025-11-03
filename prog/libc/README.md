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

### spawnv()、spawnve()、spawnvp()
* 第3引数と第4引数の`char*`にconstが付いていない。以下のようにする。
  ```c
  int spawnv (int _mode, const char* _path, const char* const _argv[]);
  ```

### putenv()
* 既存の同名環境変数を上書きする際に`strdup (string)`がエラーになると、`environ`配列から参照されている元の変数のメモリが解放されてしまう。
* 引数stringに`=`が含まれない理由以外でエラー終了すると`errno`が設定されない。
* 引数をstrdup()で複製しているためPOSIXと動作が異なる。setenv()も合わせて変更する。

### setenv()
* 引数をmalloc()で確保したメモリに複製するようにする。putenv()参照。

### スタートアップ中に環境変数が追加されるとmain()の第3引数で受け取れない
https://x.com/kg68k/status/1925927255684870476

### tzset() in libtz.a
* 環境変数TZの内容によってはスタック・バッファオーバーフローを起こす。
  * https://github.com/kg68k/libc-tests/blob/main/src/tz.c
* libc.aのtzset()はスタブ関数なので問題ない。

### ctype.h
* マクロの引数を複数回評価しないようにする。
* テーブルを`const unsigned char *_ctype = &_lc_C_ctype[1];`～`return (_ctype[c] & _ISALNUM);`のように
  参照しているが、ポインタを介する分効率が悪いので、テーブルの定義方法を工夫する。

### getrlimit()
* `getrlimit(RLIMIT_FSIZE, ...)`が`RLIM_INFINITY`より大きい`0xffd00000`を返す。
  * `_loadrlimits()`で設定している`16774144 * 1024`がオーバーフローしている(`0x3_ffd00000`)。

### malloc()
* ヒープを拡大しなければ要求サイズのメモリブロックを作れず、かつメモリブロックのリストの末尾が空ブロックという場合に、
  DOS \_SETBLOCKで拡大できる余地があっても拡大せずにメモリ不足エラーになってしまう。
  * 末尾の空ブロックのサイズを必要拡大サイズから差し引かないのが原因(_ma_new.c _ma_new()での`more = ...`のところ)。
    例えば末尾の空ブロックが6MBのときに`malloc(8*1024*1024)`とすると、2MB拡大すれば足りるのに8MB拡大しようとする。
  * getrlimit()の内部データを直接参照して計算してエラーを返しているため、DOS \_SETBLOCKは実行されない。

### struct _comline (include/sys/dos.h)
* `buffer`メンバーの要素数が255なのでNULの分が足りない。
  * XCとの互換性(include/doslib.hで`#define COMLINE _comline`として別名定義されている)を考えると、
    正しい定義は`struct _cmdline`とかで別に用意する?


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

### POSIXとの互換性向上
* sys/resource.h
  * rlim_tを定義する。

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

### printf系
* asprintf()、vasprintf()
  * 参考: [C標準でasprintfを実装する](https://nost15459.net/blog/stdc-asprintf/)

### XC独自関数の分離
* xxx()という関数名を_xc_xxx()に変更する。
* ヘッダファイル`<x68k/xc/***.h>`で_xc_xxx()の宣言を行う。
* `_X68K_XC_SOURCE`定義時のみ
  * 標準のヘッダファイルから`<x68k/xc/***.h>`をインクルードする。
  * `<x68k/xc/***.h>`でXCの関数名への別名定義(`#define xxx _xc_xxx`)を行う。
* オブジェクトファイルはlibc.aではなくlibxc.aにアーカイブする(リンク時に-lxcオプションを指定する)。

### その他チューンナップ
* __inline_strlen() ... notを使う手法を検討。`__builtin_constant_p()`と`__builtin_strlen()`を使う手法を検討。
* malloc()したメモリを後始末でfree()するパターンは、`__attribute__((__cleanup__(func))) char* buf = malloc(...);`を使う。
* malloc()をハイメモリに対応させる(現在はブロックサイズ32bitの上位8bitをフラグに使っている)。

### その他
* 標準ではHuman68k v3.02以降専用とする(LIBCぱっちの仕様)。
  * Human68k v2.00以降でも使えるようにするライブラリを新設する。ただしDOSコールベクタの複写のみ行い、動作に関しては関与しない。


## 近代的なGCC環境(elf2x68k)への対応
ライブラリをelf2x68kで使えるようにする。

### vfprintf()などでbuiltin-declaration-mismatch警告が発生する
https://twitter.com/kamadox/status/1476568081996849153

### flexible array memberをGCCかつC99未満の場合のみ`[0]`と記述する
https://twitter.com/kg68k/status/1603411122329190401

### sys/iocs_i.h
インラインアセンブラの仕様変更に対応する。

### sys/dos_i.h
* `__DOSCALL`宣言がないので、全てインラインアセンブラにする。
  * gcc1、gcc2用に、`__DOSCALL`宣言を使う従来通りの方法を残してもよいかも。
  * gcc13以降でのインラインアセンブラの互換性について調査が必要。
* DOSコールをシンボルではなく番号で書いてdoscall.equを不要にする。

### interrupt.h
真理子版GCCでない場合はマクロを使用不可にする。
```c
#ifdef __MARIKO_CC__
#define IJUMP(addr) __builtin_saveregs (addr)
#else
__attribute__((__error__("msg"))) static inline IJUMP(void* _addr);
#endif
```
真理子版でも削除したいが、errorやdeprecatedの属性をつける手段がなくユーザーへのフォローができないので、
とりあえずそのまま有効とする。

ちなみにマクロを使うのは古い書き方なので、`rte`で戻るだけの割り込み関数なら関数宣言に
`interrupt`か`attribute((interrupt))`をつける方法にすべきです。  
```c
#ifndef __MARIKO_CC__
#define interrupt __attribute__((__interrupt__))
#endif
```
というのも検討。

### 未確認、要調査
* NaN、Inf
* long longのエンディアン
* long double


## 機能の削減

* `gets()`
* I/O接続のコプロセッサ(68881/68882)を直接制御する数学関数(マクロ `__DIRECT_IOFPU__`)
* `_spawn()`でコマンドラインが256バイト以上かつ実行ファイルがHUPAIR準拠でない場合の強制実行、インダイレクト実行(環境変数 `HUGEARG`)
* `_dos_link()`、`_dos_unlink()`
* GCCの`-mshort`オプションへの対応。


## ドキュメント (X680x0 libc Vol.2 Programmer's Reference)

* p.158 `getrlimit` インクルードファイルは`sys/resource.h`(複数形のsがつかない)が正しい。
* p.190 `kbhit` 戻り値は「キーボードが押されていれば(入力データがあれば)0以外を返し」が正しい。
* p.275 `setrlimit` インクルードファイルは`sys/resource.h`(複数形のsがつかない)が正しい。
* p.533 `_dos_vernum` 下位16ビットと上位16ビットが逆。


## 近代的なGCCでビルドする
* Cコンパイラをelf2x68k(2025-11-04時点では、gcc-13.4.0)に変更する。またはgcc 15の独自ポート。
* src/stdlib/calloc.c: `calloc()`: そのまま最適化コンパイルすると`malloc()`と`memset()`の呼び出しが`calloc()`
  の呼び出しに統合されてしまい、無限に再帰ループしてしまう。
  * 関数に`__attribute__((optimize("-fno-builtin-malloc,-fno-builtin-memset")))`をつけるのは、警告が表示されるのと、
    optimize属性はデバッグ用なので製品に使うなということなので避けたい。
  * コンパイル時のコマンドラインオプションで`-fno-builtin-malloc -fno-builtin-memset`を指定するのは問題のない最適化まで行われなくなる、
    calloc.cだけ個別に指定するのは面倒、ということで避けたい。
  * `malloc()`に別名を定義し、`calloc()`から呼び出す場合のみそちらを使う、という方法にしようと思う。定義方法は要検討。
  * 参考
    * [KMC Staff Blog:GCCの最適化による予期せぬ無限ループの発生](http://blog.kmckk.com/archives/5532458.html)
    * [gcc optimizes calloc to an infinite recursive call when CONFIG_SPEED_OPTIMIZATION=y · Issue #64941 · zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr/issues/64941)


## その他

* 改造版の名称、ライセンスを再検討してリブート(2025年を目標)
* X680x0固有のヘッダファイルをinclude/x68k/ディレクトリに移動する。
  * sys/dos.h、sys/iocs.hは互換性維持のため`#include <x68k/*.h>`という内容のエイリアスにする。
  * ライブラリ内部で使用しているヘッダファイルはまた別のディレクトリにしたほうが良いかも。


----
goto [index](../../README.md) / [プログラミング](../README.md)
