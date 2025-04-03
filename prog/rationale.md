# なぜ、そうするのか。

## CMakeLists.txtをsrc/ではなくリポジトリのトップディレクトリに置く理由

GitHub ActionsでCMakeを実行する場合に、ワークフローの書き方が少しだけ簡単になる。

src/*をShift_JISに変換しつつHuman68k上のbuild/に転送したとき、
build/にHuman68kビルドに不要なCMakeLists.txtを置かないですむ。


## 自分一人で開発する場合もプルリクエストを行う理由

ブランチ作成 → プルリクエスト → マージの手順にすると、
プルリクエストの段階でGitHub Actionsが実行されビルド検証やコード検証ができ、
不備のあるコミットをmainブランチにマージすることを防げる。

(ただしマージコミットでは途中経過が残る。スカッシュやリベースなら消える)


## ソースコードをUTF-8で保存する理由

Shift_JISだとGitHubやGitツールなどで文字化けする。

近代的なエディタで直接扱えない場合がある。  
(ただし現在のVisual Studio Codeなら基本機能で対応している。以前は拡張機能が必要だった)

デメリットとして、X680x0の機種依存文字(2バイト半角ひらがななど)を扱えないというのがあるが
Human68k用のテキストエディタでも扱いやすいとは言い難いので、文字コードによる記述で済ます。

Human68k上でビルドする場合はShift_JISへの変換が必要だが、
ファイルコピーの代わりに文字コード変換を行うだけなのでたいして手間は増えない。
また、最近のGCCやrun68xであればUTF-8のままで扱うこともできる。

総合的に考えてUTF-8で保存するほうがずっと良い。


## C言語で関数を呼び出し元より先に定義する理由

* プロトタイプ宣言が不要。
* gcc1やgcc2のような古いコンパイラでもインライン展開される。  
  (近代的なコンパイラなら後ろで定義してもインライン展開される)


## plain charをunsigned charにする理由
* GCC ... -funsigned-char
* MSVC ... /J

plain charがsigned charだと以下のようなコードが未定義動作になる。
```c
int isa(const char* s) {
  return isalpha(*s);
}
```
いちいちunsigned charやunsigned char*にキャストするのは煩わしい。

文字列ポインタをunsigned char*で宣言すると上記の問題は解決されるが、
今度は標準関数と引数や戻り値の型が異なってしまう。
```c
size_t sl(const unsigned char* s) {
  return strlen(s);
}
```

plain charがunsigned charなら、上記の問題がすべて解消される。


----
goto [index](../README.md) / [プログラミング](./README.md)
