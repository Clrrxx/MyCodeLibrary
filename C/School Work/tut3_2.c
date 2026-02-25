#include <stdio.h>
#define SIZE 10

void transpose2D(int ar[][SIZE], int rowSize, int colSize);
void printmatri(int ar[][SIZE], int rowSize, int colSize);

int main(){
    int rowSize, colSize;
    int array[SIZE][SIZE];

    printf("Enter row size: ");
    scanf("%d", &rowSize);

    printf("Enter column size: ");
    scanf("%d", &colSize);

    //building matrix

    for(int i =0; i<rowSize; i++){
        for (int j =0; j<colSize; j++){
            printf("Enter value to be inserted in matrix: ");
            scanf("%d", &array[i][j]);
        }
    }

    printf("Original matrix: \n");
    printmatri(array, rowSize, colSize);

    transpose2D(array, rowSize, colSize);

    printf("Transposed matrix: \n");
    printmatri(array, rowSize, colSize);
    return 0;

}

void printmatri(int ar[][SIZE], int rowSize, int colSize){
    for (int i = 0; i<rowSize; i++){
        for (int j = 0; j< colSize; j++){
            printf(" %d ", ar[i][j]);
        }
        printf("\n");
    }
    
}

void transpose2D(int ar[][SIZE], int rowSize, int colSize){
    for (int row = 0; row <rowSize; row++){
        for (int col = row+1; col<colSize;col++){
            
            //eg for row = 0 -> col = 1
            int temp = ar[row][col];

            //row = 0 & col = 1 will swap with col = 1 and row = 0 which is what we want 
            ar[row][col] = ar[col][row];

            //continue until we finish
            ar[col][row] = temp;
        }
    }
}