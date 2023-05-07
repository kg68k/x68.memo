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

### 未実装機能のヘッダファイル
注意書きに「supprted」という脱字がある。

### sys/dos.hのstruct _dpbptrのメンバ`id`が`ide`になっている。
リファレンスは`id`となっており、またXCとの互換が必要なため、単なる誤字。


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


## xdev68k対応

### vfprintf()などでbuiltin-declaration-mismatch警告が発生する
https://twitter.com/kamadox/status/1476568081996849153

### flexible array memberをGCCかつC99未満の場合のみ`[0]`と記述する
https://twitter.com/kg68k/status/1603411122329190401


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
