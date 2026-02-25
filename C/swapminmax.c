#include <stdio.h>
void swapMinMax1D(int ar[], int size);

int main(){
    int ar[50],i,size;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)  
       scanf("%d",ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++)  
        printf("%d ",*(ar+i));  
    return 0;
}
void swapMinMax1D(int ar[], int size){
  /* Write your code here */
    int min = ar[0];
    int lastmin = 0, lastmax = 0;
    int max = ar[0];
    for (int i=0; i<size;i++){
        if (min > ar[i]){
            min = ar[i];
            lastmin = i;
        } else if (min == ar[i]){
            lastmin = i;
        } else if (max < ar[i]){
            max = ar[i];
            lastmax = i;
        } else if (max == ar[i]){
            lastmax = i;
        }
    }
    
    int j = ar[lastmin];
    ar[lastmin] = ar[lastmax];
    ar[lastmax] = j;
}