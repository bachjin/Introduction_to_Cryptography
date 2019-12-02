//with fixed decimal of 32 bits
//outputs will be unreadable bytes

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINT_TIMES 1000000
#define INITIAL_TIMES 150
#define REG_SIZE 8


int PRECISE;

__uint32_t substitute(__uint32_t mu, __uint32_t x)
{
    //with interfere

    //represents 3.57 <= mu + 3 < 4, 0 < x < 1
    x = x >> (32 - PRECISE);
    x = x << (32 - PRECISE);

    __uint64_t temp = x;
    temp *= (x ^ 0xffffffff);
    //  x ^ 0xffffffff is 1 - x

    temp = temp >> 32;
    //  the last 32 bit is the fractional part of x*(1-x)

    temp += rand() % 0x00000100; 
    //  the random interfere is between [0, 256)

    temp *= (mu >> 2) | 0xc0000000;
    //  temp *= (mu + 3), the decimal point is left of 62 bits

    return temp >> 30;
}



__uint8_t x_output(__uint32_t x)
{
    return x >> 24;
}

int main()
{
    scanf("%d", &PRECISE);

    __uint32_t mu = 0xc0000000;
    __uint32_t x = 0x80000000;

    float m_t, x_t;
    scanf("%f%f", &m_t, &x_t);
    mu = (m_t - 3)* 0x100000000;
    x = x_t * 0x100000000;
    //  mu don't store 3, in other words,
    //  mu only include the fractional part of real mu
    
    for(int i = 1; i <= INITIAL_TIMES; i++)
        x = substitute(mu, x);

    for(int i = 1; i <= PRINT_TIMES; i++)
    {
        x = substitute(mu, x);
        
        fwrite(&x, PRECISE / 8, 1, stdout);
    }

    return 0;
}
