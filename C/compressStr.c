#include <stdio.h>
#include <string.h>
#include <ctype.h>

void compressStr(char *str);

int main(){
    char str[40];

    printf("Enter a sequence of characters: \n");
    scanf("%s", str);
    printf("compressStr(): ");
    compressStr(str);
    return 0;
}

void compressStr(char *str){
/* Write your code here */
    do{
        int count = 1;
        int length = strlen(str);
        

        for (int i = 0; i<length; i++){
            if (str[i] == str[i+1]){
                count ++;
            }else{
                break;
            }
        }
        if (count > 1){
            printf("[%d%c]", count, str[0]);
            str = str + count; 
        }else{
            printf("%c", str[0]);
            str = str + 1;
        }
    }while(*str != '\0');
}