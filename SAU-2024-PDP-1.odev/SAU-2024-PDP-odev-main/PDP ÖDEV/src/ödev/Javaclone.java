/**
*
* @author bedirhan baltık bedirhan.baltik@ogr.sakarya.edu.tr 
* @since 04.04.2024
* <p>
* Sınıfım github klon klasöründen .java uzantılı dosyalarının istediğimiz klasöre klonluyor.
* </p>
*/

package ödev;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Javaclone {
	
	public void JavaClon(String sourceDirectoryPath, String targetDirectoryPath) {
       
		// `.java` dosyalarını aramak için findAndCopyJavaFiles fonksiyonunu çağırma
        findAndCopyJavaFiles(new File(sourceDirectoryPath), new File(targetDirectoryPath));
    }

    public static void findAndCopyJavaFiles(File sourceDirectory, File targetDirectory) {
        // Dizindeki dosyaları al
        File[] files = sourceDirectory.listFiles();

        // Dosyaları kontrol et
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    // Eğer dosya bir dizinse, bu dizindeki dosyaları kontrol et
                    findAndCopyJavaFiles(file, targetDirectory);
                } else if (file.getName().endsWith(".java")) {
                    // Eğer dosya .java uzantılıysa, hedef klasöre kopyala
                    copyFile(file, targetDirectory);
                }
            }
        }
    }

    public static void copyFile(File sourceFile, File targetDirectory) {
        Path sourcePath = sourceFile.toPath();
        Path targetPath = Paths.get(targetDirectory.getAbsolutePath(), sourceFile.getName());

        try {
            Files.copy(sourcePath, targetPath);
            //   System.out.println("Dosya kopyalandı: " + sourcePath + " -> " + targetPath);
        } catch (IOException e) {
            System.out.println("Dosya kopyalanırken bir hata oluştu: " + e.getMessage());
        }
    }

}
