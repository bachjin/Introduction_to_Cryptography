//with fixed decimal of 16 bits


/*
### sample input

3.75 0.5

### sample output

239
56
164
220
115
237
64
180
199
164

*/

#include <stdio.h>

#define PRINT_TIMES 100


__uint16_t substitute(__uint16_t mu, __uint16_t x)
{
    //represents 3.57 <= mu + 3 < 4, 0 < x < 1
    __uint32_t temp = x;
    temp *= (x ^ 0xffff);
    //  x ^ 0xffff is 1 - x

    temp = temp >> 16;
    //  the last 16 bit is the fractional part of x*(1-x)

    temp *= (mu >> 2) | 0xc000;
    //  temp *= (mu + 3), the decimal point is left of 30 bits

    return temp >> 14;
}

__uint8_t x_output(__uint16_t x)
{
    return x >> 8;
}

int main()
{
    __uint16_t mu = 0xc000;
    __uint16_t x = 0x8000;

    float m_t, x_t;
    scanf("%f%f", &m_t, &x_t);
    mu = (m_t - 3)* 65536;
    x = x_t * 65536;
    //  mu don't store 3, in other words,
    //  mu only include the fractional part of real mu
    
    for(int i = 1; i <= PRINT_TIMES; i++)
    {
        x = substitute(mu, x);
        
        printf("%d\n", x_output(x));
    }

    return 0;
}
