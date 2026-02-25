#include <stdio.h>
#include <string.h>

int main(){
    int arr[100];
    int count = 0; int lines = 0; int sum = 0; double average = 0.0;

    printf("Enter the number of lines: ");
    scanf("%d", &lines);


    //Enter number of lines needed for the outer loop
    for (int i =0; i < lines; i++){

        //reinitializing count and sum back to zero so that further loops do not carry forward previous count and sum values
        count = 0;
        sum = 0;

        printf("Enter the numbers (-1 to end): ");

        //while count is less that a certain number, it will loop thru continously scanning each value ignoring the whitespace
        //also checking each value if it is -1 to break the loop
        //while this is happening count increases by 1 allowing us to count each int scanned
        //at the same time it is putting it into an int array for easier usuage later 

        while (count <100 && scanf("%d", &arr[count]) == 1 && arr[count] != -1){
            count++;
        }

        //loop through the number of values scanned and add each from the array into a seperate sum

        for (int j = 0; j < count; j++){
            sum += arr[j];
        }

        //calculate average
        average = (double) sum/count;
        printf("Average = %.2lf\n", average);
    }
    return 0;

}