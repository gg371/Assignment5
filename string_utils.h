/**
* Authors: Gracyn and Andrea
* Date: 11/24/19
* These are the header files for string_utils.c
*/

/*
* This function takes a string and escapes the special characters by replacing
* them with their HTML entities. It returns a new string with the escaped
* characters.
*/
char * scrubHTML(const char *str);

/*
* This function escapes special characters unless they are already escaped
*/
char * smartScrubHTML(const char *str);

/*
* This function trims a string by removing leading and trailing whitespace from it
*/
 void trim(char *str);

/*
* This function creates a new string that uses the standard format of a
* phone number.
*/
char * formatPhoneNumber(const char *phone);

/*
* This function computes the size of a file in bytes
*/
int getFileSize(const char *fileName);

/*
* This function retreieves the contents of a file given the fiel name as a string
* (All data in the file including endline characters and whitespace are preserved)
*/
char * getFileContents(const char *fileName);
