/**
* Author: Gracyn and Andrea
* Date: 11/12/19
* These are the code for the functions defined in string_utils.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

char * scrubHTML(const char *str){
  if(str == NULL){
    return NULL;
  }
  int stringLength = strlen(str);
  //this for loop goes through the passed in string and stringLengths the number of times
  //one of the special characters shows up to calculate the extra amount of memory needed for the
  //length of the new string.
  int i = 0;
  for(i = 0; i < stringLength; i++){
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
  i = 0;
  for(i = 0; i < stringLength; i++){
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
  if(str == NULL){
    return NULL;
  }
  int stringLength = strlen(str);
  //this for loop goes through the passed in string and stringLengths the number of times
  //one of the special characters shows up to calculate the extra amount of memory needed for the
  //length of the new string.
  char testString[7];
  int newStringLength = 0;
  int i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] == '&'){


      if(str[i + 1] == 'l' && str[i + 2] == 't' && str[i + 3] == ';'){
        newStringLength = newStringLength + 4;
        i = i + 4;
      }
      else if(str[i + 1] == 'g' && str[i + 2] == 't' && str[i + 3] == ';'){
        newStringLength = newStringLength + 4;
        i = i + 4;
      }
      else if(str[i + 1] == 'a' && str[i + 2] == 'm' && str[i + 3] == 'p' && str[i + 4] == ';'){
        newStringLength = newStringLength + 5;
        i = i + 4;
      }
      else if(str[i + 1] == 'q' && str[i + 2] == 'u' && str[i + 3] == 'o' && str[i + 4] == 't' && str[i + 5] == ';'){
        newStringLength = newStringLength + 6;
        i = i + 6;
      }
      else{
        newStringLength = newStringLength + 5;
      }
    }
    else if(str[i] == '<' || str[i] == '>'){
      newStringLength = newStringLength + 4;
    }
    else if(str[i] == '"'){
      newStringLength = newStringLength + 5;
    }
    else{
      newStringLength++;
    }
  }
  char *escapedArray = (char *) malloc((newStringLength + 1) * sizeof(char));
  int index = 0;

  i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      if(str[i + 1] == 'l' && str[i + 2] == 't' && str[i + 3] == ';'){

        escapedArray[index] = '&';
        escapedArray[index + 1] = 'l';
        escapedArray[index + 2] = 't';
        escapedArray[index + 3] = ';';
        i = i + 3;
        index = index + 4;
      }
      else if(str[i + 1] == 'g' && str[i + 2] == 't' && str[i + 3] == ';'){

        escapedArray[index] = '&';
        escapedArray[index + 1] = 'g';
        escapedArray[index + 2] = 't';
        escapedArray[index + 3] = ';';
        i = i + 3;

        index = index + 4;
      }
      else if(str[i + 1] == 'a' && str[i + 2] == 'm' && str[i + 3] == 'p' && str[i + 4] == ';'){
        escapedArray[index] = '&';
        escapedArray[index + 1] = 'a';
        escapedArray[index + 2] = 'm';
        escapedArray[index + 3] = 'p';
        escapedArray[index + 4] = ';';
        i = i + 4;
        index = index + 5;
      }
      else if(str[i + 1] == 'q' && str[i + 2] == 'u' && str[i + 3] == 'o' && str[i + 4] == 't' && str[i + 5] == ';'){

        escapedArray[index] = '&';
        escapedArray[index + 1] = 'q';
        escapedArray[index + 2] = 'u';
        escapedArray[index + 3] = 'o';
        escapedArray[index + 4] = 't';
        escapedArray[index + 5] = ';';
        i = i + 5;

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
  escapedArray[newStringLength + 1] = '\0';
  return escapedArray;

}

void trim(char *str){
  int stringLength = strlen(str);
  char *tempStr = (char *) malloc(sizeof(char) * (stringLength + 1));
  int index = 0;

  int i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] != ' '){
      tempStr[index] = str[i];
      index++;
    }
  }
  str = tempStr;
}

char * formatPhoneNumber(const char *phone){
  int stringLength = strlen(phone);
  int formatedNumLen = 15; //14 + 1
  char *formatedNumber = (char *) malloc(formatedNumLen * sizeof(char));

  char *allNums = (char *) malloc(sizeof(char) * stringLength);
  int index = 0;
  int j = 0;
  for(j = 0; j < stringLength; j++){
    if(phone[j] >= '0' && phone[j] <= '9'){
      allNums[index] = phone[j];
      index++;
    }
  }

  if(strlen(allNums) < 10 || strlen(allNums) > 11){
    return NULL;
  }
  //for numbers like 1-402-555-1234
  //get rid of the one in front and move all the numbers down an index
  int k = 0;
  if(strlen(allNums) == 11){
    for(k = 0; k < stringLength; k++){
      allNums[k] = allNums[k+1];
    }
  }

  index = 0;
  int i = 0;
  for(i = 0; i < formatedNumLen; i++){
    if(i == 0){
      formatedNumber[0] = '(';
    }
    else if(i < 4){
      formatedNumber[i] = allNums[index];
      index++;
    }
    else if(i == 4){
      formatedNumber[i] = ')';
    }
    else if(i == 5){
      formatedNumber[i] = ' ';
    }
    else if(i < 9){
      formatedNumber[i] = allNums[index];
      index++;
    }
    else if(i == 9){
      formatedNumber[i] = '-';
    }
    else if(i < 14){
      formatedNumber[i] = allNums[index];
      index++;
    }
    else if(i == 14){
      formatedNumber[i] = '\0';
    }
  }

  return formatedNumber;
}

int getFileSize(const char *fileName){
  int sumBytes = 0;
  FILE *f = fopen(fileName, "r");

  if(f == NULL){
    return -1;
  }

  char c = fgetc(f);

  while(!feof(f)){
    sumBytes++;
    c = fgetc(f);
  }

  fclose(f);
  return sumBytes;
}

char * getFileContents(const char *fileName){
  char line[1000];
  FILE *f = fopen(fileName, "r");

  if(f == NULL){
    return NULL;
  }

  long sizeOfFile = 0;
  if(f){
    fseek(f, 0, SEEK_END);
    sizeOfFile = ftell(f);
    fseek(f, 0, SEEK_SET);
  }

  char *newString = (char *) malloc(sizeOfFile);
  int index = 0;
  int i;

  char * str = fgets(line, 1000, f);
  while(str != NULL){
    for(i = 0; i < strlen(str); i++){
      newString[index] = str[i];
      index++;
    }
    str = fgets(line, 1000, f);
  }

  fclose(f);
  return newString;
}
