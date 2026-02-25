#include <stdio.h>
#include <math.h>

void readIn(int *nums);
void calculateFin(int *nums, int *result);

int main(){
    int nums, result;

    readIn(&nums);
    calculateFin(&nums, &result);

    printf("The equivalent decimal number: %d", result);
    return 0;
}

void readIn(int * nums){
    printf("Enter a binary number: \n");
    scanf("%d", nums);
}

void calculateFin(int *nums, int *result){
    int lastdi;
    int count = 0; 
    int sum = 0;
    
    while (*nums > 0){
        lastdi = *nums % 10;
        if (lastdi == 1){
            sum = pow(2, count) + sum;
        }else{
            sum += 0;
        }
        count++;
        *nums /= 10;
    }
    *result = sum;
}