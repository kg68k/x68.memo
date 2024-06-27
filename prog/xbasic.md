# X-BASIC

## 浮動小数点数表記のテストケース

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
(BASIC.Xで実行する場合はCRLF改行、末尾にEOF付きで保存し、`load@`で読み込みます)


## BASTOC用テストケース
BASIC.Xでエラーなく動作するコードですが、BC.Xで正しく変換できないものがあるかもしれません。

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

## 「関数の str 型戻り値」のエスケープ解析のテストケース
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


----
goto [index](../README.md) / [プログラミング](./README.md)
