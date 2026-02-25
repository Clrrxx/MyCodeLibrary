#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main(){
    char a[80],b[80];
    char ch, *p;

    printf("Enter a string: \n");
    fgets(a, 80, stdin);
    if (p=strchr(a,'\n')) *p = '\0';
        printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}

void insertChar(char *str1, char *str2, char ch){
 /* Write your code here */
    int len = strlen(str1);
    int j = 0;
    for (int i = 0; i<len; i++){

        //build new array in str2, when str1 index == 3, insert ch, then continue building
        if (i % 3 == 0 && i != 0){
            str2[j++] = ch;
        }
        str2[j++] = str1[i];
    }
    //for cases where index is the last char in str2 insert at the end
    if (len%3 == 0){
        str2[j++] = ch;
    }
    str2[j] = '\0';
}