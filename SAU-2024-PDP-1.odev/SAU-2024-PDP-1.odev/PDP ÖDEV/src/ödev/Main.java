
/**
*
* @author bedirhan baltık bedirhan.baltik@ogr.sakarya.edu.tr 
* @since 04.04.2024
* <p>
* Sınıfım github klon klasöründen .java uzantılı dosyalarının istediğimiz klasöre klonluyor.
* </p>
*/

package ödev;

import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner scanner = new Scanner(System.in);

		 	// Kullanıcıdan GitHub depo URL'sini alma
		 	System.out.println("Lütfen GitHub deposunun URL'sini girin:");
			 String repoUrl = scanner.nextLine();
       
		 	//Github deposunu klonlanacağı klasör dizinini kullanıcıdan aldım  
	        System.out.println("Lütfen GitHub deposu klonlamak istediğiniz klasör dizini giriniz:");
	        String gitlocation =scanner.nextLine();
	        
	      //Github deposunundan klonlanacak java dosyaları için klasör dizinini kullanıcıdan aldım.
	        System.out.println("Lütfen .Java uzantılı dosyaları klonlamak istediğiniz klasör dizini giriniz:");
	        String javalocation = scanner.nextLine();


		GithubClone github =new GithubClone();
		Javaclone javaclon=new Javaclone();
		JavaClassFind javaclass=new JavaClassFind();
		Regex regex=new Regex();
		github.GithubClon(repoUrl,gitlocation);
		javaclon.JavaClon(gitlocation,javalocation);
		javaclass.Classfilefind(javalocation);
	    System.out.println("----------------------------------------------");
		regex.fileread(javalocation);
		
	
	}

}