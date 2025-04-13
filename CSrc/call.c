#include <stdio.h>

void CallByValue(int n)
{
    printf("Value of n passed to CallByValue(n) is %d\n", n);
    n += 1;
    printf("Added +1 to n\n");
}

void CallByReference(int* n)
{
    if(n == NULL)
    {
        printf("Value of n passed to CallByReference(n) is NULL. Exiting funtion\n");
        return;
    }
    printf("Value of n passed to CallByReference(n) is %d\n", *n);
    *n += 1;

    printf("Added +1 to n\n");
}

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    printf("Call By Value\n");
    CallByValue(n);
    printf("Value of n in main() after function is called: %d\n", n);

    printf("Call By Reference\n");
    CallByReference(&n);
    printf("Value of n in main() after function is called: %d\n", n);
}