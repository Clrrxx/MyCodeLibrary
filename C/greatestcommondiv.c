#include <stdio.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
   int x,y,result= -1;       
   printf("Enter 2 numbers: \n");
   scanf("%d %d", &x, &y);
   printf("gcd1(): %d\n", gcd1(x, y));  
   gcd2(x,y,&result);
   printf("gcd2(): %d\n", result);       
   return 0;
}

int gcd1(int num1, int num2){
    int value = ((num1 < num2)? num1 : num2);
    while (value>0){
        if (num1%value == 0 && num2%value == 0){
            break;
        }
        value --;
    }
    return value;
}

void gcd2(int num1, int num2, int *result){
    int value = ((num1 < num2)? num1 : num2);
    while (value>0){
        if (num1%value == 0 && num2%value == 0){
            break;
        }
        value --;
    }
    *result = value;
}