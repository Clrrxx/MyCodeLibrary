#include <stdio.h>
int height;


int main(){
    printf("Enter the height: ");
    scanf("%d", &height);

    for (int i = 0; i <= height; i++){
        for (int j = 0; j < height - i; j++){
            printf(" ");
        }
        for (int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;

}