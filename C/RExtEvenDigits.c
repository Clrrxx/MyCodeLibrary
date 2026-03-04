#include <stdio.h>

void rExtEvenDigits(int num, int *evenPtr);

int main(){
    int number, result=0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    rExtEvenDigits(number, &result);
    printf("rExtEvenDigits(): %d\n", result);
    return 0;
}

void rExtEvenDigits(int num, int *evenPtr){
 /* Write your code here */
    int digit = num % 10;
    if (num < 10){
        if (digit % 2 == 0){
            *evenPtr = digit;
        }else{
            *evenPtr = -1;
        }
    }else{
        rExtEvenDigits(num/10, evenPtr);
        if (digit % 2 == 0){
            if (*evenPtr == -1){
                //start fresh cuz currently we hit the base case that says the most deepest level yields no even numbers
                *evenPtr = digit;
            }else{
                *evenPtr = *evenPtr * 10 + digit;
            }
        }
    }
}