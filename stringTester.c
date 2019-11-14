#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_utils.h"
int main(int argc, char **argv) {
  int n = 100;
  char *str = (char*) malloc(n * sizeof(char));
  str = "&Hello>";
  char *newStr = (char*) malloc(n * sizeof(char));
  newStr = scrubHTML(str);
  printf("%s\n", newStr);

  str = "&Hello&amp;"
  newStr = smartScrubHTML(str);
  printf("%s\n", newStr);

}
