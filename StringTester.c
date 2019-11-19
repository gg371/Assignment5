/**
* Author: Gracyn and Andrea
* Date: 11/12/19
* This class tests the functions defined in string_utils.c
*/
#include <stdlib.h>
#include <stdio.h>

#include "string_utils.h"

int main(int argc, char **argv){
  char *str = "< 3 I ate & chicken";

  char *newStr = scrubHTML(str);
  printf("%s\n", newStr);

  char *str2 = "  hi  ";
  char *str3 = "lo";
  printf("%s%s\n", str2, str3);
  trim(str2);

  char *phone = "+402-555-1234";
  char *newPhone = formatPhoneNumber(phone);
  printf("%s\n", newPhone);

  int sum = getFileSize("/home/ugrad/ggreen/Assignment 5/Temp.txt");
  printf("%d\n", sum);

  char *contents = (char *) malloc(sizeof(char) * 1000);
  contents = getFileContents("/home/ugrad/ggreen/Assignment 5/Temp.txt");
  printf("%s\n", contents);

}
