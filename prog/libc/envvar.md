# LIBCが使用する環境変数

* _sysroot()
  * `SYSROOT`: TwentyOne由来。
* tmpnam()
  * `temp`
* system()
  * `SYSTEM_SHELL`: シェルの実行ファイル名
  * `SYSTEM_SHELLTYPE`: `COMMAND`または`UNIX`
  * `SYSTEM_SHELL_OPT`: シェルのコマンドライン引数
  * `SHELL`: シェルの実行ファイル名
  * `SHELLTYPE`: `COMMAND`または`UNIX`
  * `SHELL_OPT`: シェルのコマンドライン引数
* _loadrlimits()
  * `limit_core`
* uname()
  * `HOST`: 未設定時は`unknown`となる
* tzset()
  * `TZ`
* _spawn()
  * `temp`: インダイレクトファイル作成用
  * `HUGEARG`: `force`なら長い引数でも無理やり実行する。
    `indirect`から始まる文字列なら続く文字列をインダイレクト文字列とする(省略時は`-+-+-`)。
* cuserid()、getlogin()
  * `LOGNAME`
  * `USER`
* getegid()
  * `EGID`
* geteuid()
  * `EUID`
* getgid()
  * `GID`
* getuid()
  * `UID`
