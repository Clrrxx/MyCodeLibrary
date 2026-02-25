#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int main()
{
   char word[SIZE][40];
   char first[40], last[40];
   int i, size;  
    
   printf("Enter size: \n");
   scanf("%d", &size);
   printf("Enter %d words: \n", size);
   for (i=0; i<size; i++)
      scanf("%s", word[i]);  
   findMinMaxStr(word, first, last, size);   
   printf("First word = %s, Last word = %s\n", first, last);         
   return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size){
/* Write your code here */
    
    //strcmp if str1 > str2 returns positive, if str1 < str2 then it returns negative
    int mincount = 0, maxcount = 0;

    for (int i = 0; i< size; i++){
        if (strcmp(word[i], word[maxcount]) > 0){
            //if greater than zero that means that word[i] is more
            //using pointer comparisons instead of brute force comparing charas
            
            maxcount = i;

        } else if (strcmp(word[i], word[mincount]) < 0){
            //lesser than zero means that word[i] is smaller 
            mincount = i;
        }
    }

    //since first and last are chara arrays have to copy over into them
    strcpy(first, word[mincount]);
    strcpy(last, word[maxcount]);
}

