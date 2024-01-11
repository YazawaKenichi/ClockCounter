#ifndef __CLOCKCOUNTER_H__
#define __CLOCKCOUNTER_H__

#include <stdio.h>
#include <time.h>

#define MS 1000

typedef struct ClockCounter_
{
    clock_t start;
    clock_t stop;
    const char* path;
} ClockCounter;

char* addString(const char* str1, const char* str2);
const char* int_to_string(double value);
clock_t  getClock();
void printf_message(const char* msg);
void write_file(ClockCounter* counter, const char* text);
ClockCounter* create_clock_counter(const char* path);
void start_counter(ClockCounter* counter);
void stop_counter(ClockCounter* counter);

#endif

