import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CodeKata {

	private static final String FILE = "plaintext.txt";

	public static void main(String[] args) {

		List<String> allLines = getFileContents(FILE);

		System.out.println("There are " + allLines.size() + " lines");

	}

	private static List<String> getFileContents(String fileName) {
		BufferedReader br = null;
		FileReader fr = null;

		List<String> contents = new ArrayList<String>();

		try {

			fr = new FileReader(fileName);
			br = new BufferedReader(fr);

			String currentWord;

			br = new BufferedReader(new FileReader(fileName));

			while ((currentWord = br.readLine()) != null) {
				contents.add(currentWord);
			}

		} catch (IOException e) {

			e.printStackTrace();

		} finally {

			try {

				if (br != null)
					br.close();

				if (fr != null)
					fr.close();

			} catch (IOException ex) {

				ex.printStackTrace();

			}

		}
		return contents;
	}

}
