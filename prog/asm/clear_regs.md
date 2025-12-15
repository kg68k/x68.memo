# 複数のレジスタをゼロクリアする

実行速度の速さよりバイト数の少なさを優先。  
(?w)はワード数。

## レジスタ1個: データレジスタのみ (1w)
```
  moveq #0,d0
```

## レジスタ1個: アドレスレジスタのみ (1w)
```
  suba.l a0,a0
```
`suba.w`は上位ワードが0にならないので注意(0になる場合もある)。

## レジスタ2個: データレジスタのみ (2w)
```
  moveq #0,d0
  moveq #0,d1
```

## レジスタ2個: アドレスレジスタのみ (2w)
```
  suba.l a0,a0
  movea.l a0,a1
```
`suba.l`は遅いので2番目からは`movea.l`を使う。

## レジスタ2個: データレジスタ + アドレスレジスタ (2w)
```
  moveq #0,d0
  movea.l d0,a0
```

## レジスタ3個: データレジスタを含む (3w)
```
  moveq #0,d0
  moveq #0,d1    ;残りのレジスタの数だけ並べる
  movea.l d0,a0  ;  (2行)
```

## レジスタ3個: アドレスレジスタのみ (3w)
```
  suba.l a0,a0
  movea.l a0,a1
  movea.l a0,a2
```

## レジスタ4個: データレジスタを含む (4w)
```
  moveq #0,d0
  moveq #0,d1    ;残りのレジスタの数だけ並べる
  movea.l d0,a0  ;  (3行)
  movea.l d0,a1  ;
```

## レジスタ4個: アドレスレジスタのみ (4w)
```
  suba.l a0,a0
  movea.l a0,a1
  movea.l a0,a2
  movea.l a0,a3
```

## レジスタ5個: データレジスタを含む (5w)
```
  moveq #0,d0
  moveq #0,d1    ;
  moveq #0,d2    ;残りのレジスタの数だけ並べる
  movea.l d0,a0  ;  (4行)
  movea.l d0,a1  ;
```

## レジスタ5個: アドレスレジスタのみ (5w)
```
  suba.l a0,a0
  movea.l a0,a1
  movea.l a0,a2
  movea.l a0,a3
  movea.l a0,a4
```

## レジスタ6個 (5w)
```
  clr.l -(sp)
  move.l (sp),-(sp)
  move.l (sp),-(sp)
  movem.w (sp)+,d0-d2/a0-a2  ;レジスタ6個
```
`clr.l -(sp)`より`move.l (sp),-(sp)`の方が速い。

## レジスタ7個: データレジスタを含む (6w)
```
  moveq #0,d0
  move.l d0,-(sp)
  move.l d0,-(sp)
  move.l d0,-(sp)
  movem.w (sp)+,d1-d3/a0-a2  ;レジスタ6個
```

## レジスタ7個: アドレスレジスタのみ (6w)
```
  suba.l a0,a0
  move.l a0,-(sp)
  move.l a0,-(sp)
  move.l a0,-(sp)
  movem.w (sp)+,a1-a6  ;レジスタ6個
```

## レジスタ8個 (6w)
```
  clr.l -(sp)
  move.l (sp),-(sp)
  movem.w (sp),d0-d3   ;レジスタ4個
  movem.w (sp)+,a0-a3  ;レジスタ4個
```
`move.l (sp),-(sp)`を並べるより`movem.w`を並べた方が速い。

## レジスタ9個 (6w)
```
  moveq #10/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d4/a0-a3/sp  ;レジスタ9個 + sp
```
`movem`の実効アドレスがポストインクリメントのとき同じレジスタ(この場合`sp`)
へのロードが無視される挙動を利用し、レジスタを2個単位にしている
(レジスタが空いていればそちらにしても良い)。

ループカウンタはクリアするデータレジスタを使う。以後のコードも同じ。

## レジスタ10個 (6w)
```
  moveq #10/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d4/a0-a4  ;レジスタ10個
```

## レジスタ11個 (6w)
```
  moveq #12/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d5/a0-a4/sp  ;レジスタ11個 + sp
```

## レジスタ12個 (6w)
```
  moveq #12/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d5/a0-a5  ;レジスタ12個
```

## レジスタ13個 (6w)
```
  moveq #14/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d6/a0-a5/sp  ;レジスタ13個 + sp
```

## レジスタ14個 (6w)
```
  moveq #14/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d6/a0-a6  ;レジスタ14個
```

## レジスタ15個 (6w)
```
  moveq #16/2-1,d0
  @@:
    clr.l -(sp)
  dbra d0,@b
  movem.w (sp)+,d0-d7/a0-a6/sp  ;レジスタ15個 + sp
```

## 速度優先版 レジスタ6個以上
レジスタ6個以上で速度優先にしたい場合は、
レジスタ5個のパターンと同じように必要なだけ命令を並べる。

例: レジスタ15個(d0-d7/a0-a6)
```
  moveq #0,d0
  moveq #0,d1
  moveq #0,d2
  moveq #0,d3
  moveq #0,d4
  moveq #0,d5
  moveq #0,d6
  moveq #0,d7
  movea.l d0,a0
  movea.l d0,a1
  movea.l d0,a2
  movea.l d0,a3
  movea.l d0,a4
  movea.l d0,a5
  movea.l d0,a6
```


----
goto [index](../../README.md) / [プログラミング](../README.md)
