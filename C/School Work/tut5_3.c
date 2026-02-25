#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
char name[20];
int telno;
} PhoneBk;

void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);

int main(){
    PhoneBk s[MAX];
    char t[20], *p;
    int size=0, choice;
    char dummychar;

    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: printPB()\n");
    printf("4: exit()\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%c", &dummychar);
                size = readin(s);
                break;

            case 2:
                scanf("%c", &dummychar);

                printf("Enter search name: \n");
                fgets(t, 20, stdin);

                if (p=strchr(t,'\n')) *p = '\0';
                    search(s,size,t);
                    break;

            case 3:
                printPB(s, size);
            break;
            }
        } while (choice < 4);
    return 0;
}

void printPB(PhoneBk *pb, int size){
/* Write your code here */
    int j = 0;
    if (size == 0){
        printf("Empty Phonebook");
    } else {
        for (j; j<size; j++){
            printf("Name: %s, Telno: %d\n", pb[j].name, pb[j].telno);
        }
    }
}

int readin(PhoneBk *pb){
/* Write your code here */
    int i = 0;
    char *p, dummy[80];

    printf("Enter name: \n");
    gets(pb[i].name);
        
    while (strcmp(pb[i].name, "#") != 0){
        
        
        printf("Enter tel: \n");
        scanf("%d", &pb[i].telno);

        scanf("%c", dummy);
        i++;

        printf("Enter name: \n");
        gets(pb[i].name);
    }
    return i;
}

void search(PhoneBk *pb, int size, char *target){
/* Write your code here */
    int i = 0;

    for (i; i<size; i++){
        if (strcmp(pb[i].name, target) == 0){
            printf("Name = %s, Tel = %d\n", pb[i].name, pb[i].telno);
            break;
        }
        printf("Name not found\n");
    }
    
}