#include <stdio.h>
#define MAX_SIZE 10 // max size for matrix dimensions
void inputMatrix(int (*matrix)[MAX_SIZE], int rows, int
cols) {
printf("enter elements for the %d by %d matrix: \n",
rows, cols);
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("Element [%d][%d]: ", i, j);
scanf("%d", *(matrix + i) + j);
}
}
}
void multiplyMatrices(int (*mat1)[MAX_SIZE], int
(*mat2)[MAX_SIZE], int(*result)[MAX_SIZE], int rows1, int
cols1, int cols2) {
//initialize the matrix to 0 using pointer arithmetic
for (int i = 0; i < rows1; i++) {
for (int j = 0; j < cols2; j++) {
*(result[i] + j) = 0; //Correct pointer access initialize to 0
for (int k = 0; k < cols2; k++) {
*(result[i] + j) += *(mat1[i] +k)*
*(mat2[k] + j); //matrix multiplication
}
}
}
}
void printMatrix(int (*matrix)[MAX_SIZE], int rows, int
cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", *(*(matrix + i) + j));
}
printf("\n");
}
}
int main() {int rows1, cols1, rows2, cols2;
printf("Enter rows and columns for the first matrix:");
scanf("%d%d", &rows1, &cols1);
printf("Enter rows and columns for the second matrix:");
scanf("%d%d", &rows2, &cols2);
int mat1[rows1][MAX_SIZE], mat2[rows2][MAX_SIZE],
result[rows1][cols2];
inputMatrix(mat1, rows1, cols1);
inputMatrix(mat2, rows2, cols2);
multiplyMatrices(mat1, mat2, result, rows1, cols1,
cols2);
printf("Result Matrix: \n");
printMatrix(result, rows1, cols2);
return 0;
}