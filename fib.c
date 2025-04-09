#include <stdio.h>

int main(void)
{
    int fibElem[2] = {0, 1};
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid n = %d\n", n);
        return 1;
    }

    printf("%d  %d  ", fibElem[0], fibElem[1]);
    for(int i = 2; i < n; ++i)
    {
        int sum = fibElem[0] + fibElem[1];
        printf("%d  ", sum);
        fibElem[0] = fibElem[1];
        fibElem[1] = sum;
    }
}