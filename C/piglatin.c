#include <stdio.h>
#include <string.h>
void PigLatin(char *eword, char *PLword);
int main(){
    char eword[80];
    char PLword[80];

    printf("Enter your English word: \n");
    scanf("%s", eword);

    PigLatin(eword, PLword);

    printf("PigLatin(): %s\n", PLword);
    return 0;
}


void PigLatin(char *eword, char *PLword){
 /* Write your code here */
    char vowels[20] = "aeiouyAEIOUY";
    char ay[10] = "ay";
    int len = strlen(eword);
    int count = 0;

    if (strchr(vowels, eword[0])){
        strcpy(PLword, eword);
        strcat(PLword, ay);
    }else{
        for (int i = 0; i<len; i++){
            if (!(strchr(vowels, eword[i]))){
                count++;
            } else {
                break;
            }
        }
        for (int i=0; i<len-count; i++){
            PLword[i] = eword[count+i];
        }
        PLword[len-count] = '\0';
        eword[count] = '\0';
        strcat(PLword, eword);
        strcat(PLword, ay);
        
    }
    
}