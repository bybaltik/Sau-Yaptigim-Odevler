/**
*
* @author bedirhan baltık bedirhan.baltik@ogr.sakarya.edu.tr 
* @since 04.04.2024
* <p>
* Sınıfım .java uzantılı dosyalar içinde class bulunan dosyaları buluyor ve diğer dosyaları siliyor.
* </p>
*/

package ödev;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JavaClassFind {

    public  void klasorIcerisindekiDosyalariKontrolEtVeSifirla(File klasor) {
        if (klasor.isDirectory()) {
            File[] dosyalar = klasor.listFiles();
            if (dosyalar != null) {
                for (File dosya : dosyalar) {
                    if (dosya.isFile()) {
                        dosyaIcerisindekiSinifAdlariniBulVeDosyayiSil(dosya);
                    }
                }
            }
        }
    }

    public  void dosyaIcerisindekiSinifAdlariniBulVeDosyayiSil(File dosya) {
        try {
            // Dosyayı oku
            String icerik = new String(Files.readAllBytes(Paths.get(dosya.getAbsolutePath())));

            // Regex deseni
            String regex = "class\\s+(\\w+)";

            // Desene göre eşleşmeleri bul
            Pattern desen = Pattern.compile(regex);
            Matcher eslesme = desen.matcher(icerik);

            // Eşleşme varsa, sınıf adlarını yazdır
            boolean sinifVarMi = false;
            while (eslesme.find()) {
                sinifVarMi = true;
                String sinifAdi = eslesme.group(1);
             
            }

            // Eğer sınıf bulunamadıysa, dosyayı sil
            if (!sinifVarMi) {
                if (dosya.delete()) {
                 //   System.out.println("Dosya silindi: " + dosya.getName());
                } else {
                //    System.out.println("Dosya silinemedi: " + dosya.getName());
                }
            }
        } catch (IOException e) {
            System.err.println("Dosya okunurken bir hata oluştu: " + e.getMessage());
        }
    }

    public  void main(String[] args) {
     
    }
    
    public void Classfilefind(String klasorYolu ) {
    	
        File klasor = new File(klasorYolu);
        klasorIcerisindekiDosyalariKontrolEtVeSifirla(klasor);
    }
}

