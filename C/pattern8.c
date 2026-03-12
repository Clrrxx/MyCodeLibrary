#include <stdio.h>

int main(){
    int height;

    printf("Enter the height: ");
    scanf("%d", &height);

    for (int i = 0; i<height; i++){
        for (int j = 0; j<i; j++){
            printf(" ");
        }
        for (int k = height - i; k> 0; k--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
/* inverted triangle: apply the pattern making for a regular ascending traingle but opposite
then using same constrains for height print *
*/