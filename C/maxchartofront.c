#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()  {
   char str[80], *p;
    
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';  
   printf("maxCharToFront(): ");   
   maxCharToFront(str);  
   puts(str);
   return 0;
}
void maxCharToFront(char *str){
   /* Write your code here */
    int len = strlen(str);
    char max = str[0];

    for (int i = 0; i<len; i++){
        if (max<str[i]){
            max = str[i];
        }
    }
    char *result = strchr(str, max);
    int index = *result - *str;
    char new[80];

    new[0] = max;
    
    for (int i = 0; i<len; i++){
        if (i == index){
            continue;
        }
        new[i+1] = str[i];
    }
    strcpy(str, new);
}