#include <stdio.h>
#define SIZE 10

void reduceMatrix2D(int arr[][SIZE], int rowSize, int colSize);
void printmatrix(int arr[][SIZE], int rowSize, int colSize);

int main(){
    int rowSize, colSize;
    int array[SIZE][SIZE];

    printf("Enter row size: ");
    scanf("%d", &rowSize);

    printf("Enter col size: ");
    scanf("%d", &colSize);

    //build matrix
    for (int i = 0; i < rowSize; i++){
        for (int j = 0; j < colSize; j++){
            printf("Enter array element: ");    
            scanf("%d", &array[i][j]);
        }
    }
    printf("original matrix: \n");
    printmatrix(array, rowSize, colSize);

    reduceMatrix2D(array, rowSize, colSize);

    printf("New matrix: \n");
    printmatrix(array, rowSize, colSize);
    
    return 0;
}

void reduceMatrix2D(int arr[][SIZE], int rowSize, int colSize){
    int i, j;

    for (j=0; j<colSize;j++){
        for (i=0; i<rowSize;i++){
            if (i>j){
                arr[j][j] += arr[i][j];
                arr[i][j] = 0;
            }
        }
    }
}

void printmatrix(int arr[][SIZE], int rowSize, int colSize){
    for (int i=0; i<rowSize; i++){
        for (int j=0; j<colSize; j++){
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}