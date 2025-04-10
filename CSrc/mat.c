#include <stdio.h>

#define MAT_MAX_DIMENSION 256

int main(void)
{
    float matA[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], matB[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION];
    float matProd[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION] = {{0}}; //zeroing the memory

    //input
    int rowA, colA;
    printf("Enter the dimensions of matrix A: ");
    scanf("%d%d", &rowA, &colA);

    if(rowA <= 0 || colA <= 0 || rowA > MAT_MAX_DIMENSION || colA > MAT_MAX_DIMENSION)
    {
        printf("Invalid Dimensions: %d x %d\n", rowA, colA);
        return 1;
    }



    printf("Enter A (%d x %d): \n", rowA, colA);
    for(int i = 0; i < rowA; ++i)
        for(int j = 0; j < colA; ++j)
            scanf("%f", &matA[i][j]);
    
    int rowB, colB;
    printf("Enter the dimensions of matrix B: ");
    scanf("%d%d", &rowB, &colB);
    if(rowB <= 0 || colB <= 0 || rowB > MAT_MAX_DIMENSION || colB > MAT_MAX_DIMENSION)
    {
        printf("Invalid Dimensions: %d x %d\n", rowB, colB);
        return 1;
    }

    if(colB != rowA)
    {
        printf("Invalid dimmensions for matrix multiplication\n");
        printf("%d x %d,  %d x %d\n", rowA, colA, rowB, colB);
        return 2;
    }


    printf("Enter B (%d x %d): \n", rowB, colB);

    for(int i = 0; i < rowB; ++i)
        for(int j = 0; j < colB; ++j)
            scanf("%f", &matB[i][j]);



    //A X B
    for(int i = 0; i < rowA; ++i)
        for(int j = 0; j < colB; ++j)
            for(int k = 0; k < colA; ++k)
                matProd[i][j] += matA[i][k] * matB[k][j]; //matProd has already beem zeroed
    

    //printing
    printf("A X B: \n");
    for(int i = 0; i < rowA; ++i)
    {
        for(int j = 0; j < colB; ++j)
        {
            printf("%9.3f", matProd[i][j]);
        }
        putchar(0xa);//newline
    }
}