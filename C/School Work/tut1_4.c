#include <stdio.h>

int main(){
    double sol = 0.0, x = 0;
    printf("Enter the value: ");
    scanf("%lf", &x);
    double deno = 1.0, nume = 1.0;

    for (int i = 0; i<10; i++){
        //every loop that occurs, numerator multiplies by the value of x which is equivalent to x^n
        //same can be said for denominator since 2! is 2*1 which is (1+1)*1 => (i+1)*1
        //since we start deno at 1.0, all we have to do is add 1 to it to maintain the logic

        sol += nume/deno;
        nume *= x;
        deno *= i +1;
        
    }


    printf("The result is %.2lf", sol);
    return 0;
}

