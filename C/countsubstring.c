#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1

int countSubstring(char str[], char substr[]);

int main(){
    char str[80], substr[80], *p;
    int result=INIT_VALUE;

    printf("Enter the string: \n");
    fgets(str, 80, stdin);
    
    if (p=strchr(str,'\n')) *p = '\0';
    
    printf("Enter the substring: \n");
    fgets(substr, 80, stdin);
    
    if (p=strchr(substr,'\n')) *p = '\0';
    
    result = countSubstring(str, substr);
    printf("countSubstring(): %d\n", result);
    
    return 0;
}

int countSubstring(char str[], char substr[]){
 /* Write your code here */
    int length = strlen(substr);
    if (*str == '\0'){
        return 0;
    }else{

        /*goated method of using recursion, conceptual mistake that need to take note strcmp returns 0 on match
        so the idea here is we're going to compare the str with substr but only to the length of the substr
        if it matches, add one to count and then advance the str by substr len, if not we advance by 1, this covers
        the cases where its babcabcabc and abc*/

        if (strncmp(str, substr, length) == 0){
            return 1 + countSubstring(str + length, substr);
        }else{
            return countSubstring(str+1, substr);
        }
    }
} 