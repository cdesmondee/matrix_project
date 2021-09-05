#ifndef MATRIX_FUNCTIONS_H_
#define MATRIX_FUNCTIONS_H_

/*MACROS*/
#define MATRIX_SIZE 4 //specifies the dimension of a square matrix
#define MATRIX_NUM_RANGE 10 //gives the following range of random numbers that can be generated: [0,MATRIX_NUM_RANGE-1]
#define ELEMENT_DISP_SIZE 1 //specifies how many digits each element of the array will be displayed with

/*FUNCTION DECLARATIONS*/


void MATRIX_create_rand(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void MATRIX_print(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void MATRIX_transpose(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void MATRIX_horizontal_mirror(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void MATRIX_90_degree_cw_rotate(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


#endif//MATRIX_FUNCTIONS_H_