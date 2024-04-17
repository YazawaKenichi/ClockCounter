#include "sub1.h"
#include <math.h>
#include "../ClockCounter/ClockCounter.h"

void power(const char * path, unsigned int count)
{
    //! instance
    ClockCounter* counter = create_clock_counter(path);
    //! start
    start_counter(counter);

    float wt_inv;
    float wt = 3;

    for(unsigned int i = 0; i < count; i++)
    {
        wt_inv = pow(wt, -1);
    }

    //! stop
    stop_counter(counter);
}

void frac(const char * path, unsigned int count)
{
    //! instance
    ClockCounter* counter = create_clock_counter(path);
    //! start
    start_counter(counter);

    float wt_inv;
    float wt = 3;

    for(unsigned int i = 0; i < count; i++)
    {
        wt_inv = 1 / wt;
    }

    //! stop
    stop_counter(counter);
}

