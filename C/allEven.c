#include  <stdio.h>
int allEvenDigits1(int num);  
void allEvenDigits2(int num, int *result);     
int main()
{
   int number, p=999, result=999;
   printf("Enter a number: \n");
   scanf("%d", &number);
   p = allEvenDigits1(number);
   if (p == 1)
      printf("allEvenDigits1(): yes\n");
   else if (p == 0)
      printf("allEvenDigits1(): no\n");
   else  
      printf("allEvenDigits1(): error\n");
   allEvenDigits2(number, &result);
   if (result == 1)
      printf("allEvenDigits2(): yes\n");
   else if (result == 0)
      printf("allEvenDigits2(): no\n");
   else  
      printf("allEvenDigits2(): error\n");
   return 0;
}
int allEvenDigits1(int num){
    int sol = 0;
    int multi = 1;
    int temp = num;

    while (num > 0){
        int val = num % 10;
        if (val % 2 != 1){
            sol += val*multi;
            multi *= 10;
        }
        num /= 10;
    }
    if (sol == temp) //overly complicated way of checking if the number matches literally
        return 1;
    return 0;
}
void allEvenDigits2(int num, int *result){
    int sol = 0;
    int multi = 1;
    int temp = num;

    *result = 0;

    while (num > 0){
        int val = num % 10;
        if (val % 2 != 1){
            sol += val * multi;
            multi *= 10;
        }
        num /= 10;
    }
    if (sol == temp){
        *result = 1;
    }
}
