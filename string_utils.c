/**
* Author: Gracyn and Andrea
* Date: 11/12/19
* These are the code for the functions defined in string_utils.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

/*
char * scrubHTML(const char *str){
  char *newStr = (char *) malloc(sizeof(char) * strlen(str));
  strcpy(newStr, str);

  char *p = strchr(newStr, '&');
  char *q = strchr(newStr, '<');
  char *r = strchr(newStr, '>');
  char *s = strchr(newStr, '"');
  printf("%s\n", p);
  printf("%s\n", q);
  printf("%s\n", r);
  printf("%s\n", s);

  for(int i = 0; i < strlen(str); i++){

    if(p != NULL){
      p = "&amp;";

    }
    else if(q != NULL){
      q = "&lt;";

    }
    else if(r != NULL){
      r = "&gt;";

    }
    else if(s != NULL){
      s = "&quot;";

    }

  }

  return newStr;
}
*/
char * scrubHTML(const char *str){
  int stringLength = strlen(str);
  //this for loop goes through the passed in string and stringLengths the number of times
  //one of the special characters shows up to calculate the extra amount of memory needed for the
  //length of the new string.
  for(int i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      stringLength = stringLength + 4;
    }
    else if(str[i] == '<' || str[i] == '>'){
      stringLength = stringLength + 3;
    }
    else if(str[i] == '"'){
      stringLength = stringLength + 5;
    }
  }
  char *escapedArray = (char *) malloc((stringLength + 1) * sizeof(char));
  int index = 0;

  //this for loop goes through the passed in string and finds where the special characters are an then replaces
  //them with the escaped charcters versions of them
  for(int i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'a';
      escapedArray[index + 2] = 'm';
      escapedArray[index + 3] = 'p';
      escapedArray[index + 4] = ';';
      index = index + 5;
    }
    else if(str[i] == '<'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'l';
      escapedArray[index + 2] = 't';
      escapedArray[index + 3] = ';';
      index = index + 4;
    }
    else if(str[i] == '>'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'g';
      escapedArray[index + 2] = 't';
      escapedArray[index + 3] = ';';
      index = index + 4;
    }
    else if(str[i] == '"'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'q';
      escapedArray[index + 2] = 'u';
      escapedArray[index + 3] = 'o';
      escapedArray[index + 4] = 't';
      escapedArray[index + 5] = ';';
      index = index + 6;
    }
    else{
      escapedArray[index] = str[i];
      index++;
    }
  }
  escapedArray[stringLength] = '\0';
  return escapedArray;

}

char * smartScrubHTML(const char *str){
  int stringLength = strlen(str);
  //this for loop goes through the passed in string and stringLengths the number of times
  //one of the special characters shows up to calculate the extra amount of memory needed for the
  //length of the new string.
  char testString[7];
  for(int i = 0; i < stringLength; i++){
    if(str[i] == '&'){


      if(0 == strcmp(strncpy(testString, &str[i], 4), "&lt;")){
        stringLength = stringLength;
      }
      else if(0 == strcmp(strncpy(testString, &str[i], 4), "&gt;")){
        stringLength = stringLength;
      }
      else if(0 == strcmp(strncpy(testString, &str[i], 5), "&amp;")){
        stringLength = stringLength;
      }
      else if(0 == strcmp(strncpy(testString, &str[i], 6), "&quot;")){
        stringLength = stringLength;
      }
      else{
        stringLength = stringLength + 4;
      }
    }
    else if(str[i] == '<' || str[i] == '>'){
      stringLength = stringLength + 3;
    }
    else if(str[i] == '"'){
      stringLength = stringLength + 5;
    }
  }

  char *escapedArray = (char *) malloc((stringLength + 1) * sizeof(char));
  int index = 0;

  for(int i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      if(0 == strcmp(strncpy(testString, &str[i], 4), "&lt;")){
        index = index + 4;
      }
      else if(0 ==strcmp(strncpy(testString, &str[i], 4), "&gt;")){
        index = index + 4;
      }
      else if(0 == strcmp(strncpy(testString, &str[i], 5), "&amp;")){
        index = index + 5;
      }
      else if(0 == strcmp(strncpy(testString, &str[i], 6), "&quot;")){
        index = index + 6;
      }
      else{
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'a';
      escapedArray[index + 2] = 'm';
      escapedArray[index + 3] = 'p';
      escapedArray[index + 4] = ';';
      index = index + 5;
      }
    }
    else if(str[i] == '<'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'l';
      escapedArray[index + 2] = 't';
      escapedArray[index + 3] = ';';
      index = index + 4;
    }
    else if(str[i] == '>'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'g';
      escapedArray[index + 2] = 't';
      escapedArray[index + 3] = ';';
      index = index + 4;
    }
    else if(str[i] == '"'){
      escapedArray[index] = '&';
      escapedArray[index + 1] = 'q';
      escapedArray[index + 2] = 'u';
      escapedArray[index + 3] = 'o';
      escapedArray[index + 4] = 't';
      escapedArray[index + 5] = ';';
      index = index + 6;
    }
    else{
      escapedArray[index] = str[i];
      index++;
    }
  }
  escapedArray[stringLength] = '\0';
  return escapedArray;

}

void trim(char *str){
  int stringLength = strlen(str);
  char *tempStr = (char *) malloc(sizeof(char) * (stringLength + 1));
  int index = 0;

  for(int i = 0; i < stringLength; i++){
    if(str[i] != ' '){
      tempStr[index] = str[i];
      index++;
    }
  }
  str = tempStr;
}
/*
char * formatPhoneNumber(const char *phone){
  int stringLength = strlen(phone);
  char *formatedNumber = (char*) malloc(14 + 1 * sizeof(char));
  formatedNumber[0] = '(';
  formatedNumber[15] = '\0';
  for(int i = 0; i < stringLength; i++){
  }
}
int getFileSize(const char *fileName){
}
char * getFileContents(const char *fileName){
}
*/
