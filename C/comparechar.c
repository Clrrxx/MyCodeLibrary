#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char target;
    printf("Enter a character: ");
    scanf("%c", &target);
    char lower[100] = "abcdefghijklmnopqrstuvwxyz";
    int count = strlen(lower);


    if (isdigit(target)){
        printf("Digit");
        
    } else if (isalpha(target)){
        for (int i = 0; i < count; i++){
            if (lower[i] == target){
                printf("Lower case letter");
                break;
            } else{
                printf("Upper case letter");
                break;
            }
        }
    } else {
        printf("Other character");
    }
    return 0;
}