#include <stdio.h>
#define N 20
int main(){
    int a[N],i,j,k,m;
    int size, hold;
    int temp[N];

    /* Write your code here – for additional local variables */

    printf("Enter array size: \n");
    scanf("%d",&size);

    printf("Enter %d data: \n", size);

    for (i=0; i<size; i++)
        scanf("%d", &a[i]);

    printf("Result: \n");
    
    
    for (int i = 0; i<size; i++){
        //before start of any iteration, first save the last val of the array in hold and reassign to temp array's first
        hold = a[size-1];
        temp[0] = hold;


        //inside loop handles shifting all the chars down by 1
        for (int j = 0; j<size-1; j++){
            temp[j+1] = a[j];
        }

        //over here in temp this becomes 4123 from 1234
        //print out the vals

        for (int k=0; k< size; k++){
            printf("%d", temp[k]);
        }

        //then use another for loop to reassign all the values in temp array to original array saving the first iteration
        for (int k= 0; k<size;k++){
            a[k] = temp[k];
        }

        //then the loop can proceed
        printf("\n");
    }




    /* Write your code here */
    return 0;
} 
