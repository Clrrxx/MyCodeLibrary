#include <stdio.h>
#include <string.h>
void strIntersect(char *str1, char *str2, char *str3);
int main(){
    char str1[50],str2[50],str3[50];

    printf("Enter str1: \n");
    scanf("%s",str1);

    printf("Enter str2: \n");
    scanf("%s",str2);

    strIntersect(str1, str2, str3);

    if (*str3 == '\0')
        printf("strIntersect(): null string\n");
    else
        printf("strIntersect(): %s\n", str3);
    return 0;
}
void strIntersect(char *str1, char *str2, char *str3){
 /* Write your code here */
    int tempmax = 0, tempmin = 0, truemax = 0, truemin = 0;
    tempmax = strlen(str1);
    tempmin = strlen(str2);
    if (tempmin > tempmax){
        truemin = tempmax;
        truemax = tempmin;
    }else{
        truemax = tempmax;
        truemin = tempmin;
    }
    str3[0] = '\0';
    int k = 0;
    for (int i = 0; i< truemin; i++){
        for (int j = 0; j<truemax; j++){
            if (str2[i] == str1[j]){
                str3[k] = str2[i];
                k++;
            }
        } 
    }
    str3[k++] = '\0';
} 