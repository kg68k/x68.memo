# アセンブリ言語のネタ

## アドレスをデータレジスタに入れる

基本形。X形式実行ファイルの場合はリロケート情報が添付され、R形式実行ファイルでは使用できない。
```
  move.l #label,d0
```

リロケート情報なしにしたいならPC相対アドレッシングを使う。ただし相対距離-$8000～$7fffの範囲に限られる。
```
  lea (label,pc),a0
  move.l a0,d0
```

アドレスレジスタを破壊したくない場合。
```
  pea (label,pc)
  move.l (sp)+,d0
```

スタックもアドレスレジスタも使わない。確かツイートで教えてもらった方法。
```
  move.l a0,d0
  lea (label,pc),a0
  exg d0,a0
```

直後のアドレス限定。ショートブランチなら4バイトで済み、上の方法より短い。  
届くなら`@f`にしてもよい。
```
@@:
  move.l (sp)+,d0
  ;...

  bsr.s @b
label:  ;データレジスタに入れたいアドレス(実行はされない)
```

直後から相対距離-$80～+$7fのアドレスにもできるが、6バイトになるので利点はない。
```
@@:
  moveq #offset,d0
  add.l (sp)+,d0
  ;...

  bsr.s @b
label:
```

## テーブルジャンプ

`d0.w`に0～最大値のインデックスが入っているものとする(上限オーバーの検査は省略)。

基本形。`d0.w < $2000`
```
  add d0,d0
  move (@f,pc,d0.w),d0
  jmp  (@f,pc,d0.w)
@@:
  .dc fn0-@b
  .dc fn1-@b
  ...
```

アドレス範囲が収まる場合。`d0.w <= $007e`。これ以降のネタは実用する場合の最大値はもっと小さい。  
テーブルと分岐先のコードが大きくなると`bra.s`で届かなくなる(先頭付近の分岐先を`@@:`より上に書くという緩和策もある)。
* 最後の`bra`のみサイズを省く。
  * 分岐先が遠い場合、ワードブランチで届かせられる。  
  * 分岐先を直後に置くことで、アセンブラの最適化により`bra`命令自体が削除される。
```
  add d0,d0
  jmp (@f,pc,d0.w)
@@:
  bra.s fn0
  bra.s fn1
  ...
  bra fnX

fnX: ...
```

アドレス範囲が収まる場合(分岐先は`@@:`より下に限られる)。`d0.w < $00fc`
```
  move.b (@f,pc,d0.w),d0
  jmp    (@f,pc,d0.w)
@@:
  .dc.b fn0-@b
  .dc.b fn1-@b
  ...
  .dc.b fnX-@b
  .even
```

オフセット値の基準点をずらすことで制限を緩和(分岐先は`B:`より下)。`d0.w < $0100`
```
  move.b (@f,pc,d0.w),d0
  jmp    (B,pc,d0.w)
@@:
  .dc.b fn0-B
  .dc.b fn1-B
  ...
B:
  ...
  .dc.b fnX-B
  .even
```

## 32ビット値の偶数化

データレジスタが奇数なら+1して偶数にする。
```
doeven1: .macro dn
  addq.l #1,dn
  andi.b #$fe,dn
.endm
```

入出力が同じアドレスレジスタの場合。
```
doeven2: .macro an,dn
  move.l an,dn    ;4
  addq.l #1,dn    ;8
  andi.b #$fe,dn  ;8
  movea.l dn,an   ;4
.endm
```

クロック数は同じだが1ワード小さくなる。
```
doeven3: .macro an,dn
  move.w an,dn  ;4
  lsr.w #1,dn   ;8
  subx.w dn,dn  ;4
  suba.w dn,an  ;8
.endm
```
実際には入出力が同じアドレスレジスタというケースはあまりないかも。

入出力が同じメモリの場合(基本形)。
```
doeven4: .macro ea,dn
  moveq #1,dn
  and.l ea,dn
  add.l dn,ea
.endm
```

短くするために`andi.b #$fe,dn`と書きましたが、`andi #$fffe,dn`の方が好み。


## 符号拡張後の2倍
```
  ext.l d0
  add.l d0
```
は`add.l`を`add.w`にすれば4クロック速い(フラグ変化は異なる)。



----
goto [index](../../README.md) / [プログラミング](../README.md)
