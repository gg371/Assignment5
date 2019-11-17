
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
//
//	    public static String formatPhoneNumber(String phone) {
//	    }
//
//	    public static int getFileSize(String fileName) {
//	    }
//
//	    public static String getFileContents(String fileName) {
//	    }
}
