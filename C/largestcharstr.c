#include <stdio.h>
#include <string.h>
#define N 20
void largeCharStr(char str[N][20], char a[N], int size);
int main(){
    char str[N][20],dummy;
    char a[N],i,j,size;

    printf("Enter number of strings: \n");
    scanf("%d", &size);
    scanf("%c", &dummy);

    for (i=0;i<size;i++){
        printf("Enter string %d: \n", i+1);
        scanf("%s",str[i]);
    }
    largeCharStr(str,a,size);
    
    printf("largeCharStr(): \n");
    
    for (i=0;i<size;i++) {
        printf("String %d: ",i+1);
        printf("%c\n",a[i]);
    }
    return 0;
}

void largeCharStr(char str[N][20], char a[N], int size){
 /* Write your code here */
    for (int i = 0; i<size; i++){
        char max = str[i][0];
        int len = strlen(str[i]);
        for (int j = 0; j<len; j++){
            if (str[i][j]<str[i][j+1]){
            max = str[i][j+1];
            }
        }
        a[i] = max;
    }
}