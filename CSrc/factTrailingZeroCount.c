#include <stdio.h>
#include <math.h>

typedef unsigned long long u64;

int main(void)
{
    u64 n;
    scanf("%llu", &n);
    u64 trailingZeroCount = 0;
    for(u64 i = 5; i <= n; i *= 5)
        trailingZeroCount += n / i;
    	
    printf("%llu\n", trailingZeroCount);
}