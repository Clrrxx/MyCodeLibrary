#include <stdio.h>
#include <math.h>

void readIn(int *num);
void calculate(int *num, int *result);
int main(){
    int num, result;
    readIn(&num);
    calculate(&num, &result);

    printf("The equivalent binary number: %d", result);
    return 0;
}

void readIn(int *num){
    printf("Enter a decimal number: \n");
    scanf("%d", num);
}

void calculate(int *num, int *result){
    int val = 0, remainder = 0;
    int multiplier = 1;
    while (*num > 0){
        val = *num%2;
        remainder = multiplier*val + remainder;
        multiplier *= 10;
        
        *num/=2;
    }
    *result = remainder;
}