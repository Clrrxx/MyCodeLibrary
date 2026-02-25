#include <stdio.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);

int main(){
    char str[50], *p;
    int totVowels, totDigits;
    printf("Enter the string: \n");
    fgets(str, 50, stdin);

    if (p=strchr(str,'\n')) *p = '\0';

    processString(str, &totVowels, &totDigits);

    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);

    return 0;
}
void processString(char *str, int *totVowels, int *totDigits){
/* Write your code here */
    char digit[15] = "0123456789";
    char vowel[15] = "AEIOUaeiou";
    *totVowels = 0, *totDigits = 0;

    int len = strlen(str);
    for (int i=0; i<len;i++){
        if (strchr(vowel, str[i])){
            *totVowels += 1;
        } else if (strchr(digit, str[i])){
            *totDigits += 1;
        }
    }
}