//with fixed decimal of 32 bits
//outputs will be unreadable bytes

#include <stdio.h>
#include <string.h>

#define PRINT_TIMES 100000
#define INITIAL_TIMES 150
#define REG_SIZE 8


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

__uint32_t reg1[REG_SIZE + 1];
__uint32_t reg2[REG_SIZE + 1];
__uint32_t reg3[REG_SIZE + 1];


__uint32_t substitute_combine(__uint32_t mu, __uint32_t x)
{
    //store 32 results in the register,
    //and use the CRC-32 polynomial for feedback
    for(int i = REG_SIZE; i > 0; i--)
    {
        reg1[i] = reg1[i - 1];
        reg2[i] = reg2[i - 1];
        reg3[i] = reg3[i - 1];
    }
    
    reg1[0] = reg2[0] = reg3[0] = substitute(mu, x);

    __uint32_t r1, r2, r3;
    r1 = reg1[5] ^ reg1[2] ^ reg1[0];
    r2 = reg2[3] ^ reg2[2] ^ reg2[1];
    r3 = reg3[2] ^ reg3[0];

    return (r1 * r2) ^ (r2 * r3) ^ r3;
}

int last_put[256];

void find_period(__uint8_t out, int i)
{
    //output the period to the stderr, 
    //and refresh the last_put array
    fprintf(stderr, "%d\n", i - last_put[out]);
    last_put[out] = i;
}

__uint8_t x_output(__uint32_t x)
{
    return x >> 24;
}

int main()
{
    memset(last_put, 0, sizeof(int) * 256);

    memset(reg1, 0, (REG_SIZE + 1) * sizeof(__uint32_t));
    memset(reg2, 0, (REG_SIZE + 1) * sizeof(__uint32_t));
    memset(reg3, 0, (REG_SIZE + 1) * sizeof(__uint32_t));

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
        x = substitute_combine(mu, x);
        
        __uint8_t out = x_output(x);

        find_period(out, i);

        fwrite(&out, sizeof(__uint8_t), 1, stdout);
    }

    return 0;
}
