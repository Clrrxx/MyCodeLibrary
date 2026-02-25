#include <stdio.h>
#include <math.h>
int checker(int, int, int, int);


int main(){
    int a, b, c, d, e, f, deno;
    double x, y;

    printf("Enter the values for a1, b1, c1, a2, b2, c2: ");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    deno = checker(a, e, d, b);

    x = ((e*c)-(b*f))/deno;
    y = ((a*f)-(d*c))/deno;

    printf("x = %.2f and y = %.2f", x, y);

    return 0;
}

int checker(int var1,int var2,int var3,int var4){
    int sum;
    sum = (var1*var2)-(var3*var4);
    if (sum <= 0){
        printf("Unable to compute because the denominator is zero!\n");
    } else{
        return sum;
    }
}
