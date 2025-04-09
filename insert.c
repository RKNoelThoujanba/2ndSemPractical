#include <stdio.h>

#define ARR_MAX_SZ 512

int main(void)
{
    int arr[ARR_MAX_SZ] = {0};
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0 || n > ARR_MAX_SZ - 1)
    {
        printf("Invalid n = %d\n", n);
        return 1;
    }

    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int index;
    printf("Enter the index where element is to be inserted: ");
    scanf("%d", &index);
    if(index < 0 || index > n)
    {
        printf("Invalid indaex = %d\n", index);
        printf("Count = %d, MAX_SIZE = %d\n", n, ARR_MAX_SZ);
        return 2;
    }

    int elem;
    printf("Enter element to be inserted: ");
    scanf("%d", &elem);

    for(int i = n - 1; i >= index; --i)
    {
        arr[i + 1] = arr[i];

    }
    arr[index] = elem;
    ++n;

    printf("New Array: \n");
    for(int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}