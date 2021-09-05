#include <stdio.h>
#include "matrix_functions.h"

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
   
    MATRIX_create_rand(matrix);

    printf("Original Matrix:\n");
    MATRIX_print(matrix);

    MATRIX_90_degree_cw_rotate(matrix);

    printf("\n90 Degree Rotated Matrix:\n");  
    MATRIX_print(matrix);

    return 0;
}