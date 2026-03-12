#include <stdio.h>
int rSumSqDigits(int num);

int main(){
    int number;
    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("rSumSqDigits(): %d\n", rSumSqDigits(number));
    return 0;
}

int rSumSqDigits(int num){
 /* Write your code here */
    if (num == 0){
        return 0;
    }else{
        int digit = num%10;

        return (digit*digit) + rSumSqDigits(num/10);
        /*let return carry the sum throught the recursion calls instead of keeping a running sum
        running sum wouldnt work here anyways since no prior declaration of running sum
        this means that if a sum var is declared it will be redeclared as 0 for each run*/
    }
}