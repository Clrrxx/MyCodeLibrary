#include <stdio.h>

int main(){
    int lines, val;
    int loop = 0;

    printf("Enter number of lines: \n");
    scanf("%d", &lines);
    //main for loop
    for (int i=0; i<lines; i++){
        printf("Enter line %d:  \n", i+1);
        scanf("%d", &loop);
        int sum = 0;

        for (int k=0; k<loop; k++){
            scanf("%d", &val);
            sum += val;
        }
        printf("Total: %d\n", sum);
    }
    return 0;
}