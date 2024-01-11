# ClockCounter
## 概要
C++ で使用可能なプログラムの処理時間を計測し、結果を任意のファイルに保存することができるプログラム

## 単位
```
ミリ秒
```

## 使用方法
### C++
``` C++
//! 書き出すファイルパスを指定してインスタンス化
auto cc = ClockCounter::ClockCounter(std::string path);
//! 計測開始
cc.startCounter();
//! 計測停止してファイルに書き出し
cc.stopCounter();
```

