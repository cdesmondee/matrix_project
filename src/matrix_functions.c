#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_functions.h"

/*
Description: transposes a matrix of dimension MATRIX_SIZE
Input Parameters: a square integer matrix of dimension MATRIX_SIZE
Output Result: a transposed matrix of dimension MATRIX_SIZE
*/
void MATRIX_create_rand(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    time_t t;
    srand((unsigned) time(&t)); //intialize random number generator based on system time
    int rand_num;

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {   
            rand_num = rand() % MATRIX_NUM_RANGE; //modulus operators forces rand_num to be in range [0,MATRIX_NUM_RANGE-1]
            matrix[i][j]= rand_num;
        }   
    }
}

/*
Description: Prints the contents of the provided matrix (2D Array) to the console
Input Parameters:
- matrix - a square integer matrix of dimension MATRIX_SIZE
Output Result: void
*/
void MATRIX_print(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    printf("[");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if(i != 0)//aligns rows 1 to MATRIX_SIZE-1 to the first row
            printf(" ");

        for(int j = 0; j < MATRIX_SIZE; j++)
        {   
            char * format = (j==MATRIX_SIZE-1) ? "%.*d" : "%.*d,"; //last element in a row doesn't need a comma
            int current_element = matrix[i][j];

            printf(format,ELEMENT_DISP_SIZE,current_element);
        }

        if(i != MATRIX_SIZE-1)//a newline character does not follow the last element displayed
            printf("\n");
    }
    printf("]\n");
}

/*
Description: transposes a matrix of dimension MATRIX_SIZE
Input Parameters: a square integer matrix of dimension MATRIX_SIZE
Output Result: a transposed matrix of dimension MATRIX_SIZE
*/
void MATRIX_transpose(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int swap_temp;

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = i; j < MATRIX_SIZE; j++) //j=0 will cause duplicate swaps which will result in a non modified matrix
        {
            if(i!=j)//principle diagonal elements do not need to be swapped
            {
                swap_temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = swap_temp;
            }
        }
    }
}

/*
Descrption: the columns of the given matrix are mirrored

Example:
[a,b,c         [c,b,a
 e,f,g  ------> g,f,e
 h,i,j]         j,i,h]

Remark:If the MATRIX_SIZE is odd then the center column will remain unchanged. 
If the MATRIX_SIZE is even then all columns will be flipped

Input Parameters: a square integer matrix of dimension MATRIX_SIZE
Ouput Result: a horizontally mirrored matrix
*/
void MATRIX_horizontal_mirror(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int swap_temp;

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < (MATRIX_SIZE>>1);j++)
        {
            swap_temp = matrix[i][j];
            matrix[i][j] = matrix[i][MATRIX_SIZE-1-j];
            matrix[i][MATRIX_SIZE-1-j]= swap_temp;
        }
    }
}

/*
Descrption: rotates the given matrix clockwise by 90 degrees. 
This is implemented by first transposing the matrix then by mirroring the columns
Input Parameters: a square integer matrix of dimension MATRIX_SIZE
Output Result: a 90 degree clockwise rotated matrix
*/
void MATRIX_90_degree_cw_rotate(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    MATRIX_transpose(matrix);
    MATRIX_horizontal_mirror(matrix);
}