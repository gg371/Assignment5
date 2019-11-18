
public class StringUtils {
	 	public static String trim(String s) {
	 		String tempStr = "";
	 		
	 		for(int i = 0; i < s.length(); i++) {
	 			if(s.charAt(i) != ' ') {
	 				tempStr += s.charAt(i);
	 			}
	 		}
	 		
	 		return tempStr;
	    }

	    public static String scrubHTML(String s) {
	    	if(s == null) {
	    		return null;
	    	}
	    	String escapedString = "";
	    	
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
	    	if(s == null) {
	    		return null;
	    	}
	    	
	    	String escapedString = "";
	    	
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
	    	
	    	for(int j = 0; j < phone.length(); j++) {
	    		if(phone.charAt(j) >= '0' && phone.charAt(j) <= '9') {
	    			allNumbers += phone.charAt(j);
	    		}
	    	}
	    	
	    	if(allNumbers.length() < 10 || allNumbers.length() > 11) {
	    		return null;
	    	}
	    	
	    	if(allNumbers.length() == 11) {
	    		String tempString = "";
	    		for(int k = 0; k < allNumbers.length() - 1; k++) { 
	    			tempString += allNumbers.charAt(k + 1);
	    		}
	    		allNumbers = tempString;
	    	}
	    	
	    	int index = 0;
	    	int formatedNumberLen = 14;
	    	
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
//
//	    public static int getFileSize(String fileName) {
//	    }
//
//	    public static String getFileContents(String fileName) {
//	    }
}
