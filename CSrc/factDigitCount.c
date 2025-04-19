#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    scanf("%lf", &x);

    if(x < 0)
    {
        printf("Invalid n\n");
        return 1;
    }
    if((unsigned long long) x != x)
    {
        printf("Warning: flooring x to nearest integer\n");
    }

    double digitCount = 0;
    
    
    for(double i = 2; i <= x; ++i)//lg(1) = 0
    {
        digitCount += log10(i);
    }
    ++digitCount;
    
    printf("%llu\n", (unsigned long long)digitCount);
}