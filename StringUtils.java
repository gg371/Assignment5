
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

//	    public static String scrubHTML(String s) {
//	    }
//
//	    public static String smartScrubHTML(String s) {
//	    }
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
