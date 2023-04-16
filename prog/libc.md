# リンク

- [LIBC 1.1.32A - ライブラリ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY](http://retropc.net/x68000/software/develop/lib/libc1132a/)
- [LIBC 1.1.32A ぱっち DON 版 - ライブラリ - プログラミング - ソフトウェアライブラリ - X68000 LIBRARY](http://retropc.net/x68000/software/develop/lib/libcdon/)


----
# TODO
整理が行き届いていないため、LIBCとLIBCぱっちの話が混在しています。ご留意願います。

## 不具合の修正

### テキストモードのファイル位置
https://twitter.com/kg68k/status/1601896787207258112

### access()が失敗時にも成功を返す
https://twitter.com/kg68k/status/1562037717994651649

### 近代的なGCCでbuiltin-declaration-mismatchが起きる
https://twitter.com/kamadox/status/1476568081996849153

### include/sys/xstdio.h `#define __sys_xglob_h__`
インクルードガードが `__sys_xglob_h__` になっている。
src\stdio\tempnam.c で xglob.h と同時にインクルードしているが、xstdio.h
側の関数を使用していないので問題になっていなかった。

### _pathexpand() (_fullpath())
- TwentyOneのSYSROOTを正しく展開できない。
- ルートディレクトリを指定すると`D://`のようにルートのパスデリミタが重複する。

### _isremotefs()
間違ったドライブを調べてしまう。

### _statsub() (stat())
- 仮想ディレクトリを正しく処理できない。
- ボリュームラベルの`st_ino`の下位桁が`0`であることを仕様に明記する
  (同一ドライブ上で同一inode値のボリュームラベルが存在することがある)。
- `st_ino`の上位桁にドライブ番号を入れないようにする。

### iocslib.hでTLINEPTRが定義されない(未確認、要調査)
XC iocslib.h struct TLINEPTR


## 機能の追加改善

### C23に対応(需要のあるものから)
- stdbool.h
- stdint.h
- inttypes.h

### Visual C++との互換性向上
- fopen_s()
- _O_BINARY
- _countof()
- _fileno()
- _setmode()

### getexecname(): 実行ファイルのフルパス名を返す
https://twitter.com/kg68k/status/1610270055765520384

## 未確認、要調査

### xdev68k(gcc12)で変更になる挙動の影響調査
- NaN、Inf
- long longのエンディアン
- long double

## その他

- 改造版の名称、ライセンスを再検討してリブート(2024年を目標)
- Cコンパイラをxdev68k/gcc12に変更

----
goto [index](../README.md) / [プログラミング](./README.md)
