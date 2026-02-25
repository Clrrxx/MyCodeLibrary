#include <stdio.h>
int main(){
    char choice; int n1, n2, result; 
    printf("Enter your choice (A, S or M)=> ");
    scanf("%c", &choice);
    printf("Enter 2 numbers: ");
    scanf("%d %d", &n1, &n2);

    switch(choice){
        case 'a':
        case 'A': result = n1 + n2;
            printf("Result is %d", result);
            break;
        case 's':
        case 'S': result = n1 - n2;
            printf("Result is %d", result);
            break;
        case 'M':
        case 'm': result = n1*n2;
            printf("Result is %d", result);
            break;
        default:
            printf("No proper choice was selected.\n");
    return 0;
    }
}