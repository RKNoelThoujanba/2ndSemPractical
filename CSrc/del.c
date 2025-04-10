#include <stdio.h>

#define ARR_MAX_SZ 512

int main(void)
{
    int arr[ARR_MAX_SZ];
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0 || n > ARR_MAX_SZ)
    {
        printf("Invalid n = %d\n", n);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int index;
    printf("Enter index to delete: ");
    scanf("%d", &index);

    if(index < 0 || index >= n)
    {
        printf("Invalid index (%d)\n", index);
        return 2;
    }

    for(int i = index; i < n - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --n;

    printf("New array: \n");
    for(int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }

    printf("\n");
}