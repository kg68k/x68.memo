# X-BASIC

## 外部関数用ツール

* 村田敏幸さんによるソフトウェアツール集&lt;MUSH&gt; (MUSH010.ZIP)に以下のツールが含まれています。
  * dumpfnc.r ... X-BASIC外部関数ファイル内容の表示
  * fnc2def.r ... .fncファイルからの.defファイル簡易生成
  * fnc2h.r ... .fncからの.hファイル簡易生成


## 無効化されている関数
https://x.com/kamadox/status/1933754063675666538
* str float$(float)
* float hexfloat(str)


## テストケース
* BAISC.Xで動作確認しています。
* BASIC.Xで実行する場合はCRLF改行、末尾にEOF付きで保存し、`load@`で読み込みます。
* BC.Xで正しく変換できないものがあるかもしれませんが、BC.Xの動作についてはここでは取り扱いません。

### 浮動小数点数表記
```
? 0.5e+1#
? 0.5e+1
? 0.5e-1#
? 0.5e-1
? 0.5e1#
? 0.5e1
? 0.5#
? 0.5
? 0.e+1#
? 0.e+1
? 0.e-1#
? 0.e-1
? 0.e1#
? 0.e1
? 0.#
? 0.
? 0e+1#
? 0e+1
? 0e-1#
? 0e-1
? 0e1#
? 0e1
? 0#
? .5e+1#
? .5e+1
? .5e-1#
? .5e-1
? .5e1#
? .5e1
? .5#
? .5
```

### print文
```
/*print 0**//
print '\'
print "\"
int a$=1,b=2
print a$b
print "foo""bar"
print "foo"1"bar"
print "foo"b"bar"
print "done."
```

### 「関数のstr型戻り値」のエスケープ解析
```
print f2()
print f3()
end
/**/
func str f2()
str s="foo"
return((s))
endfunc
/**/
func str f3sub(s; str)
return(s)
endfunc
func str f3()
str s="bar"
return(f3sub(s))
endfunc
```

### 文字列演算の多重使用
```
print f1("abc","xyz")
end
func str f1(a; str, b; str)
return(a+f2("-",b))
endfunc
func str f2(a; str, b; str)
return(a+b)
endfunc
```


----
goto [index](../README.md) / [プログラミング](./README.md)
