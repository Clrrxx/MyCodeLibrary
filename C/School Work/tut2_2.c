#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
 int number, result = INIT_VALUE;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("extOddDigits1(): %d\n", extOddDigits1(number));
 extOddDigits2(number, &result);
 printf("extOddDigits2(): %d\n", result);
 return 0;
}
int extOddDigits1(int num)
{
 /* Write your code here */
    int sol = 0;
    int multi = 1;

    while (num>0){
        int val = num%10;
        if (val%2 != 0){
            sol += val*multi;
            multi *= 10;        //incrementing by 10
        }
        num /= 10;
        
    }
    if (sol == 0){
            return -1;
    }
    return sol;
    
}

void extOddDigits2(int num, int *result)
{
 /* Write your code here */
    int sol = 0;
    int multi = 1;
    *result = -1;
    while (num > 0){
        int val = num%10;   //find rightmost digit
        if (val % 2 == 1){
            sol += val * multi;
            multi *= 10;
            *result = sol;
        }
        num /= 10;
    }
    
}