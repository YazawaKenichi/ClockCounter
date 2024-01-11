#include "main.h"

#include <unistd.h>

#include "../ClockCounter/ClockCounter.h"

int main(int argc, char *argv[])
{
    const char* path = argv[1];
    //! instance
    ClockCounter* counter = create_clock_counter("./text");
    //! start
    start_counter(counter);

    unsigned int sec = SEC;
    for(unsigned int i = 0; i < sec; i++)
    {
        sleep(1);
    }

    //! stop
    stop_counter(counter);

    return 0;
}

