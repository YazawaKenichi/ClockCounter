#include "ClockCounter.h"
#include <stdlib.h>
#include <string.h>

char* addString(const char* str1, const char* str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1);

    if(result == NULL)
    {
        fprintf(stderr, "メモリの確保に失敗しました\n");
        exit(EXIT_FAILURE);
    }

    // str1 をコピー
    strcpy(result, str1);
    // str2 を結合
    strcat(result, str2);

    return result;
}

const char* int_to_string(double value)
{
    char* buffer;
    int size = snprintf(NULL, 0, "%f", value);  // 必要なバッファのサイズを取得
    buffer = (char*)malloc(size + 1);  // メモリを動的に確保
    snprintf(buffer, size + 1, "%f", value);  // 整数を文字列に変換
    return buffer;
}

clock_t getClock()
{
    clock_t now = clock();
    return now;
}

void printf_message(const char* msg)
{
    printf("%s\r\n", msg);
}

void write_file(ClockCounter* counter, const char* text)
{
    FILE *fp;
    fp = fopen(addString("/home/amatsukaze/raspicat2/clock/", counter->path), "a");
    if(fp == NULL)
    {
        return;
    }

    printf_message(text);

    fprintf(fp, "%s\r\n", text);
}

ClockCounter* create_clock_counter(const char* path)
{
    //! ClockCounter 構造体のポインタを作成
    ClockCounter* counter = malloc(sizeof(ClockCounter));
    if(counter == NULL)
    {
        return NULL;
    }
    //! 構造体ポインタに path を作成
    counter->path = strdup(path);
    if(counter->path == NULL)
    {
        free(counter);
        return NULL;
    }
    //! 構造体ポインタを返す
    return counter;
}

void start_counter(ClockCounter* counter)
{
    counter->start = getClock();
}

void stop_counter(ClockCounter* counter)
{
    counter->stop = getClock();
    double dur = (double) (counter->stop - counter->start) / (double) CLOCKS_PER_SEC * (double) MS;
    printf("%f = %ld - %ld / %ld * %d\r\n", dur, counter->stop, counter->start, CLOCKS_PER_SEC, MS);
    const char* text = int_to_string(dur);
    write_file(counter, text);
}

