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
        //if start with vowels, just add ay to the end

    }else{
        for (int i = 0; i<len; i++){
            if (!(strchr(vowels, eword[i]))){
                count++;
                //find how many consonants before a vowel

            } else {
                //once it hits a vowel break
                break;
            }
        }

        for (int i=0; i<len-count; i++){
            PLword[i] = eword[count+i];
            //create newword without the consonats at the start
        }
        
        PLword[len-count] = '\0';
        eword[count] = '\0';
        
        //strcat Plword with the consonants to the back
        //then strcat again with ay
        strcat(PLword, eword);
        strcat(PLword, ay);
        
    }
}