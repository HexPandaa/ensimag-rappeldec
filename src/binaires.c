#include <stdlib.h>
#include <stdio.h>

static unsigned long long X = 123456ULL;
static unsigned long long m = 1ULL << 48;
static unsigned long long a = 0x5DEECE66D;
static unsigned long long c = 0xB;

unsigned char crand48(void) {
    X = (a * X + c) % m;
    return (X >> 32) & 0xFF;
}

int main(void)
{
    printf("%hhu\n", crand48());
    printf("%hhu\n", crand48());
    printf("%hhu\n", crand48());

    return EXIT_SUCCESS;
}
