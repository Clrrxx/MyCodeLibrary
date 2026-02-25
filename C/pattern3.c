#include <stdio.h>
int height;

int main(){
    printf("Enter the height: ");
    scanf("%d", &height);
    char str[100] = "123456789012345678901234567890";

    for (int i = 0; i < height; i++){
        printf("%d", i+1);
        for (int j = 0; j<i; j++){
                printf("%c", str[i+j+1]);
            }
        
        printf("\n");
    }
    return 0;
}