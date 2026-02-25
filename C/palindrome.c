#include <stdio.h>
#include <string.h>
#include <ctype.h>
void palindrome(char *eword, char *PLword);
int main(){
    char eword[80];
    char PLword[80];
    
    printf("Enter your English word: \n");
    fgets(eword, 80, stdin);
    

    palindrome(eword, PLword);

    return 0;
}


void palindrome(char *eword, char *PLword){
 /* Write your code here */
    int len = strlen(eword);
    for (int i = 0; i<len; i++){
        PLword[i] = eword[len-i-1];
    }
    toupper(PLword);
    toupper(eword);

    
    
    
}