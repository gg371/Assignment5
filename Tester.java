import java.io.File;

public class Tester {

	public static void main(String[] args) {
		
		String s = "	bloo			";
		System.out.println(s);
		
		String newStr = StringUtils.trim(s);
		
		System.out.println(newStr);
		
		String str = "<> I ate & chicken";
		String newString = StringUtils.scrubHTML(str);
		
		System.out.println(newString);
		
		String halfScrub = "&&amp; < &lt; Hi >";
		String fullScrub = StringUtils.smartScrubHTML(halfScrub);
		
		System.out.println(fullScrub);
		
		String phone = "+402-555-1234";
		String newPhone = StringUtils.formatPhoneNumber(phone);
		
		System.out.println(newPhone);
		
		int sum = StringUtils.getFileSize("/Users/gracyngreen/eclipse-workspace/Assignment5/src/Temp.txt");
		System.out.println(sum);
		
		String contents = StringUtils.getFileContents("/Users/gracyngreen/eclipse-workspace/Assignment5/src/Temp.txt");
		System.out.println(contents);
		
	}

}
