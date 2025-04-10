#include <stdio.h>
#include <stdint.h>

int main(void)
{
    unsigned int n;
    printf("n: ");
    scanf("%u", &n);

    unsigned long long factorial = 1;

    for(unsigned int i = 2; i <= n; ++i)
        factorial *= i;
    
    printf("%u! = %llu\n", n, factorial);

}