/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/

#include "Bst.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

Bst::Bst(char veri) {
    this->veri = veri;
    ilkkok = nullptr;
    sol = nullptr;
    sag = nullptr;
    sonrakikok = nullptr;
    toplam = 0;
    seciliAgac = nullptr;
}

Bst::~Bst() {
    Bst* gecici = ilkkok;
    Bst* yedek = nullptr;
    while (gecici != nullptr) {
        yedek = gecici->sonrakikok;
        SilVeriAgac(gecici);
        delete gecici;
        gecici = yedek;
    }
}

void Bst::DosyadanOkuVeEkle() {
    ifstream file("agaclar.txt");
    string satir;

    while (getline(file, satir)) {
        bool dogrumu = true;
        Bst* yeni = nullptr;
        for (char karakter : satir) {
            if (dogrumu == true) {
                dogrumu = false;
                yeni = new Bst(karakter); // Yeni ağacın kök düğümü

                if (ilkkok == nullptr) {
                    ilkkok = yeni;
                }
                else {
                    Bst* gecici = ilkkok;
                    while (gecici->sonrakikok != nullptr) {
                        gecici = gecici->sonrakikok;
                    }
                    gecici->sonrakikok = yeni;
                }
            }
            Ekle(yeni, karakter);
        }
    }
}
    int Bst::AgacSayisiBul(){
     Bst* temp = ilkkok;

 while (temp != nullptr) {
     temp = temp->sonrakikok;
     agacsayisi++;
 }
 return agacsayisi;
}
Bst* Bst::Ekle(Bst* kok, char veri) {
    if (kok == nullptr) {
        return new Bst(veri);
    }
    if (veri < kok->veri) {
        kok->sol = Ekle(kok->sol, veri);
    }
    else if (veri > kok->veri) {
        kok->sag = Ekle(kok->sag, veri);
    }
    return kok;
}

void Bst::Yazdirma(Bst*root) {
    KendiAdresiniYazdir(root);
    ToplamYazdir(root);
    SonrakiAdresiniYazdir(root);
   
}

void Bst::KendiAdresiniYazdir(Bst*root) {
     Bst* gecici = root;
  Bst* gecici2 = root;
  int counter = 1;



  while (gecici2->sonrakikok != nullptr) {
      counter++;

      gecici2 = gecici2->sonrakikok;
  }
  
  if (counter > 10) {



      for (int i = 0; i < 10; i++) {
          cout << "........   ";
      }
      cout << endl;
      for (int i = 0; i < 10; i++) {
          if (gecici != nullptr) {
              uintptr_t adres = reinterpret_cast<uintptr_t>(gecici);
              cout << ".  " << hex << setw(4) << setfill('0') << adres % 0x10000 << ".   ";
              gecici = gecici->sonrakikok;
          }
      }
      cout << endl;
      for (int i = 0; i < 10; i++) {
          cout << "........   ";
      }
      cout << endl;
  }
  else {
      for (int i = 0; i < counter; i++) {
          cout << "........   ";
      }
      cout << endl;
      for (int i = 0; i < counter; i++) {
          if (gecici != nullptr) {
              uintptr_t adres = reinterpret_cast<uintptr_t>(gecici);
              cout << ".  " << hex << setw(4) << setfill('0') << adres % 0x10000 << ".   ";
              gecici = gecici->sonrakikok;
          }
      }
      cout << endl;
      for (int i = 0; i < counter; i++) {
          cout << "........   ";
      }
      cout << endl;
  }
}
void Bst:: SonrakiAdresiniYazdir(Bst*root) {
        Bst* gecici = root;
 Bst* gecici2 = root;
 int counter = 1;



 while (gecici2->sonrakikok != nullptr) {
     counter++;

     gecici2 = gecici2->sonrakikok;
 }
 if (counter > 10) {




     for (int i = 0; i < 10; i++) {
         cout << "........   ";
     }
     cout << endl;
     for (int i = 0; i < 10; i++) {
         if (gecici != nullptr) {
             uintptr_t adres = reinterpret_cast<uintptr_t>(gecici->sonrakikok);
             cout << ".  " << hex << setw(4) << setfill('0') << adres % 0x10000 << ".   ";
             gecici = gecici->sonrakikok;
         }
     }
     cout << endl;
     for (int i = 0; i < 10; i++) {
         cout << "........   ";
     }
     cout << endl;
 }

 else {
     for (int i = 0; i < counter; i++) {
         cout << "........   ";
     }
     cout << endl;
     for (int i = 0; i < counter; i++) {
         if (gecici != nullptr) {
             uintptr_t adres = reinterpret_cast<uintptr_t>(gecici->sonrakikok);
             cout << ".  " << hex << setw(4) << setfill('0') << adres % 0x10000 << ".   ";
             gecici = gecici->sonrakikok;
         }
     }
     cout << endl;
     for (int i = 0; i < counter; i++) {
         cout << "........   ";
     }
     cout << endl;

 }
    }

void Bst::ToplamYazdir(Bst*root){
       Bst* gecici = root;
  Bst* gecici2 = root;
  int counter = 1;



  while (gecici2->sonrakikok != nullptr) {
      counter++;

      gecici2 = gecici2->sonrakikok;
  }

  if (counter > 10) {




      for (int i = 0; i < 10; i++) {
          cout << "........   ";
      }
      cout << endl;
      for (int i = 0; i < 10; i++) {

          if (gecici != nullptr) {
              toplam = 0; // Her bir ağaç için toplamı sıfırla
              toplam += gecici->veri;
              printLeftNodes(gecici);
              printRightNodes(gecici);

              cout << ". ";
              printf("%d", toplam);
              cout << " .   ";
              gecici = gecici->sonrakikok;
          }
      }
      cout << endl;
      for (int i = 0; i < 10; i++) {
          cout << "........   ";
      }
      cout << endl;
  }
  else {
      for (int i = 0; i < counter; i++) {
          cout << "........   ";
      }
      cout << endl;
      for (int i = 0; i < counter; i++) {

          if (gecici != nullptr) {
              toplam = 0; // Her bir ağaç için toplamı sıfırla
              toplam += gecici->veri;
              printLeftNodes(gecici);
              printRightNodes(gecici);

              cout << ". ";
              printf("%d", toplam);
              cout << " .   ";
              gecici = gecici->sonrakikok;
          }
      }
      cout << endl;
      for (int i = 0; i < counter; i++) {
          cout << "........   ";
      }
      cout << endl;
  }
    }
void Bst::SeciliAgaciGoster(Bst*root) {
        int modelSayac = AgacNerde(root)%10;

   for (int i = 1; i <= AgacNerde(root); i++) {


       if (i == 10 && modelSayac == 0) {
           cout << "^^^^^^^^";
       }
       if (i == (modelSayac)) {
           cout << "^^^^^^^^";
       }


       else {
           cout << "           ";
       }

   }
   cout << endl;
   for (int i = 1; i <= AgacNerde(root); i++) {


       if (i == 10 && modelSayac == 0) {
           cout << "||||||||";
       }
       if (i == (modelSayac)) {
           cout << "||||||||";
       }


       else {
           cout << "           ";
       }

   }
   cout << endl;
    }
    void Bst::printLeftNodes(Bst* root){
        if (root == nullptr) return;
        if (root->sol != nullptr) {
            toplam += root->sol->veri * 2;
        }
        printLeftNodes(root->sol);
        printLeftNodes(root->sag);
    }
void Bst::printRightNodes(Bst* root){
        if (root == nullptr) return;
        if (root->sag != nullptr) {
            toplam += root->sag->veri;
        }
        printRightNodes(root->sol);
        printRightNodes(root->sag);
    }
   void Bst::CiziliAgacCizdir(Bst* seciliAgac) {
       if (seciliAgac == nullptr) {
           cout << "Secili bir agac yok!" << endl;
           return;
       }

       CustomQueue kuyruk;
       kuyruk.enqueue(seciliAgac);

       int yukseklik = YukseklikBul(seciliAgac);
       int seviye = 0;
       int sayac = 0;
  
       while (!kuyruk.isEmpty()) {
           int seviyeBoyutu = kuyruk.size();
           int boslukMiktari = pow(2, yukseklik - seviye ) ; // Düğümler arasındaki boşluk miktarını ayarla

           // Boşluk ile hizalama
           cout << string(boslukMiktari, ' ');

           for (int i = 0; i < seviyeBoyutu; i++) {
               Bst* current = kuyruk.dequeue();

               if (current != nullptr) {
                 
                   cout << current->veri; // Düğüm verisini yazdır
                   kuyruk.enqueue(current->sol); // Sol çocuğu ekle
                   kuyruk.enqueue(current->sag); // Sağ çocuğu ekle
               }
               else {
                   cout << " "; // Boş düğüm
                   kuyruk.enqueue(nullptr); // Sol çocuğu boş ekle
                   kuyruk.enqueue(nullptr); // Sağ çocuğu boş ekle
               }

               // Düğümler arası boşluk
               cout << string(boslukMiktari * 2 - 1, ' ');
           }
           cout << endl;

           int sayac = pow(2, seviye);

           for (int index = 0; index < sayac; index++) {
               int boslukMiktari2 = pow(2, yukseklik - (seviye + 1));
               cout << string(boslukMiktari2, ' ');
               int kardesbosluk = pow(2, yukseklik - seviye) + 1; // Düğümler arasındaki boşluk miktarını ayarla
               cout << string(kardesbosluk, '.');
               if(seviye != yukseklik)
                   cout << string(boslukMiktari2 - 1, ' ');


     }

           cout << endl;

           seviye++;
     
        

           // Kuyruktaki tüm elemanlar nullptr ise işlemi durdur
           CustomQueue tempQueue;
           bool hepsiNull = true;
           while (!kuyruk.isEmpty()) {
               Bst* eleman = kuyruk.dequeue();
               if (eleman != nullptr) hepsiNull = false;
               tempQueue.enqueue(eleman);
           }

           while (!tempQueue.isEmpty()) {
               kuyruk.enqueue(tempQueue.dequeue());
           }

           if (hepsiNull) break;
       }
   }
   int Bst::YukseklikBul(Bst* seciliAgac){
        if (seciliAgac)
            return 1 + max(YukseklikBul(seciliAgac->sol), YukseklikBul(seciliAgac->sag));
        return -1;
    }
void Bst::SilAgac(Bst* seciliAgac) {
        if (ilkkok == nullptr) {
            cout << "Liste bos" << endl;
            return;
        }

        // Eğer sadece bir düğüm varsa
        if (ilkkok == seciliAgac && ilkkok->sonrakikok == nullptr) {
            // Tek düğüm varsa, o düğümü silip listeyi null yapalım
            SilVeriAgac(ilkkok); // Ağacın tüm düğümlerini sil
            delete ilkkok; // Son düğümü sil
            ilkkok = nullptr; // Listeyi boşalt
            return;
        }

        // Secili ağacı bağlı listeden çıkaralım
        Bst* gecici = ilkkok;
        if (gecici == seciliAgac) { // Eğer ilk ağaç seciliAgac ise
            ilkkok = ilkkok->sonrakikok;
        }
        else {
            while (gecici->sonrakikok != seciliAgac) {
                gecici = gecici->sonrakikok;

            }
            gecici->sonrakikok = seciliAgac->sonrakikok; // Sonraki düğümü bağlıyoruz
        }

        // Ağacın tüm düğümlerini silmek için bir yardımcı fonksiyon çağırıyoruz
        SilVeriAgac(seciliAgac);

        // Secili ağacı bellekten serbest bırakıyoruz
        delete seciliAgac; // Seçili ağacı sil

    }
void Bst::SilVeriAgac(Bst* root) {
        if (root == nullptr) return;

        // Sol ve sağ alt ağaçları sil
        SilVeriAgac(root->sol);
        SilVeriAgac(root->sag);


    }
    void Bst::Aynalama(Bst* kok) {
        if (kok == nullptr) return; // Eğer düğüm boşsa, bir işlem yapmadan geri dön.

        // Sol ve sağ alt ağaçları yer değiştir
        Bst* temp = kok->sol;
        kok->sol = kok->sag;
        kok->sag = temp;

        // Sol ve sağ alt ağaçlar için aynalama işlemini rekürsif olarak uygula
        Aynalama(kok->sol);
        Aynalama(kok->sag);
    }
     void Bst::KullaniciKontrol() {
          char secim;
   Bst* gecici = ilkkok;
   while (true) {

       if (ilkkok == nullptr) {
           cout << "Liste tamamen bos";
       }
       else {
           agacsayisi = 0;
       Yazdirma(gecici); // Ağacı yazdır
       SeciliAgaciGoster(seciliAgac);
       

       AgacNerde(seciliAgac);
       AgacSayisiBul();
       CiziliAgacCizdir(seciliAgac);
      
          

       }
       cout << "Yon degistirmek icin (a: onceki, d: sonraki), Agaci silmek icin (s),aynalama islemi icin (w), cikis ve tum agac ve dugumleri silmek icin (q): ";



       cin >> secim;


       if (secim == 'a') {
           // Önceki ağaca geç
           if (sayac > 1) {
               sayac--;
           }

           if (sayac != 0) {

               if (sayac % 10 == 0) {
                   Bst* yedek = ilkkok;
                   while (yedek->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok != gecici) {
                       yedek = yedek->sonrakikok;
                       
                   }
                   gecici = yedek;
               }
           }
           system("cls");
           if (seciliAgac != ilkkok) {
               Bst* gecici = ilkkok;
               while (gecici->sonrakikok != seciliAgac) {
                   gecici = gecici->sonrakikok;
               }
               seciliAgac = gecici; // Önceki ağaca geç
           }
           else {
               cout << "Zaten ilk agactasiniz." << endl;
           }
       }
       else if (secim == 'd') {
           if (sayac != 0) {
               if (sayac % 10 == 0) {
                   for (int i = 0; i < 10; i++) {
                       if (gecici->sonrakikok == nullptr) {
                           cout << "zaten son agactasiniz";
                           
                       }
                       gecici = gecici->sonrakikok;
                       
                   }
                   
               }
           }


           // Sonraki ağaca geç
           if (sayac != agacsayisi) {
               sayac++;
          }
           system("cls");
           if (seciliAgac != nullptr && seciliAgac->sonrakikok != nullptr) {
               seciliAgac = seciliAgac->sonrakikok; // Sonraki ağaca geç
           }
           else {
               cout << "Zaten son agactasiniz." << endl;
           }
       }

       else if (secim == 's') {
       

           system("cls");
           if (seciliAgac != nullptr) {
            
               // Eğer seçili ağaç birden fazla düğüm içeriyorsa
               if (seciliAgac->sonrakikok != nullptr) {
                   
                   
                   Bst* yedek = seciliAgac->sonrakikok;
                   
                   if (seciliAgac == gecici) {
                       gecici = yedek;
                   }
                   SilAgac(seciliAgac);  // Ağacı sil
                   seciliAgac = yedek;  // Yeni seçili ağaç
                   
               }
               else {
                   // Eğer liste sadece bir düğüm içeriyorsa
                   if (ilkkok == seciliAgac) {
                       // Liste tek düğümle başlıyorsa
                       SilAgac(seciliAgac);
                       seciliAgac = nullptr;  // Listeyi boşalt
                       ilkkok = nullptr;  // Listeyi tamamen boşalt
                       cout << "Secili agac silindi ve liste tamamen bosaltildi." << endl;
                       
                   }
                  
                   else {
                       if (sayac > 0) {
                           sayac--;
                       }
                       // Diğer düğümler arasında son düğümü silmek için
                       Bst* yedek = ilkkok;
                       while (yedek->sonrakikok != seciliAgac) {
                           yedek = yedek->sonrakikok;
                       }
                       Bst* deneme = ilkkok;

                       if (seciliAgac == gecici) {

                           while (deneme->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok->sonrakikok != gecici) {
                               deneme = deneme->sonrakikok;

                           }

                           
                           gecici = deneme;

                           
                     }
                      

                       SilAgac(seciliAgac);
                       seciliAgac = yedek;  // Yeni seçili ağaç
                       
                   }

               }

           }
           else {
               cout << "Secili agac yok!" << endl;
           }
       }

       else if (secim == 'w') {
           system("cls");
           Aynalama(seciliAgac);

       }
       else if (secim == 'q') {
           break; // Döngüyü sonlandır
       }
   }
    }

    int Bst::AgacNerde(Bst*root){
         Bst* temp = ilkkok; // Bağlı listenin başından başla
 int konum = 1;      // Konum sayacı (1'den başlatıyoruz)

 while (temp != nullptr) {
     if (temp == root) { // Eğer seciliAgac bulunduysa
         return konum;         // Sırasını döndür
     }
     temp = temp->sonrakikok;  // Bir sonraki köke geç
     konum++;                  // Konumu artır
 }

 return -1; // Eğer seciliAgac bağlı listede bulunamazsa
    }