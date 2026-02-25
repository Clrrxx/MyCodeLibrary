#include <stdio.h>
#include <math.h>

void inputXY(double *x1, double *y1, double *x2, double *y2);
void outputResult(double dist);
double calDistance1(double x1, double y1, double x2, double y2);
void calDistance2(double x1, double y1, double x2, double y2, double *dist);

int main(){
    double x1, y1, x2, y2, distance=-1;

    inputXY(&x1, &y1, &x2, &y2); // call by reference
    distance = calDistance1(x1, y1, x2, y2); // call by value
    printf("calDistance1(): ");
    outputResult(distance);
    calDistance2(x1, y1, x2, y2, &distance); // call by reference
    printf("calDistance2(): ");
    outputResult(distance); // call by value
    return 0;
}


void inputXY(double *x1, double *y1, double *x2, double *y2){
/* Write your code here */
    printf("Input x1 y1 x2 y2: \n");
    scanf("%lf %lf %lf %lf", x1, y1, x2, y2);
    //since the variables are already declared as pointers there is no need to use & to store the values

}


void outputResult(double dist){
/* Write your code here */
    printf("%.2lf\n", dist);
}


double calDistance1(double x1, double y1, double x2, double y2){
/* Write your code here */
    double sox = (x2 - x1);
    double soy = (y2 - y1);

    double result = sqrt(sox*sox + soy*soy);
    return result;
}


void calDistance2(double x1, double y1, double x2, double y2,double *dist){
/* Write your code here */
    double sox = (x2 - x1);
    double soy = (y2 - y1);

    double result = sqrt(sox*sox + soy*soy);
    *dist = result;
}