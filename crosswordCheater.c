#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *str = argv[1];
    int hyphenCount = 0;
    int charCount = 0;
    int stringLength = strlen(str);

  //  printf("%d\n", stringLength);

    int j;
    for(j = 0; j < stringLength; j++){
      if(str[j] == '-'){
        hyphenCount++;
      }
    }

    FILE *dictionary = fopen("/usr/share/dict/american", "r");
    char line[100];

    char *word = fgets(line, 100, dictionary);

    char *tempArr = (char *) malloc(sizeof(char) * stringLength);
    int index = 0;
    int i;

    while(word != NULL){

      for(i = 0; i < stringLength; i++){
        if(str[i] == word[i]){
          charCount++;
        }
        else if(str[i] != '-' && str[i] != word[i]){
          charCount = 0;
          break;
        }

      }

      if((stringLength - (charCount + hyphenCount)) == 0 && strlen(word) == stringLength + 1){
        //printf("%d %d %d\n", charCount, hyphenCount, strlen(word));
        printf("%s\n", word);
      }

      word = fgets(line, 100, dictionary);
    }

}
