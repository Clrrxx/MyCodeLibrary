#include <stdio.h>

int main(){
    static int height;
    int i, j;

    printf("Enter your height: ");
    scanf("%d", &height);

    for (i=0; i<height; i++){
        for (j=0; j<=i; j++){
            switch (i%3){
                case 0: printf("1"); break;
                case 1: printf("2"); break;
                case 2: printf("3"); break;
            }
        }
        printf("\n");

    }
    return 0;
}