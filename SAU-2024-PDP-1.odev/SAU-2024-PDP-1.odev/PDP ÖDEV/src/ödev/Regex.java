/**
*
* @author bedirhan baltık bedirhan.baltik@ogr.sakarya.edu.tr 
* @since 04.04.2024
* <p>
* Sınıfım içinde class bulunan .java uzantılı dosyaların analizlerini yapıyor .(kod satır sayısı,loc,yorum satır sayısı gibi)
* </p>
*/




package ödev;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Regex {
	
	public void fileread  (String klasorYolu) {
	
	      
        // Klasördeki dosyaları al
        File klasor = new File(klasorYolu);
        File[] dosyalar = klasor.listFiles();
        
        
        
    

        // Her bir dosya için işlem yapıyorum
        if (dosyalar != null) {
            for (File dosya : dosyalar) {
            	double[] satirSayilari = dosyaIcerisindekiSatirSayisiniHesapla(dosya);
            	double boşsatirsayisi=satirSayilari[0];
            	double dolusatirsayisi=satirSayilari[1];
                
                  
         
         
            													
                  
                  
                 
             
                  
                // .java uzantılı dosya mı diye kontrol ediyorum
                if (dosya.isFile() && dosya.getName().endsWith(".java")) {
                   
         
               
                	double yg=((Javadocsatirsayisi(dosya) + YorumSatirSayisi(dosya))*0.8)/Fonksiyonsayisi(dosya);
                	double yh= (KodSatirSayisi(dosya)/Fonksiyonsayisi(dosya))*0.3;
                	double YorumSapmaYüzdesininHesabı =((100*yg)/yh)-100;
                	   dosyaIcerisindekiSinifAdlariniBul(dosya);
                	   System.out.println("Javadoc Yorum Satir Sayisi : " +Javadocsatirsayisi(dosya));
                	   System.out.println("Yorum Satir Sayisi : " +YorumSatirSayisi(dosya));
                	   System.out.println("Kod Satir Sayisi : " +KodSatirSayisi(dosya));
                       System.out.println("LOC :" + (boşsatirsayisi+dolusatirsayisi));  
                       System.out.println("Fonksiyon Sayisi : " +  Fonksiyonsayisi(dosya));
                       System.out.println("Yorum Sapma Yüzdesi : % "+YorumSapmaYüzdesininHesabı);
                     
                       
              
                       
                    
                  
                   
     
                    System.out.println("----------------------------------------------");
                }
            }
        } else {
            System.out.println("Klasör boş veya geçersiz.");
        }

}

	
	

public static void dosyaIcerisindekiSinifAdlariniBul(File dosya) {
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
            System.out.println("Sınıf : "+sinifAdi +".java");
        }

        // Eğer sınıf bulunamadıysa, dosya adını yazdır
        if (!sinifVarMi) {
           // System.out.println("Dosyada sınıf tanımı bulunamadı.");
        }
    } catch (IOException e) {
      // System.err.println("Dosya okunurken bir hata oluştu: " + e.getMessage());
    }
}




// Dosyadaki boş ve dolu satır sayılarını hesapla
public static double[] dosyaIcerisindekiSatirSayisiniHesapla(File dosya) {
	double bosSatirSayisi = 0;
	double doluSatirSayisi = 0;
  

    try (Scanner scanner = new Scanner(dosya)) {
        while (scanner.hasNextLine()) {
            String satir = scanner.nextLine();
            // Satırın boş olup olmadığını kontrol et
            if (satir.trim().isEmpty()) {
                bosSatirSayisi++;
            } else {
                doluSatirSayisi++;
            }
           
        }
       
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    }

    return new double[]{bosSatirSayisi, doluSatirSayisi}; 
}





public static double Fonksiyonsayisi(File dosya) {
    double fonksiyonsayisi = 0;
    

    try (Scanner scanner = new Scanner(dosya)) {
        while (scanner.hasNextLine()) {
            String satir = scanner.nextLine();
            // Satırın boş olup olmadığını kontrol et
        	   if ((satir.contains("public") || satir.contains("private") ||satir.contains("protected") || satir.contains("static") )&& satir.contains("(")) {
        		   fonksiyonsayisi++;
               }
        	 
              
           
        }
     
       
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    }

    
    return fonksiyonsayisi; 
}





public static double Javadocsatirsayisi(File dosya) {
	int javaDocSatirSayisi = 0;
	int blokYorumSayisi = 0;
    boolean blokYorumIcinde = false;

    try (Scanner scanner = new Scanner(dosya)) {
        while (scanner.hasNextLine()) {
            String satir = scanner.nextLine().trim();
            if (satir.startsWith("/**")) {
                blokYorumIcinde = true;
             
            }
            if (blokYorumIcinde) {
                javaDocSatirSayisi++;
                if (satir.endsWith("*/")) {
                    blokYorumSayisi++;
                    blokYorumIcinde = false;
                }
            }
        }
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    }

    // Sonuç hesaplanırken blok yorum satırları çıkarılır.
    double sonuc = javaDocSatirSayisi - (2 * blokYorumSayisi);
    return sonuc;
}










public static double KodSatirSayisi(File dosya) {
	double KodSatirSayisi = 0;
   
  

    try (Scanner scanner = new Scanner(dosya)) {
        while (scanner.hasNextLine()) {
        	   String satir = scanner.nextLine().trim();
            // Satırın boş olup olmadığını kontrol et
        	   if (!satir.startsWith("/**") && !satir.startsWith("*")&& !satir.startsWith("/*") && !satir.startsWith("*/")&& !satir.startsWith("//") && !satir.isEmpty()) {
        		   KodSatirSayisi++;
               }
           
        }
       // System.out.println("Kod satir sayisi : "+KodSatirSayisi);
       
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    }

    return KodSatirSayisi; 
}






public static double YorumSatirSayisi(File dosya) {
    double ciftSlashSatirSayisi = 0;
    boolean blokYorumIcinde = false;
  double blokYorumSayisi=0;

    try (Scanner scanner = new Scanner(dosya)) {
        while (scanner.hasNextLine()) {
            String satir = scanner.nextLine();
            // Satırın boş olup olmadığını kontrol et
        	   if (satir.contains("//")) {
                   ciftSlashSatirSayisi++;
               }
        	   if (satir.contains("/*") && !satir.contains("/**")) {
                   blokYorumIcinde = true;
                
               }
               if (blokYorumIcinde) {
            	   ciftSlashSatirSayisi++;
                   if (satir.endsWith("*/")) {
                       blokYorumSayisi++;
                       blokYorumIcinde = false;
                   }
               }
           
        }
      //  System.out.println("Yorum satir sayisi : "+ciftSlashSatirSayisi);
       
    } catch (FileNotFoundException e) {
        e.printStackTrace();
    }
double yorumsatiri=ciftSlashSatirSayisi-(blokYorumSayisi*2);
    
    return yorumsatiri; 
}




































}





