#include "ClockCounter.hpp"

#include <fstream>
#include <iostream>

using namespace std;

namespace ClockCounter
{
    ClockCounter::ClockCounter(string _path) : start(0), stop(0)
    {
        this->path = _path;
    }

    //! 計測開始
    void ClockCounter::startCounter()
    {
        //! 開始時刻の取得
        this->start = clock();
    }

    //! 計測終了
    void ClockCounter::stopCounter()
    {
        //! 終了時刻の取得
        this->stop = clock();
        //! 差分の算出
        double ms = (double) (this->stop - this->start) / (double) CLOCKS_PER_SEC * (double) MS;
        //! 処理時間 ms 変数を std::chrono::seconds::rep 型から std::string 型に変換
        std::string text = std::to_string(ms);
        this->writef(text);
    }

    void ClockCounter::printf(string msg)
    {
        cout << msg << endl;
    }

    void ClockCounter::writef(string _text)
    {
        fstream file;
        file.open(this->path, std::ios_base::app);
        if (file.is_open())
        {
            string text = _text + "\r\n";
            this->printf(text);
            file.write(text.data(), text.size());
        }
    }
}

