#include <stdio.h>
#include <string.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
   int number, digit, result=0;
   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);             
   printf("digitPos1(): %d\n", digitPos1(number, digit));            
   digitPos2(number, digit, &result);           
   printf("digitPos2(): %d\n", result);    
   return 0;
}
int digitPos1(int num, int digit){
    int count = 0;
    while (num > 0){
        int currdig = num % 10;
        if (currdig == digit){
            return count+1;
        }
        num /= 10;
        count++;
    }
    return 0;
}

void digitPos2(int num, int digit, int *result){
    int count = 0;
    *result = 0;
    while (num > 0){
        int curr = num%10;
        if (curr == digit){
            *result = count+1;
            break;
        }
        num /= 10;
        count++;
    }
    
}