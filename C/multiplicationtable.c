#include <stdio.h>

int main(){
    int value;

    printf("Enter a number (between 1 and 9): \n");
    scanf("%d", &value);

    //printing multiplication table
    printf("Multiplication Table:  \n");
    for (int i=0; i < value; i++){
        printf(" %d", i+1);
    }
    printf("\n");

    int sum = 0;
    for (int k = 0; k < value; k++){
        printf("%d", k+1);
        for (int j = 0; j < k+1; j++){
            sum = (k+1)*(j+1);
            printf(" %d", sum);
        }
        printf("\n");
    }
    return 0;
}