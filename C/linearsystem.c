#include <stdio.h>
#include <math.h>

int main (){
    int h, i, j, k ,l ,m;
    double numx, numy, deno, x, y;
    printf("Enter a1,b1,c1,a2,b2,c2: ");
    scanf("%d %d %d %d %d %d", &h, &i, &j, &k, &l, &m);

    deno = h*l - k*i;
    if (deno > 0 || deno < 0){
        numx = l*j - i*m;
        numy = h*m - k*j;

        x = numx / deno;
        y = numy / deno;

        printf("x=%.2lf,y=%.2lf", x, y);
    } else {
        printf("Denominator is zero!");
    }
    return 0;
}
