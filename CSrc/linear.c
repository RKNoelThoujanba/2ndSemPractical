#include <stdio.h>

#define ARR_MAX_SZ 512

int main(void)
{
    int arr[ARR_MAX_SZ] = {0};
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0 || n > ARR_MAX_SZ)
    {
        printf("Invalid n = %d\n", n);
        return 1;
    }

    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter element to be searched (key): ");
    scanf("%d", &key);

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == key)
        {
            printf("Key = %d found at index = %d (element number %d)\n", key, i, i+1);
            return 0;
        }
    }

    printf("Key = %d not found\n", key);
    return 1;
}
