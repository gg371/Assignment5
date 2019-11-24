/**
* Authors: Gracyn and Andrea
* Date: 11/24/19
* These methods trim strings, escapes special characters, escapes special characters unless
* they are already escaped, formats a string representing a telephone number, computes the
* size of file in bytes, and prints the contents of a file given the file name as a string.
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class StringUtils {
	 	public static String trim(String s) {
	 		String tempStr = "";
	 		int countLeadingSpaces = 0;
	 		int countTrailingSpaces = 0;
	 		
	 		//count leading whitespace
	 		for(int i = 0; i < s.length(); i++) {
	 			if(s.charAt(i) == ' ' || s.charAt(i) == '\n' || s.charAt(i) == '\t') {
	 				countLeadingSpaces++;
	 			}
	 			else {
	 				break;
	 			}
	 		}
	 		
	 		//count trailing whitespace
	 		for(int i = s.length() - 1; i >= 0; i--) {
	 			if(s.charAt(i) == ' ' || s.charAt(i) == '\n' || s.charAt(i) == '\t') {
	 				countTrailingSpaces++;
	 			}
	 			else {
	 				break;
	 			}
	 		}
	 		
	 		int newLength = s.length() - (countLeadingSpaces + countTrailingSpaces);
	 		
	 		//makes the trimmed string with only the characters before and after the whitespace
	 		for(int k = 0; k < newLength; k++) {
	 			tempStr += s.charAt(k + countLeadingSpaces);
	 		}
	 		
	 		return tempStr;
	    }

	    public static String scrubHTML(String s) {
	    	//returns NULL if the string passed into the function is NULL
	    	if(s == null) {
	    		return null;
	    	}
	    	
	    	String escapedString = "";
	    	
	    	/*
	    	* this for loop goes through the passed in string and finds where the
	    	* special characters are an then replaces them with the escaped characters
	    	* versions of them
	    	*/
	    	for(int i = 0; i < s.length(); i++) {
	    		if(s.charAt(i) == '&') {
	    			escapedString += "&amp;";
	    		}
	    		else if(s.charAt(i) == '<') {
	    			escapedString += "&lt;";
	    		}
	    		else if(s.charAt(i) == '>') {
	    			escapedString += "&gt;";
	    		}
	    		else if(s.charAt(i) == '"') {
	    			escapedString += "&quot;";
	    		}
	    		else {
		    		escapedString += s.charAt(i);
		    		
	    		}
	    	}
	    	
	    	return escapedString;
	    }

	    public static String smartScrubHTML(String s) {
	    	//returns NULL if the string passed into the function is NULL
	    	if(s == null) {
	    		return null;
	    	}
	    	
	    	String escapedString = "";
	    	
	    	/*
	    	* this for loop goes through the string passed into the function to look for
	    	* the special characters if there is a special character it will be changed the escaped version.
	    	* If the escaped version of one of the special characters is in the string,
	    	* it will stay like that.
	    	*/
	    	
	    	for(int i = 0; i < s.length(); i++) {
	    		if(s.charAt(i) == '&') {
	    			if(s.charAt(i+1) == 'l' && s.charAt(i+2) == 't' && s.charAt(i+3) == ';') {
	    				escapedString += "&";
	    			}
	    			else if(s.charAt(i+1) == 'g' && s.charAt(i+2) == 't' && s.charAt(i+3) == ';') {
	    				escapedString += "&";
	    			}
	    			else if(s.charAt(i+1) == 'a' && s.charAt(i+2) == 'm' && s.charAt(i+3) == 'p' && s.charAt(i+4) == ';') {
	    				escapedString += "&";
	    			}
	    			else if(s.charAt(i+1) == 'q' && s.charAt(i+2) == 'u' && s.charAt(i+3) == 'o' && s.charAt(i+4) == 't' && s.charAt(i+5) == ';') {
	    				escapedString += "&";
	    			}
	    			else {
	    				escapedString += "&amp;";
	    			}
	    		}
	    		else if(s.charAt(i) == '<') {
	    			escapedString += "&lt;";
	    		}
	    		else if(s.charAt(i) == '>') {
	    			escapedString += "&gt;";
	    		}
	    		else if(s.charAt(i) == '"') {
	    			escapedString += "&quot;";
	    		}
	    		else {
		    		escapedString += s.charAt(i);
	    		}
	    	}
	    	
	    	return escapedString;
	    }

	    public static String formatPhoneNumber(String phone) {
	    	String formatedNumber = "";
	    	String allNumbers = "";
	    	
	    	//only adds the numbers to the new string
	    	for(int j = 0; j < phone.length(); j++) {
	    		if(phone.charAt(j) >= '0' && phone.charAt(j) <= '9') {
	    			allNumbers += phone.charAt(j);
	    		}
	    	}
	    	
	    	if(allNumbers.length() < 10 || allNumbers.length() > 11) {
	    		return null;
	    	}
	    	
	    	/*
	    	* for numbers like 1-402-555-1234 it gets rid of the one in front
	    	* and moves all the numbers down an index
	    	*/
	    	if(allNumbers.length() == 11) {
	    		String tempString = "";
	    		for(int k = 0; k < allNumbers.length() - 1; k++) { 
	    			tempString += allNumbers.charAt(k + 1);
	    		}
	    		allNumbers = tempString;
	    	}
	    	
	    	int index = 0;
	    	int formatedNumberLen = 14;
	    	
	    	//formats the number in the specified format of (###) ###-####
	    	for(int i = 0; i < formatedNumberLen; i++) {
	    		if(i == 0) {
	    			formatedNumber += '(';
	    		}
	    		else if(i < 4){
    		      formatedNumber += allNumbers.charAt(index);
    		      index++;
    		    }
    		    else if(i == 4){
    		      formatedNumber += ')';
    		    }
    		    else if(i == 5){
    		      formatedNumber += ' ';
    		    }
    		    else if(i < 9){
    		      formatedNumber += allNumbers.charAt(index);
    		      index++;
    		    }
    		    else if(i == 9){
    		      formatedNumber += '-';
    		    }
    		    else if(i < 14){
    		      formatedNumber += allNumbers.charAt(index);
    		      index++;
    		    }
	    	}
	    	
	    	return formatedNumber;
	    }

	    public static int getFileSize(String fileName) {
	    	int sumBytes = 0;
	    	int lineCount = 0;
	    	
	    	File f = new File(fileName);
	    	
	    	Scanner s;
			try {
				s = new Scanner(f);
				String line = s.nextLine();
				sumBytes += (line.length());
		    	
				//goes through the entire file and reads it character by character to count the number of bytes in the file
		    	while(s.hasNextLine()) {
		    		lineCount++;
		    		line = s.nextLine();
		    		sumBytes += (line.length());
		    	}
		    	sumBytes += lineCount;
		 
		    	s.close();
		    	
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
	    	
	    	return sumBytes;
	    }

	    public static String getFileContents(String fileName) {
	    	String str = "";
	    	
	    	File f = new File(fileName);
	    	
	    	Scanner s;
	    	try {
	    		s = new Scanner(f);
	    		String line = s.nextLine();
	    		str += line + "\n";
	    		
	    		//goes through the entire file and reads it line by line then adds its contents to a string
	    		while(s.hasNextLine()) {
	    			line = s.nextLine();
	    			
	    			if(s.hasNextLine()) {
	    				str += line + "\n";
	    			}
	    			else {
	    				str += line;
	    			}
	    		}
	    		
	    		s.close();
	    		
	    	} catch (FileNotFoundException e) {
	    		e.printStackTrace();
	    	}
	    	
	    	return str;
	    }
}
