#include <stdio.h> /* 亂數相關函數 */
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
#include "random_tools.h"

float random_float(float min, float max)
{
    static int s = 11;

    /* 設定亂數種子 */
    srand(time(NULL) + s++);
    
    /* 產生 [min , max) 的浮點數亂數 */
    float rand_float = (max - min) * rand() / (RAND_MAX + 1.0) + min;

    return rand_float;
}


uint32_t random_int(uint32_t min, uint32_t max)
{
    static int s = 18;
    
    /* 設定亂數種子 */
    srand(time(NULL) + s++);

    /* 產生 [min , max] 的整數亂數 */
    uint32_t rand_int = rand() % (max - min + 1) + min;

    return rand_int;
}

void print_bin(uint32_t x) 
{
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define JUDGE_ONE(x,i) 0x80000000 & (x<<i)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define JUDGE_ONE(x,i) 0x00000001 & (x>>i)
#endif
    for(int i = 0; i < 32; i++) {
        if(JUDGE_ONE(x,i))
            putchar('1');
        else
            putchar('0');
    }
}