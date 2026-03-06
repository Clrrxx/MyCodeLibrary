#include <stdio.h>
#include <math.h>
#include <string.h>
int hexStrToDec(char *hex);

int main(){
    int num;
    char hex[100];

    printf("Enter a hexadecimal number: \n");
    scanf("%s",&hex);
    num=hexStrToDec(hex);
    printf("hexStrToDec(): %d\n", num);
    return 0;
}

int hexStrToDec(char *hex){
 /* Write your code here */
    int len = strlen(hex);
    int sum = 0;
    int multiplier = 1;
    char *num = "0123456789";

    for (int i = 1; i<len; i++){
        multiplier *= 16;
    }



    do{
        char temp = hex[0];
        if (temp  >= '0' && temp <= '9'){
            sum += (temp - '0') * multiplier;
        }else{
            switch(temp){
                case 'A': sum += 10 * multiplier;
                        break;
                case 'B': sum += 11 * multiplier;
                        break;
                case 'C': sum += 12 * multiplier;
                        break;
                case 'D': sum += 13 * multiplier;
                        break;
                case 'E': sum += 14 * multiplier;
                        break;
                case 'F': sum += 15 * multiplier;
                        break;
            }
        }
        len--;
        hex = hex + 1;
        multiplier /= 16;

    }while (len > 0);
    return sum;
}