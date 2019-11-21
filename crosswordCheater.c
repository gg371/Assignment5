#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *str = argv[1];
    int charCount = 0;
    int stringLength = strlen(str);

    FILE *dictionary = fopen("/usr/share/dict/american", "r");
    char line[100];

    char *word = fgets(line, 100, dictionary);


    while(word != NULL){

      int j;
      for(j = strlen(word) - 1; j >= 0; j--){
        if(word[j] == ' ' || word[j] == '\n' || word[j] == '\t'){
            word[j] = '\0';
        }
      }

      if(strlen(word) == stringLength){

        int i;
        for(i = 0; i < stringLength; i++){
          if(str[i] == '-' || str[i] == word[i]){
            charCount++;
          }
          else{
            charCount = 0;
            break;
          }
        }

        if(charCount == stringLength){
          printf("%s\n", word);
        }

      }

      word = fgets(line, 100, dictionary);
    }

    fclose(dictionary);

    // char *wo = "fool";
    // if(strcmp(wo, "fool") == 0){
    //   printf("%s\n", wo);
    // }
}
