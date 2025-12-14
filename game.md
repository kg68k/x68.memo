# ゲーム

## 同人ゲーム

### Lock On! 2
* 起動時の「NEW GAME (L) or CONTINUE (R)?」はジョイスティックの左右。キーボードのNキーでも始まる。
  [@Awed_Urshy/1968117489394651539](https://x.com/Awed_Urshy/status/1968117489394651539)

### PARORAM
* サンプリングドラムと効果音が両方ともONの」状態ではゲームスタートできない。
  [@Kazurin000/1947181309866176778](https://x.com/Kazurin000/status/1947181309866176778)
  * MIDIなしはXF1～XF4をOFF・ON・OFF・ON
  * MIDIありはXF1～XF4をON・ON・OFF・ON
  * 設定後にジョイスティックのボタンでゲームスタート
* MIDIはMT-32、CM-32L、CM-64に対応。
* キー操作
  * XF1～XF3 …… ?
  * XF4 …… 効果音のON・OFF
  * F1～F10 …… BGM PLAY
  * S …… BGM STOP
* ディスク内のREADME.DOCにも補足説明あり。

### ねぴあらんど
* RTCアラーム/1Hz/16Hz割り込みのベクタが使用されていると、スプライトの表示数が減る。
  [@kg68k/1999993077344391315](https://x.com/kg68k/status/1999993077344391315)
  * 竹馬が表示されず取得できないため敵を倒せず進行できない。
  * パッチ nl.x 115508バイト 1997-12-28 15:29:56  
    `$0001486D: 38 3C`


----
[goto index](README.md)
