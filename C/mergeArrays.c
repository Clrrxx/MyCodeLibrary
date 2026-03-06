#include <stdio.h>
#define M 80

int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2);

int main(){
    int a[M],b[M],c[M],i,k=0,n1,n2;
    
    printf("Enter the size of array a: \n");
    scanf("%d", &n1);
    
    printf("Enter the size of array b: \n");
    scanf("%d", &n2);
    
    printf("Enter array a[%d]: \n", n1);
    for (i=0; i<n1; i++)
        scanf("%d",&a[i]);
    
    printf("Enter array b[%d]: \n", n2);
    
    for (i=0; i<n2; i++)
        scanf("%d",&b[i]);
    
    k=mergeArrays(a,b,c,n1,n2);
    printf("mergeArrays(): \n");
    
    for (i=0;i<k;i++)
        printf("%d ",c[i]);
    return 0;
}

int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2){
 /* Write code here */
    int total = n1 + n2;
    int point1 = 0, point2 = 0;
    int index = 0;
    
    for (int i = 0; i<total; i++){
        if (a[point1] < b[point2]){
            c[index] = a[point1];
            index++;
            point1++;

        }else{
            c[index] = b[point2];
            index++;
            point2++;
        }
    }
    return total;
} 
