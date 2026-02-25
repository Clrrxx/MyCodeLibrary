#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *sweepSpace1(char *str);
char *sweepSpace2(char *str);
int main(){
    char str[80],str2[80], *p;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);

    if (p=strchr(str,'\n')) *p = '\0';
        strcpy(str2,str);
        printf("sweepSpace1(): %s\n", sweepSpace1(str));
        printf("sweepSpace2(): %s\n", sweepSpace2(str2));
    return 0;
}

char *sweepSpace1(char *str){
/* Write your program code here */
    int count = 0;
    int length = strlen(str);
    for (int i = 0; i<length; i++){
        if (isgraph(str[i])){
            str[count] = str[i];
            count++;
        }
    }
    str[count] = '\0';
    return str;
}

char *sweepSpace2(char *str){
/* Write your program code here */
    int temp = 0;
    int len = strlen(str);
    for (int i = 0; i<len; i++){
        if (isgraph(*(str+i))){
            *(str+temp) = *(str+i);
            temp++;
        }
    }
    *(str+temp) = '\0';
    return str;
}