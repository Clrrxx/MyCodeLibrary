#include <stdio.h>
#include <string.h>
int strOverWrite(char *s1, char *s2, int pos);
int main()
{
    char s1[40], s2[40], *p;
    int pos, total;
    printf("Enter string 1: \n");
    fgets(s1, 80, stdin);
    if (p=strchr(s1,'\n')) *p = '\0';

    printf("Enter string 2: \n");
    fgets(s2, 80, stdin);
    if (p=strchr(s2,'\n')) *p = '\0';

    printf("Enter position: \n");
    scanf("%d", &pos);

    total = strOverWrite(s1, s2, pos);
    printf("strOverWrite(): %s %d\n", s1, total);

    return 0;
}

int strOverWrite(char *s1, char *s2, int pos){
/* Write your code here */
    int len2 = strlen(s2);
    int len1 = strlen(s1);
    char temp[40];
    char rest[40];
    int len1remain = 0;
    
    if (len1 < pos + len2){
        int diff = len1 - pos - len2;
        len2 += diff;
    }else{
        len1remain = len1 - pos - len2;
    }

    strncpy(temp, s1, pos);
    temp[pos] = '\0';

    strncpy(rest, s1+pos+len2, len1remain);
    rest[len1remain] = '\0';

    strcat(temp, s2);
    strcat(temp, rest);

    strcpy(s1, temp);
    s1[len1] = '\0';
    return len2;
} 