/**
* Authors: Gracyn and Andrea
* Date: 11/24/19
* These are the code for the functions defined in string_utils.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "string_utils.h"

char * scrubHTML(const char *str){
  //returns NULL if the string passed into the function is NULL
  if(str == NULL){
    return NULL;
  }

  int stringLength = strlen(str);
  int newStringLength = stringLength;

  /*
  * this for loop goes through the passed in string and stringLengths the number of times
  * one of the special characters shows up to calculate the extra amount of memory needed for the
  * length of the new string.
  */
  int i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      newStringLength += 4;
    }
    else if(str[i] == '<' || str[i] == '>'){
      newStringLength += 3;
    }
    else if(str[i] == '"'){
       newStringLength += 5;
    }
  }

  char *escapedArray = (char *) malloc((newStringLength + 1) * sizeof(char));
  escapedArray[0] = '\0';
  int index = 0;

  /*
  * this for loop goes through the passed in string and finds where the
  * special characters are an then replaces them with the escaped charcters
  * versions of them
  */

  i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      escapedArray = strcat(escapedArray, "&amp;");
      index += 5;
      escapedArray[index] = '\0';
    }
    else if(str[i] == '<'){
      escapedArray = strcat(escapedArray, "&lt;");
      index += 4;
      escapedArray[index] = '\0';
    }
    else if(str[i] == '>'){
      escapedArray = strcat(escapedArray, "&gt;");
      index += 4;
      escapedArray[index] = '\0';
    }
    else if(str[i] == '"'){
      escapedArray = strcat(escapedArray, "&quot;");
      index += 6;
      escapedArray[index] = '\0';
    }
    else{
      escapedArray[index] = str[i];
      index++;
      escapedArray[index] = '\0';
    }
  }
  escapedArray[index] = '\0';
  return escapedArray;
}

char * smartScrubHTML(const char *str){
  //returns NULL if the string passed into the function is NULL
  if(str == NULL){
    return NULL;
  }

  int stringLength = strlen(str);
  char *escapedArray = (char *) malloc(((stringLength * 6)) * sizeof(char));
  escapedArray[0] = '\0';

  /*
  * this for loop goes through the string passed into the function to look for
  * the special characters if there is a special character it will be changed the escaped version.
  * If the escaped version of one of the special characters is in the string,
  * it will stay like that.
  */

  int index = 0;
  int i = 0;
  for(i = 0; i < stringLength; i++){
    if(str[i] == '&'){
      if(str[i + 1] == 'l' && str[i + 2] == 't' && str[i + 3] == ';'){
        escapedArray = strcat(escapedArray, "&lt;");
        i += 3;
        index += 4;
        escapedArray[index] = '\0';
      }
      else if(str[i + 1] == 'g' && str[i + 2] == 't' && str[i + 3] == ';'){
        escapedArray = strcat(escapedArray, "&gt;");
        i += 3;
        index += 4;
      }
      else if(str[i + 1] == 'a' && str[i + 2] == 'm' && str[i + 3] == 'p' && str[i + 4] == ';'){
        escapedArray = strcat(escapedArray, "&amp;");
        i += 4;
        index += 5;
        escapedArray[index] = '\0';
      }
      else if(str[i + 1] == 'q' && str[i + 2] == 'u' && str[i + 3] == 'o' && str[i + 4] == 't' && str[i + 5] == ';'){
        escapedArray = strcat(escapedArray, "&quot;");
        i += 5;
        index += 6;
        escapedArray[index] = '\0';
      }
      else{
        escapedArray = strcat(escapedArray, "&amp;");
        index += 5;
        escapedArray[index] = '\0';
      }
    }
    else if(str[i] == '<'){
      escapedArray = strcat(escapedArray, "&lt;");
      index += 4;
      escapedArray[index] = '\0';
    }
    else if(str[i] == '>'){
      escapedArray = strcat(escapedArray, "&gt;");
      index += 4;
      escapedArray[index] = '\0';
    }
    else if(str[i] == '"'){
      escapedArray = strcat(escapedArray, "&quot;");
      index += 6;
      escapedArray[index] = '\0';
    }
    else{
      escapedArray[index] = str[i];
      index++;
      escapedArray[index] = '\0';
    }
  }

  int newStringLength = strlen(escapedArray);
  escapedArray[index] = '\0';
  return escapedArray;
}

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
  //overrides the original string to have no leading or trailing whitespace
  for(k = 0; k < newLength; k++){
    str[k] = str[k + countLeadingSpaces];
  }

  str[newLength] = '\0';
}

char * formatPhoneNumber(const char *phone){
  //returns NULL if the string given to the function is NULL
  if(phone == NULL){
    return NULL;
  }

  int stringLength = strlen(phone);
  int formatedNumLen = 15;
  char *formatedNumber = (char *) malloc(formatedNumLen * sizeof(char));

  char *allNums = (char *) malloc(sizeof(char) * stringLength + 1);
  int index = 0;
  int j = 0;
  for(j = 0; j < stringLength; j++){
    if(phone[j] >= '0' && phone[j] <= '9'){
      allNums[index] = phone[j];
      index++;
    }
  }
  allNums[index] = '\0';

  if(allNums == NULL){
    return NULL;
  }

  if(strlen(allNums) < 10 || strlen(allNums) > 11){
    return NULL;
  }

  /*
  * for numbers like 1-402-555-1234 it gets rid of the one in front
  * and moves all the numbers down an index
  */
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

  //returns -1 if the file is NULL, becuase normally a file couldn't have -1 bytes
  if(f == NULL){
    return -1;
  }

  char c = fgetc(f);

  //goes through the entire file and reads it character by character to count the number of bytes in the file
  while(c != EOF){
    sumBytes++;
    c = fgetc(f);
  }

  fclose(f);
  return sumBytes;
}

char * getFileContents(const char *fileName){
  FILE *f = fopen(fileName, "r");
  char line[sizeof(*f)];

  //returns NULL if the file is NULL
  if(f == NULL){
    return NULL;
  }

  int fileSize = getFileSize(fileName);

  char *newString = (char *) malloc(fileSize + 1);
  int index = 0;
  int i;

  char *str = fgets(line, fileSize, f);
  //goes through the entire file and reads it line by line then adds its contents to a string
  while(str != NULL){
    for(i = 0; i < strlen(str); i++){
      newString[index] = str[i];
      index++;
    }
    str = fgets(line, fileSize, f);
  }

  newString[fileSize] = '\0';

  fclose(f);
  return newString;
}
