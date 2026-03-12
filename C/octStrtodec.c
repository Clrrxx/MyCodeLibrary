#include <stdio.h>
int octStrTodec(char *str);
int main(){
    char str[20],*sp;
    int num;

    printf("Enter an octal number: \n");
    scanf("%s",str);
    num=octStrTodec(str);
    printf("octStrTodec(): %d\n",num);
    return 0;
}
int octStrTodec(char *str){
 /* Write your code here */
    int sum = 0, multiplier = 1;
    int len = 0;

    /* bloody annoying cant use atoi, or strcpy to iterate literally have to manually go thru*/
    while (str[len]!='\0'){
        len++;
    }
    
    //build the multiplier
    for (int i = 1; i<len; i++){
        multiplier *= 8;
    }

    //str[i] - '0' gives the int counterpart
    for (int i = 0; i<len; i++){
        int digit = str[i] - '0';
        sum += multiplier*digit;
        multiplier /= 8;
    }
    return sum;
}