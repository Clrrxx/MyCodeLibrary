#include <stdio.h>
int max3 (int, int, int);
int max2 (int, int);

int main(){
    int x, y, z;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("The max of these 3 numbers is %d.\n", max3(x, y, z));
    return 0;
}

int max3(int a, int b, int c){
    printf("Finding the max of these 3 numbers (%d, %d, %d)\n", a, b, c);
    return max2(max2(a, b), max2(b, c));
}

int max2(int e, int f){
    return e>f ? e:f;
}