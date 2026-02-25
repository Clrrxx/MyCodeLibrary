#include <stdio.h>
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999

void printNames(char nameptr[][80], int size);
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80], int size);

int main(){
    char nameptr[SIZE][80], t[40], *p;
    int size, result = INIT_VALUE;
    int choice;

    printf("Select one of the following options: \n");
    printf("1: readNames()\n");
    printf("2: findTarget()\n");
    printf("3: printNames()\n");
    printf("4: exit()\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readNames(nameptr, &size);
                break;
            case 2:
                printf("Enter target name: \n");
                scanf("\n");
                fgets(t, 80, stdin);

                if (p=strchr(t,'\n')) *p = '\0';
                    result = findTarget(t, nameptr, size);
                    printf("findTarget(): %d\n", result);
                break;

            case 3:
                printNames(nameptr, size);
                break;
        }
    } while (choice < 4);
    return 0;
}
void printNames(char nameptr[][80], int size){
    int i;
    for (i=0; i<size; i++){
        printf("%s ", nameptr[i]);
    }
    printf("\n");
}

void readNames(char nameptr[][80], int *size){
/* Write your code here */
    printf("Enter the size: \n");
    scanf("%d", size);

    //put individual names into a ragged array
    printf("Enter %d names: \n", *size);
    for (int j = 0; j < *size; j++){
        scanf("%s", nameptr[j]);
    }
}

int findTarget(char *target, char nameptr[][80], int size){
/* Write your code here */

    //using a for loop, iterate thru the whole array, nameptr[i] will contain the addresses of all the names
    //ragged array
    //that way when we call string compare to compare the pointer address which will result us in the entire name
    //if it gives the name we just return the count of i when it hits

    for (int i = 0; i < size; i++){
        if ((strcmp(nameptr[i], target) == 0)){
            return i;
        }
    }
    return -1;
}