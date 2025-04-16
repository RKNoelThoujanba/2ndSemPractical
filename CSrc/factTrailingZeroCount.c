#include <stdio.h>
#include <math.h>

typedef unsigned long long u64;

int main(void)
{
    u64 n;
    scanf("%llu", &n);
    u64 zeroCount = 0;
    for(u64 i = 5; i <= n; i *= 5)
    	zeroCount += n / i;
    	
    printf("%llu\n", zeroCount);
}