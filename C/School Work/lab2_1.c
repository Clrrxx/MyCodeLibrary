#include <stdio.h>
int square1(int nums);
void square2(int nums, int *result);

int main(){
    int number, result = 0;

    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Result is: %d\n", square1(number));
    square2(number, &result);
    printf("Result is: %d", result);
    return 0;
}

int square1(int nums){
    int result = 0;
    for (int i = 0; i < nums; i++){
        result += i*2 + 1;
    }
    return result;
}

void square2(int nums, int *result){
    int value = 0;
    for (int i = 0; i < nums; i++){
        value += i*2 + 1;
    }
    *result = value;
}
