//with fixed decimal of 32 bits
//outputs will be unreadable bytes

#include <stdio.h>

#define PRINT_TIMES 100000


int PRECISE;

__uint32_t substitute(__uint32_t mu, __uint32_t x)
{
    //represents 3.57 <= mu + 3 < 4, 0 < x < 1
    x = x >> (32 - PRECISE);
    x = x << (32 - PRECISE);

    __uint64_t temp = x;
    temp *= (x ^ 0xffffffff);
    //  x ^ 0xffffffff is 1 - x

    temp = temp >> 32;
    //  the last 32 bit is the fractional part of x*(1-x)

    temp *= (mu >> 2) | 0xc0000000;
    //  temp *= (mu + 3), the decimal point is left of 62 bits

    return temp >> 30;
}

__uint8_t x_output(__uint32_t x)
{
    return x >> 24;
}

int last_put[256];

void find_period(__uint8_t out, int i)
{
    //output the period to the stderr, 
    //and refresh the last_put array
    fprintf(stderr, "%d\n", i - last_put[out]);
    last_put[out] = i;
}

int main()
{
    memset(last_put, 0, sizeof(int) * 256);

    scanf("%d", &PRECISE);

    __uint32_t mu = 0xc0000000;
    __uint32_t x = 0x80000000;

    float m_t, x_t;
    scanf("%f%f", &m_t, &x_t);
    mu = (m_t - 3)* 0x100000000;
    x = x_t * 0x100000000;
    //  mu don't store 3, in other words,
    //  mu only include the fractional part of real mu
    
    for(int i = 1; i <= PRINT_TIMES; i++)
    {
        x = substitute(mu, x);
        
        __uint8_t out = x_output(x);

        find_period(out, i);

        fwrite(&out, sizeof(__uint8_t), 1, stdout);
    }

    return 0;
}
