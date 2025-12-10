# ヘッダーファイル

| ファイル名      | C23 | POSIX | XC | LIBC  | 種別 | 備考 |
|-----------------|-----|-------|----|-------|------|------|
| sys/dir.h       |     |       |    | LIBC  | 互換 | 4.3BSD(?) |
| sys/dos.h       |     |       |    | LIBC  | 特有 |      |
| sys/dos_i.h     |     |       |    | LIBC  | 内部 |      |
| sys/dos_p.h     |     |       |    | LIBC  | 内部 |      |
| sys/errno.h     |     |       |    | LIBC  |      | 古いUNIX(?)。記載はないが互換ファイルのはず |
| sys/exec.h      |     |       |    | LIBC  | 互換 | 4.3BSD(?)。.Xの構造を定義 |
| sys/fcntl.h     |     |       |    | LIBC  | 互換 | SYSV(?) |
| sys/file.h      |     |       |    | LIBC  | 互換 | 4.3BSD(?) |
| sys/iocs.h      |     |       |    | LIBC  | 特有 |      |
| sys/iocs_i.h    |     |       |    | LIBC  | 内部 |      |
| sys/iocs_p.h    |     |       |    | LIBC  | 内部 |      |
| sys/locking.h   |     |       |    | LIBC  | 互換 | MS-C 7.0 |
| sys/math_f.h    |     |       |    | patch | 内部 |      |
| sys/math_fe.h   |     |       |    | patch | 内部 |      |
| sys/math_i.h    |     |       |    | patch | 内部 |      |
| sys/mman.h      |     | POSIX |    | LIBC  | 互換 | AES/OS・SVR4。未実装 |
| sys/param.h     |     |       |    | LIBC  | 互換 | 古いUNIX(?) |
| sys/project.h   |     |       |    | LIBC  | 特有 | ソースはglob/にある |
| sys/resource.h  |     | POSIX |    | LIBC  | 互換 | 古いUNIX(?) |
| sys/scsi.h      |     |       |    | LIBC  | 特有 |      |
| sys/signal.h    |     |       |    | LIBC  | 互換 | 古いUNIX(?) |
| sys/stat.h      |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| sys/time.h      |     | POSIX |    | LIBC  | 互換 | 古いUNIX(?)。一部のみ実装 |
| sys/timeb.h     |     |       |    | LIBC  | 互換 | XC互換だがパスが違う |
| sys/timers.h    |     |       |    | LIBC  | 互換 | AES/OS・SVR4。一部のみ実装 |
| sys/times.h     |     | POSIX |    | LIBC  |      | 古いUNIX(?) |
| sys/types.h     |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| sys/utsname.h   |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| sys/wait.h      |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988)。一部のみ実装 |
| sys/xdoseml.h   |     |       |    | LIBC  | 内部 |      |
| sys/xglob.h     |     |       |    | LIBC  | 内部 |      |
| sys/xgrp.h      |     |       |    | LIBC  | 内部 |      |
| sys/xmath.h     |     |       |    | LIBC  | 内部 |      |
| sys/xmbstring.h |     |       |    | LIBC  | 内部 |      |
| sys/xprof.h     |     |       |    | LIBC  | 内部 |      |
| sys/xpwd.h      |     |       |    | LIBC  | 内部 |      |
| sys/xresource.h |     |       |    | LIBC  | 内部 |      |
| sys/xsignal.h   |     |       |    | LIBC  | 内部 |      |
| sys/xstart.h    |     |       |    | LIBC  | 内部 |      |
| sys/xstart_hu.h |     |       |    | LIBC  | 内部 |      |
| sys/xstart_sx.h |     |       |    | LIBC  | 内部 |      |
| sys/xstat.h     |     |       |    | LIBC  | 内部 |      |
| sys/xstdio.h    |     |       |    | LIBC  | 内部 |      |
| sys/xstdlib.h   |     |       |    | LIBC  | 内部 |      |
| sys/xstring.h   |     |       |    | patch | 内部 |      |
| sys/xtime.h     |     |       |    | LIBC  | 内部 |      |
| sys/xunistd.h   |     |       |    | LIBC  | 内部 |      |
| sys/xwstring.h  |     |       |    | patch | 内部 |      |
| alloca.h        |     |       |    | LIBC  | 互換 | 4.3BSD |
| assert.h        | C23 | POSIX | XC | LIBC  |      |      |
| audio.h         |     |       | XC | LIBC  |      |      |
| basic.h         |     |       | XC |       |      |      |
| basic0.h        |     |       | XC |       |      |      |
| class.h         |     |       | XC |       |      |      |
| a_out.h         |     |       |    | LIBC  | 特有 | ファイル名はUNIX由来だが、.Xの構造を定義 |
| cdecl.h         |     |       |    | LIBC  | 内部 |      |
| complex.h       | C23 | POSIX |    |       |      |      |
| conio.h         |     |       | XC | LIBC  | 互換 | XC   |
| ctype.h         | C23 | POSIX | XC | LIBC  |      |      |
| direct.h        |     |       | XC |       |      |      |
| dirent.h        |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| doslib.h        |     |       | XC | LIBC  | 互換 | XC   |
| err.h           |     |       |    | patch | 互換 | 4.4BSD |
| errno.h         | C23 | POSIX |    | LIBC  |      |      |
| error.h         |     |       | XC |       |      |      |
| fcntl.h         |     | POSIX | XC | LIBC  | 互換 | POSIX.1(1988) |
| fctype.h        |     |       | XC |       |      |      |
| fenv.h          | C23 | POSIX |    |       |      |      |
| float.h         | C23 | POSIX | XC | LIBC  |      |      |
| ftw.h           |     | POSIX |    | LIBC  | 互換 | XPG3 |
| gpib.h          |     |       | XC | patch |      | 未実装 |
| graph.h         |     |       | XC | patch |      | インライン関数として実装 |
| grp.h           |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| image.h         |     |       | XC | patch |      | インライン関数として、一部のみ実装 |
| interrupt.h     |     |       |    | LIBC  | 特有 | 真里子版GCCの拡張機能による割り込み処理 |
| inttypes.h      | C23 | POSIX |    |       |      |      |
| io.h            |     |       | XC | LIBC  | 互換 | XC   |
| iocslib.h       |     |       | XC | LIBC  | 互換 | XC   |
| iso646.h        | C23 | POSIX |    |       |      |      |
| jctype.h        |     |       | XC | LIBC  | 互換 | XC、MS-C 7.0 |
| jfctype.h       |     |       | XC | patch | 互換 | XC   |
| jstring.h       |     |       | XC | LIBC  | 互換 | XC、MS-C 7.0 |
| langinfo.h      |     | POSIX |    | LIBC  | 互換 | XPG3。未実装 |
| limits.h        | C23 | POSIX | XC | LIBC  |      |      |
| locale.h        | C23 | POSIX |    | LIBC  |      | Cロケールのみ対応 |
| malloc.h        |     |       |    | LIBC  | 互換 | SYSV(?) |
| math.h          | C23 | POSIX | XC | LIBC  |      |      |
| mbctype.h       |     |       |    | LIBC  | 互換 | MS-C 7.0 |
| mbstring.h      |     |       |    | LIBC  | 互換 | MS-C 7.0 |
| mem.h           |     |       |    | patch | 互換 | MS-C(?) |
| memory.h        |     |       |    | LIBC  |      | MS-C(?)。記載はないが互換ファイルのはず |
| mouse.h         |     |       | XC | patch |      | インライン関数として実装 |
| music.h         |     |       | XC | patch |      | 未実装 |
| music3.h        |     |       | XC | patch |      | 未実装 |
| nl_types.h      |     | POSIX |    | LIBC  | 互換 | XPG3。未実装 |
| poll.h          |     | POSIX |    | LIBC  | 互換 | AES/OS・SVR4。未実装 |
| process.h       |     |       | XC | LIBC  | 互換 | XC   |
| pwd.h           |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| regexp.h        |     |       |    | LIBC  | 互換 | XPG3。未実装 |
| search.h        |     | POSIX |    | LIBC  | 互換 | XPG3。一部のみ実装 |
| setjmp.h        | C23 | POSIX | XC | LIBC  |      |      |
| signal.h        | C23 | POSIX | XC | LIBC  |      |      |
| sprite.h        |     |       | XC | patch |      | インライン関数として実装 |
| stat.h          |     |       | XC | patch | 互換 | XC   |
| stdalign.h      | C23 | POSIX |    |       |      |      |
| stdarg.h        | C23 | POSIX | XC | LIBC  |      |      |
| stdatomic.h     | C23 | POSIX |    |       |      |      |
| stdbit.h        | C23 |       |    |       |      |      |
| stdbool.h       | C23 | POSIX |    |       |      |      |
| stdchkdint.h    | C23 |       |    |       |      |      |
| stddef.h        | C23 | POSIX | XC | LIBC  |      |      |
| stdint.h        | C23 | POSIX |    |       |      |      |
| stdio.h         | C23 | POSIX | XC | LIBC  |      |      |
| stdlib.h        | C23 | POSIX | XC | LIBC  |      |      |
| stdnoreturn.h   | C23 | POSIX |    |       |      |      |
| stick.h         |     |       | XC | patch |      | インライン関数として実装 |
| string.h        | C23 | POSIX | XC | LIBC  |      |      |
| strings.h       |     | POSIX |    | LIBC  | 互換 | 4.3BSD(?) |
| termios.h       |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988)。未実装 |
| tgmath.h        | C23 | POSIX |    |       |      |      |
| threads.h       | C23 | POSIX |    |       |      |      |
| time.h          | C23 | POSIX | XC | LIBC  |      |      |
| timeb.h         |     |       | XC |       |      | LIBCではsys/timeb.hに移動 |
| uchar.h         | C23 | POSIX |    |       |      |      |
| ulimit.h        |     |       |    | LIBC  | 互換 | XPG3。未実装 |
| unistd.h        |     | POSIX |    | LIBC  | 互換 | POSIX.1(1988) |
| utime.h         |     |       | XC | LIBC  |      | POSIX.1-2017にはあるが、-2024で削除された |
| varargs.h       |     |       |    | LIBC  | 互換 | XPG3 |
| wchar.h         | C23 | POSIX |    | LIBC  | 特有 |      |
| wctype.h        | C23 | POSIX |    | LIBC  | 互換 | AES/OS・SVR4 |
| widec.h         |     |       |    | LIBC  | 互換 | AES/OS・SVR4。未実装 |
| wstring.h       |     |       |    | LIBC  | 互換 | AES/OS・SVR4 |

* POSIXの項はPOSIX.1-2024 (IEEE Std 1003.1-2024)による。
* LIBCの項の「patch」はLIBCぱっちで追加されたもの。
* MS-CはMicrosoft C/C++のこと。
* 種別
  * 互換 …… ほかの処理系(備考欄に記載)への互換のために用意されたファイル。
  * 特有 …… LIBCに特有のファイル。
  * 内部 …… LIBCのライブラリを作成するために内部で使用しているファイル。
* 互換ファイルの情報はLIBCのリファレンスマニュアルを情報源としている。
  * XCの独自ファイルでもLIBCのリファレンスに互換として明示されていないものは種別欄を空白とした。
  * SYSVと4.3BSDは「その他の互換ファイル」の節にまとめられていたので明確ではない。
  * SYSVと4.3BSDより遡りそうなものは「古いUNIX(?)」とした。
* 定義や宣言の内容は無視して、ファイルの有無だけを比較している。
* アセンブリ言語用のファイル(\*.mac \*.equ 一部\*.h)は除外している。
* POSIXにしかないファイルは除外している。
  * arpa/inet.h
  * net/if.h
  * netinet/in.h netinet/tcp.h
  * sys/ipc.h sys/msg.h sys/select.h sys/sem.h sys/shm.h sys/socket.h sys/statvfs.h sys/uio.h sys/un.h 
  * aio.h cpio.h devctl.h dlfcn.h endian.h fmtmsg.h fnmatch.h glob.h iconv.h libintl.h libgen.h monetary.h
    mqueue.h ndbm.h netdb.h pthread.h regex.h sched.h semaphore.h spawn.h syslog.h tar.h utmpx.h wordexp.h

