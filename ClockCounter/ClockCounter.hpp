#ifndef __TIMECOUNTER_HPP__
#define __TIMECOUNTER_HPP__

#include <string>

#define MS 1000

namespace ClockCounter
{
    class ClockCounter
    {
        public:
            ClockCounter(std::string);
            void startCounter();
            void stopCounter();
        private:
            void printf(std::string);
            void writef(std::string);
            std::string path;

            clock_t start;
            clock_t stop;
    };
}

#endif

