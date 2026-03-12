#include <stdio.h>

int main(){
    int height;

    printf("Enter the height: \n");
    scanf("%d", &height);

    printf("The pattern is: \n");
    for (int i=0; i<height;i++){
        for (int j=height; j>i; j--){
            printf(" ");
        }
        for (int k=0; k<=i;k++){
            printf("*");
        }
        for (int b=0; b<i;b++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/* break down into 2 separate loops
first one prints an inverted traingle with another triangle
then the next triangle would be delayed by 1 step
*/