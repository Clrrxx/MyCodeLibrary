#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int i = 0;
    int length, alpha, numer = 0;
  
    char str[100];
    printf("Enter your characters (# to end): ");
    fgets(str, 100, stdin);
    length = strlen(str);

    //logic checking each char if char is alpha +1 to apha count, if digit +1 to numer count
    while (i < length && str[i] != '#'){
        char c = str[i];

        if (isalpha(c)){
            alpha++;
        }
        else if (isdigit(c)){
            numer++;
        }

        i++;
    }
    printf("The number of digits: %d\n", numer);
    printf("The number of letters: %d\n", alpha);
    return 0;
}






