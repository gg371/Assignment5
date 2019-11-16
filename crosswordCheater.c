#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *str = argv[1];
    int hyphenCount = 0;
    int charCount = 0;
    int stringLength = strlen(str);

    for(int i = 0; i < stringLength; i++){
      if(str[i] == '-'){
        hyphenCount++;
      }
    }

    FILE *dictionary = fopen("/usr/share/dict/american.txt", "r");
    char line[100];

    char *word = fgets(line, 100, dictionary);
    
    while(word != NULL){
      for(int i = 0; i < stringLength; i++){
        if(word[i] == str[i] || str[i] == '-'){
          charCount++;
        }
      }
      if(charCount == stringLength){
        printf("%s\n", word);
      }
      word = fgets(line, 100, dictionary);
    }

}
