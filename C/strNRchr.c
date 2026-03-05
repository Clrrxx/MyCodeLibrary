#include <stdio.h>
#include <string.h>

char *strNRChr(char *str, int n, char ch);

int main(){
    char str[80], ch, dummy;
    char *temp=NULL;
    int n;
    
    printf("Enter a string: \n");
    scanf("%s",str);
    scanf("%c",&dummy);
    
    printf("Enter a char: \n");
    scanf("%c",&ch);
    
    printf("Enter the occurrence: \n");
    scanf("%d", &n);
    
    temp = strNRChr(str, n, ch);
    
    if (temp!=NULL)
        printf("strNRChr(): %s\n", temp);
    else
        printf("strNRChr(): null string\n");
    return 0;
}

char *strNRChr(char *str, int n, char ch){
/* Write your code here */
    int length = strlen(str);
    int count = 0;
    int index = 0;

    for(int i = 0; i < length; i++){
        if (str[i] == ch){
            count++;
        }if (count == n+1){
            break;
        }
        index ++;
    }
    if (index == length){
        return str = NULL; 
    }
    return str = str + index;
} 