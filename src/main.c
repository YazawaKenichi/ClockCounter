#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *endptr;
    float v = (float) strtod(argv[3], &endptr);

    if(*endptr != '\0')
    {
        printf("変換エラー： '%s' は有効な浮動小数点数ではない\n", argv[3]);
        return 1;
    }

    frac(argv[1], v);
    power(argv[2], v);

    return 0;
}

