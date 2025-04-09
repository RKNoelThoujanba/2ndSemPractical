#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid n = %d\n", n);
        return 1;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n - i + 1; ++j)
        {
            printf("  %d  ", j);
        }
        printf("\n");
    }
}