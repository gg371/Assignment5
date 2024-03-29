/*
* Authors: Gracyn Green and Andrea McGrane
* Date: 11/24/2019
* This function takes a partially completed word and lists all the words that
* could possibly be the word.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//this function trims trailing and leading whitespace
void trim(char *str){
  int stringLength = strlen(str);
  int countLeadingSpaces = 0;
  int countTrailingSpaces = 0;

  int i;
  //count leading whitespace
  for(i = 0; i < stringLength; i++){
    if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
      countLeadingSpaces++;
    }
    else{
      break;
    }
  }

  int j;
  //count trailing whitespace
  for(j = stringLength - 1; j >= 0; j--){
    if(str[j] == ' ' || str[j] == '\n' || str[j] == '\t'){
      countTrailingSpaces++;
    }
    else{
      break;
    }
  }

  int newLength = stringLength - (countLeadingSpaces + countTrailingSpaces);

  int k;
  for(k = 0; k < newLength; k++){
    str[k] = str[k + countLeadingSpaces];
  }

  str[newLength] = '\0';
}

//returns 0 if the word is the same, and -1 if it isn't
int isSame(char *newWord, char *str){
  int j = 0;
  int count = 0;

  while(newWord[j] == str[j] || str[j] == '-'){
    if(j == strlen(str)){
      return 0;
    }
    j++;
    count++;
  }

  return -1;
}

int main(int argc, char **argv){
    char *str = argv[1];
    int stringLength = strlen(str);

    FILE *dictionary = fopen("/usr/share/dict/american", "r");
    char line[100];

    char *word = fgets(line, 100, dictionary);

    //the while loop will stop when there are no more words to compare
    while(word != NULL){
      trim(word);

      /*
      * will print out the word if it is the same length of the string, and has
      * all the letters and hyphens in the right spaces 
      */
      if(strlen(word) == stringLength){
        if(isSame(word, str) == 0){
            printf("%s\n", word);
        }
      }

      word = fgets(line, 100, dictionary);
    }

    fclose(dictionary);
}
