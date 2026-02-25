#include <stdio.h>
int reverseDigits(int num);
int main()
{
   int num, result=999;
   printf("Enter a number: \n");
   scanf("%d", &num);      
   printf("reverseDigits(): %d\n", reverseDigits(num));
   return 0;
}
int reverseDigits(int num)
{
    int reversed = 0;
    while (num > 0){
        int lastdi = 0;
        lastdi = num%10;
        reversed = reversed * 10 + lastdi; 
        num /= 10;
    }
    return reversed;
}