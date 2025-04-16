#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    scanf("%lf", &x);
    double digitCount = 0;
    for(double i = 2; i <= x; ++i)//lg(1) = 0
    {
        digitCount += log10(i);
    }
    ++digitCount;
    
    printf("%llu\n", (unsigned long long)digitCount);
}