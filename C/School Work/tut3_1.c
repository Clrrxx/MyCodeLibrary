#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readIn(int *num);
void printhist(int *result, int count);


int main(){
    int num;
    readIn(&num);

    srand(time(NULL));
    int arr[num];
    int result[10] = {0};
    
    
    for (int i = 0; i < num; i++){
        arr[i] = rand() % 100;
    }

    for (int j = 0; j<10; j++){
        for (int k =0; k < num; k++){
            if (j == arr[k]/10){
                result[j]++;
            }
        }
    }
    printf("\n");
    printhist(result, 10);


    return 0;
}
// tbh i get the logic behind the whole thing, but i dont understand the pointer system manz

// initialize an array with random values, then using a for loop, compare with (for eg.) 0th element
// of the array divided by 10 to give us the 10s range. if the 0th element is equal to what j's current value is (0) we add one to
// another array to store the value of how many times it occurs


void readIn(int *num){
    printf("Enter: \n");
    scanf("%d", num);
}

void printhist(int *result, int count){
    int i, j;
    for (i =0; i<count; i++){
        printf("%2d - %2d    |", i*10, i*10+9);
        for (j = 0; j< result[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}

