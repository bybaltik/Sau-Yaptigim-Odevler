/**
*
* @author bedirhan baltık bedirhan.baltik@ogr.sakarya.edu.tr 
* @since 04.04.2024
* <p>
* Sınıfım Git kullanarak github deposunu klonluyor.
* </p>
*/

package ödev;

import java.io.IOException;
import java.util.Scanner;

public class GithubClone {

	
  
	public void GithubClon(String repoUrl, String cloneDirectory){
		
	        String gitCommand = "git clone " + repoUrl + " " + cloneDirectory;
	     
	        try {
	            Process process = Runtime.getRuntime().exec(gitCommand);

	            // Git işleminin çıktısını okuma
	            Scanner gitScanner = new Scanner(process.getInputStream());
	            while (gitScanner.hasNextLine()) {
	                System.out.println(gitScanner.nextLine());
	            }

	            // İşlemi bekletme
	            process.waitFor();

	            // Çıktı kontrolü
	            if (process.exitValue() == 0) {
	               System.out.println("Depo başarıyla klonlandı.");
	            } else {
	                System.out.println("Klonlama işlemi başarısız oldu. Lütfen geçerli bir URL ve klasör yolu sağladığınızdan emin olun.");
	            }
	        } catch (IOException | InterruptedException e) {
	            e.printStackTrace();
	        } 
	}
	
}