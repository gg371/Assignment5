/**
 * @author Andrea McGrane and Gracyn Green
 * @date 11-24-2019
 * this program takes an input file that is formatted in CSV that is then read and converted to be formatted in JSON
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CSVtoJSON {

	public static void main(String[] args) {
		File input = new File(args[0]);
		File output = new File(args[1]);

		Scanner s;
		try {
			PrintWriter pw = new PrintWriter(output);
			s = new Scanner(input);

			String line = s.nextLine();
			String colNames[] = line.split(",");

			pw.println("[");

			/*
			 * this while loop will go through the file as long as it still has another line
			 * to read. Inside this loop, the String on each line is tokenized with every comma, from
			 * there the information is formatted into a JSON format.
			 */

			while (s.hasNextLine()) {
				line = s.nextLine();
				String token[] = line.split(",");

				pw.println("\t{");

				for (int i = 0; i < colNames.length; i++) {
					if (i < colNames.length - 1) {
						pw.println("\t\t\"" + colNames[i] + "\": " + "\"" + token[i] + "\",");
					} else {
						pw.println("\t\t\"" + colNames[i] + "\": " + "\"" + token[i] + "\"");
					}
				}

				if (!s.hasNextLine()) {
					pw.println("\t}");
				} else {
					pw.println("\t},");
				}

			}

			pw.println("]");

			s.close();
			pw.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

}