#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Yapıcı
LinkedList::LinkedList(char veri) {
    this->veri = veri;
    ilk = nullptr;
    gensonraki = nullptr;
    kromozomsonraki = nullptr;
}

// Yıkıcı
LinkedList::~LinkedList() {
    // Yıkıcı işlemleri burada
  
      LinkedList* satir = ilk;
  while (satir != nullptr) {
      LinkedList* karakter = satir;
      LinkedList* sonrakiSatir = satir->kromozomsonraki; // Bir sonraki satırı kaydet
      // Satırdaki tüm karakterleri serbest bırak
      while (karakter != nullptr) {
          LinkedList* sonrakiKarakter = karakter->gensonraki; // Bir sonraki karakteri kaydet
          delete karakter; // Mevcut karakteri serbest bırak
          karakter = sonrakiKarakter; // Bir sonraki karaktere geç
      }

      satir = sonrakiSatir; // Bir sonraki satıra geç
  }
}

// Dosyadan okuma ve ekleme işlemi
void LinkedList::DosyadanOkuVeEkle() {
    // İşlev gövdesi burada
     ifstream file("Dna.txt"); // Dosyayı aç
 char ch;
 char sonKarakter = '\0'; // Önceki satırın son karakterini saklamak için değişken
 LinkedList* sonDugum = nullptr; // Son eklenen düğümü saklamak için

 if (file.is_open()) {
     while (file.get(ch)) { // Her bir karakteri oku
         if (ch == '\n') { // Satır sonu durumunda
             if (sonDugum != nullptr) {
                 sonDugum->gensonraki = nullptr; // Satırın son düğümünün gensonraki'si nullptr
             }
             sonKarakter = '\0'; // Satır sonu olduğu için son karakteri sıfırla
             sonDugum = nullptr; // Yeni satır için sonDugum'u sıfırla
         }
         else if (ch != ' ') { // Boşlukları atla
             LinkedList* yeni = new LinkedList(ch); // Yeni düğüm oluştur

             if (ilk == nullptr) {
                 // Listenin ilk düğümü yoksa, bu düğümü ilk düğüm yap
                 ilk = yeni;
             }
             else if (sonDugum == nullptr) {
                 // Yeni bir satır başladığında, kromozomsonraki'yi ayarla
                 LinkedList* gecici = ilk;
                 while (gecici->kromozomsonraki != nullptr) {
                     gecici = gecici->kromozomsonraki;
                 }
                 gecici->kromozomsonraki = yeni;
             }
             else {
                 // Aynı satırda, son düğümün gensonraki'sini yeni düğüme bağla
                 sonDugum->gensonraki = yeni;
             }

             // Son düğümü güncelle
             sonDugum = yeni;
             sonKarakter = ch; // Mevcut karakteri son karakter olarak sakla
         }
     }

     // Dosya okuma işlemi tamamlandıktan sonra son karakteri kontrol et
     if (sonDugum != nullptr) {
         sonDugum->gensonraki = nullptr; // Son satırın son karakterini işaret et
     }

     file.close(); // Dosyayı kapat
 }
 else {
     cerr << "Dosya acilamadi." << endl;
 }
}

// Yazdırma işlemi
void LinkedList::Yazdir() {
    // İşlev gövdesi burada
      LinkedList* satir = ilk;
  while (satir != nullptr) {
      LinkedList* karakter = satir;
      while (karakter != nullptr) {
          cout << karakter->veri << " ";
          karakter = karakter->gensonraki; // Aynı satırdaki sonraki düğüme geç
      }
      satir = satir->kromozomsonraki; // Bir sonraki satıra geç
      cout << endl;
  }
}

void LinkedList::Caprazlama(int satir1, int satir2) {
    // İlk ve ikinci kromozomları bul
    LinkedList* kromozom1 = ilk;
    LinkedList* kromozom2 = ilk;

    for (int i = 0; i < satir1; ++i) {
        if (kromozom1 == nullptr) {
            cerr << "Hatali birinci satir numarasi." << endl;
            return;
        }
        kromozom1 = kromozom1->kromozomsonraki;
    }

    for (int i = 0; i < satir2; ++i) {
        if (kromozom2 == nullptr) {
            cerr << "Hatali ikinci satir numarasi." << endl;
            return;
        }
        kromozom2 = kromozom2->kromozomsonraki;
    }

    // İlk kromozomun boyutunu hesapla
    int uzunluk1 = 0, uzunluk2 = 0;
    LinkedList* temp = kromozom1;
    while (temp != nullptr) {
        uzunluk1++;
        temp = temp->gensonraki;
    }

    // İkinci kromozomun boyutunu hesapla
    temp = kromozom2;
    while (temp != nullptr) {
        uzunluk2++;
        temp = temp->gensonraki;
    }

    // Orta noktaları belirle
    int orta1 = uzunluk1 / 2;
    int orta2 = uzunluk2 / 2;

    // Yeni genleri oluştur
    string genler1, genler2;
    temp = kromozom1;
    for (int i = 0; i < uzunluk1; i++) {
        if (i < orta1) genler1 += temp->veri;
        else if (uzunluk1 % 2 == 0 || i > orta1) genler2 += temp->veri;
        temp = temp->gensonraki;
    }

    string genler3, genler4;
    temp = kromozom2;
    for (int i = 0; i < uzunluk2; i++) {
        if (i < orta2) genler4 += temp->veri;
        else if (uzunluk2 % 2 == 0 || i > orta2) genler3 += temp->veri;
        temp = temp->gensonraki;
    }

    // Yeni kromozomlar
    string yeniGenler1 = genler1 + genler3;
    string yeniGenler2 = genler2 + genler4;

    // Yeni kromozomları ekle
    auto yeniKromozomOlustur = [](const string& genler) -> LinkedList* {
        LinkedList* yeniIlk = nullptr;
        LinkedList* onceki = nullptr;
        for (char ch : genler) {
            LinkedList* yeni = new LinkedList(ch);
            if (yeniIlk == nullptr) yeniIlk = yeni;
            else onceki->gensonraki = yeni;
            onceki = yeni;
        }
        return yeniIlk;
    };

    LinkedList* yeniKromozom1 = yeniKromozomOlustur(yeniGenler1);
    LinkedList* yeniKromozom2 = yeniKromozomOlustur(yeniGenler2);

    // Yeni kromozomları popülasyona ekle
    LinkedList* gecici = ilk;
    while (gecici->kromozomsonraki != nullptr) {
        gecici = gecici->kromozomsonraki;
    }
    gecici->kromozomsonraki = yeniKromozom1;
    yeniKromozom1->kromozomsonraki = yeniKromozom2;
}


// Mutasyon işlemi
void LinkedList::Mutasyon(int satir, int sutun) {
    // İşlev gövdesi burada
      // Start at the first chromosome
  LinkedList* kromozom = ilk;
  for (int i = 0; i < satir; ++i) {
      if (kromozom == nullptr) {
          cerr << "Hatali satir numarasi." << endl;
          return;
      }
      kromozom = kromozom->kromozomsonraki; // Move to the next chromosome
  }

  // Now at the correct chromosome, navigate to the correct gene
  LinkedList* gen = kromozom;
  for (int j = 0; j < sutun; ++j) {
      if (gen == nullptr) {
          cerr << "Hatali sutun numarasi." << endl;
          return;
      }
      gen = gen->gensonraki; // Move to the next gene
  }

  if (gen != nullptr) {
      gen->veri = 'X'; // Perform mutation
  }
  else {
      cerr << "Hatali sutun numarasi." << endl;
  }
}

// Otomatik işlemler
void LinkedList::OtomatikIslemler() {
    // İşlev gövdesi burada
    ifstream dosya("islemler.txt");
string satir;

if (!dosya) {
    cerr << "Dosya acilamadi!" << endl;
    
}

while (getline(dosya, satir)) {
    istringstream iss(satir);
    string komut;
    int sayi1, sayi2;

    // Satırı okuma
    if (iss >> komut >> sayi1 >> sayi2) {
        if (komut == "C") {
            Caprazlama(sayi1, sayi2);
        }
        else if (komut == "M") {
        Mutasyon(sayi1,sayi2);
            // M komutunu bulduğunda ilgili fonksiyonu çağır
        }

    }
}

dosya.close();
}

// Ekrana yazma işlemi
void LinkedList::EkranaYaz() {
    // İşlev gövdesi burada
      LinkedList* satir = ilk;  // İlk kromozomdan başlayarak her satır üzerinde çalışacağız

  while (satir != nullptr) {
      char yazdirilacak = satir->veri;  // İlk düğümün verisini varsayılan olarak alıyoruz
      LinkedList* son = satir;
      LinkedList* onceki = nullptr;

      // Satırın son düğümünü bulmak için sona kadar ilerle
      while (son->gensonraki != nullptr) {
          onceki = son;
          son = son->gensonraki;
      }

      // Sağdan sola doğru ilerleyerek ilk düğümden küçük bir karakter arayın
      while (son != satir) {  // İlk düğüme ulaşana kadar devam et
          if (son->veri < yazdirilacak) {
              yazdirilacak = son->veri;
              break;
          }

          // Son düğümü bir önceki düğüme çek
          if (onceki != nullptr) {
              delete son;  // Son düğümü sil
              onceki->gensonraki = nullptr;  // Bir önceki düğümü yeni son düğüm yap
              son = onceki;

              // Yeni 'son' düğümden önceki düğümü bul
              onceki = satir;
              while (onceki->gensonraki != son && onceki->gensonraki != nullptr) {
                  onceki = onceki->gensonraki;
              }
          }
          else {
              break;  // Eğer artık başka düğüm kalmamışsa döngüyü sonlandır
          }
      }

      // İstenen karakteri yazdır
      cout << yazdirilacak << " ";
      satir = satir->kromozomsonraki;  // Bir sonraki kromozoma geç
  }
  cout << endl;
}
