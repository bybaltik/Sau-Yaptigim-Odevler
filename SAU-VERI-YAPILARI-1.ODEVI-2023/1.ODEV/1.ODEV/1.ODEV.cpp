#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdint> // for uintptr_t
using namespace std;

class deneme {
public:
 
    deneme(int veri) {
        this->veri = veri;  //Sayinin degerini tutar
        ilk = nullptr;   //Sayi adresini tutmak için
        sonraki = nullptr;  //Sayidan sonraki gelen sayının adresi icin 
        basamaksonraki = nullptr;   //Basamak adresleri tutmak icin
    }

    ~deneme() {
        sil(); // Düğüm silinirken bağlı listeler de temizlenir
    }

    int veri;
    deneme* ilk;
    deneme* sonraki;
    deneme* basamaksonraki;

    // Dosyadan sayıları okur ve listeye ekler
    void ekle() {
        ifstream inputfile("sayilar.txt");
        if (!inputfile) {
            cerr << "Dosya acilamadi" << endl;
            return;
        }

        int number;
        while (inputfile >> number) {
            deneme* yeni = new deneme(number);
            if (ilk == nullptr) {
                ilk = yeni;
            }
            else {
                deneme* gecici = ilk;
                while (gecici->sonraki != nullptr) {
                    gecici = gecici->sonraki;
                }
                gecici->sonraki = yeni;
            }

            // Sayıyı basamaklarına ayırma
            string numberstring = to_string(number);
            deneme* basamakIlk = nullptr; // İlk basamağı işaret eder
            deneme* basamakGecici = nullptr; // Geçici basamak düğümü

            for (char digit : numberstring) {
                int digitInt = digit - '0'; // Basamağı int yap
                deneme* basamakdegeri = new deneme(digitInt); // Yeni basamak düğümü

                if (basamakIlk == nullptr) {
                    basamakIlk = basamakdegeri;
                    yeni->basamaksonraki = basamakIlk; // İlk basamağı yeni düğüme bağla
                }
                else {
                    basamakGecici->basamaksonraki = basamakdegeri; // Sonraki basamağı bağla
                }
                basamakGecici = basamakdegeri; // Geçiciyi yeni basamağa ilerlet
            }

            // Son basamağın `nullptr` işaret ettiğinden emin ol
            if (basamakGecici != nullptr) {
                basamakGecici->basamaksonraki = nullptr;
            }
        }

        inputfile.close(); // Dosyayı kapat
    }

    void yazdir() {
        deneme* gecici = ilk;
        while (gecici != nullptr) {
            cout << "###################" << "    " << " *******" << "  " << "     *******" << endl;
            cout << "#" << gecici << "#";

            // Sayının basamaklarını yazdır
            deneme* basamak = gecici->basamaksonraki;
            while (basamak != nullptr) {
                // Adresin son 3 hanesini yazdır
                uintptr_t adres = reinterpret_cast<uintptr_t>(basamak);
                cout << "      * "


                    << setfill('0') << setw(3) << hex << (adres & 0xFFF) << " * " << dec; // Son 12 bit

                basamak = basamak->basamaksonraki;
            }
            cout << endl;
            cout << "#-----------------#" << "     " << "*******" << "    " << "   *******" << endl;

            cout << "#         " << gecici->veri << "      #";

            deneme* basamak2 = gecici->basamaksonraki;
            while (basamak2 != nullptr) {

                cout << "     *   " << basamak2->veri << " *  ";
                basamak2 = basamak2->basamaksonraki;

            }
            cout << endl;
            cout << "###################" << "     *******" << "   " << "    *******";
            cout << endl;
            cout << endl;

            gecici = gecici->sonraki; // Bir sonraki sayıya geç
        }
    }



    // Listeyi ve basamakları siler
    void sil() {
        cout << "Sil fonksiyonu calisti" << endl;

        deneme* gecici = ilk;
        while (gecici != nullptr) {
            cout << "ben calistimmi" << endl;
            // Basamakları sil
            deneme* basamak = gecici->basamaksonraki;
            while (basamak != nullptr) {
                cout << "Basamak sil calistimi" << endl;
                deneme* basamakSil = basamak;
                basamak = basamak->basamaksonraki;
                delete basamakSil;
            }

            // Sayı düğümünü sil
            deneme* silinecek = gecici;
            gecici = gecici->sonraki;
            delete silinecek;
        }

        ilk = nullptr; // Tüm listeyi sildiğimizden ilk düğümü de null yap
    }

    void enbuyuksayiyicikar() {
        if (ilk == nullptr) {
            // Liste boşsa çık
            return;
        }

        deneme* gecici = ilk;
        deneme* onceki = nullptr;  // Silinecek düğümün öncesini izlemek için
        deneme* silinecek = ilk;
        deneme* silinecekOnceki = nullptr;

        // İlk değeri en büyük olarak al
        int enbuyuksayi = ilk->veri;

        // Bağlı listeyi dolaş
        while (gecici != nullptr) {
            if (gecici->veri > enbuyuksayi) {
                enbuyuksayi = gecici->veri;
                silinecek = gecici;
                silinecekOnceki = onceki;
            }
            onceki = gecici;
            gecici = gecici->sonraki;
        }

        // Silme işlemi
        if (silinecekOnceki == nullptr) {
            // En büyük sayı ilk düğümdeyse
            ilk = ilk->sonraki;
        }
        else {
            // Bağlantıyı atla
            silinecekOnceki->sonraki = silinecek->sonraki;
        }
        cout << silinecek->veri << "  silindi." << endl;
        delete silinecek;  // En büyük düğümü sil
    }

    // Tek basamaklı sayıları başa çekme
  // Tek basamakları başa çeker
    void tekBasamaklariBasaAl() {
        deneme* gecici = ilk;
        while (gecici != nullptr) {
            deneme* basamakIlk = nullptr;
            deneme* basamakGecici = gecici->basamaksonraki;
            deneme* tekIlk = nullptr;
            deneme* tekSon = nullptr;
            deneme* ciftIlk = nullptr;
            deneme* ciftSon = nullptr;

            // Basamakları tek ve çift olarak ayır
            while (basamakGecici != nullptr) {
                deneme* sonraki = basamakGecici->basamaksonraki;
                basamakGecici->basamaksonraki = nullptr;

                if (basamakGecici->veri % 2 != 0) { // Tek basamak
                    if (tekIlk == nullptr) {
                        tekIlk = basamakGecici;
                        tekSon = basamakGecici;
                    }
                    else {
                        tekSon->basamaksonraki = basamakGecici;
                        tekSon = basamakGecici;
                    }
                }
                else { // Çift basamak
                    if (ciftIlk == nullptr) {
                        ciftIlk = basamakGecici;
                        ciftSon = basamakGecici;
                    }
                    else {
                        ciftSon->basamaksonraki = basamakGecici;
                        ciftSon = basamakGecici;
                    }
                }
                basamakGecici = sonraki;
            }

            // Tek basamakları başa al, çift basamakları ise sonrasına ekle
            if (tekIlk != nullptr) {
                gecici->basamaksonraki = tekIlk;
                if (tekSon != nullptr) {
                    tekSon->basamaksonraki = ciftIlk;
                }
                else {
                    gecici->basamaksonraki = ciftIlk;
                }
            }
            else {
                gecici->basamaksonraki = ciftIlk;
            }

            // Yeni değeri hesapla
            deneme* basamak = gecici->basamaksonraki;
            int yeniSayi = 0;
            int basamakBoyu = 1;

            while (basamak != nullptr) {
                yeniSayi = yeniSayi * 10 + basamak->veri;
                basamak = basamak->basamaksonraki;
            }

            gecici->veri = yeniSayi;

            gecici = gecici->sonraki;
        }
    }

    void basamaklariTersle() {
        deneme* gecici = ilk;
        while (gecici != nullptr) {
            // Basamakları ters çevir
            deneme* basamakIlk = nullptr;
            deneme* basamakGecici = gecici->basamaksonraki;
            deneme* tersBasamakIlk = nullptr;
            deneme* tersBasamakGecici = nullptr;

            while (basamakGecici != nullptr) {
                deneme* sonraki = basamakGecici->basamaksonraki;
                basamakGecici->basamaksonraki = tersBasamakIlk;
                tersBasamakIlk = basamakGecici;
                basamakGecici = sonraki;
            }

            // Ters çevrilmiş basamakları listeye bağla
            gecici->basamaksonraki = tersBasamakIlk;

            // Yeni değeri hesapla
            deneme* basamak = tersBasamakIlk;
            int yeniSayi = 0;
            int basamakBoyu = 1;

            while (basamak != nullptr) {
                yeniSayi = yeniSayi * 10 + basamak->veri;
                basamak = basamak->basamaksonraki;
            }

            gecici->veri = yeniSayi;

            gecici = gecici->sonraki;
        }
    }


};

int main() {
    deneme d(8); // Başlangıçta dummy bir değer
    d.ekle();    // Sayıları dosyadan oku ve ekle
    d.yazdir();  // Sayıları ve basamaklarını yazdır



    // Destructor otomatik olarak çağrılır ve bellek temizliği yapılır
    int islem;
    do {
        // Menü
        cout << "1. Tek basamaklari basa al" << endl;
        cout << "2. Basamaklari tersle" << endl;
        cout << "3. En buyuk cikar" << endl;
        cout << "4. Cikis" << endl;
        cout << "Bir islem secin (1-4): ";

        cin >> islem;

        switch (islem) {
        case 1:
            // Tek basamakları başa alma işlemleri
            cout << "Tek basamaklari basa al secildi." << endl;
            d.tekBasamaklariBasaAl();
            d.yazdir();

            break;
        case 2:
            // Basamakları tersleme işlemleri
            cout << "Basamaklari tersle." << endl;
            d.basamaklariTersle();
            d.yazdir();
            break;
        case 3:
            // En büyük çıkarma işlemleri
            cout << "En buyuk cikar secildi." << endl;
            d.enbuyuksayiyicikar();
            d.yazdir();
            break;
        case 4:
            // Çıkış işlemleri
            cout << "Cikis yapiliyor." << endl;
            break;

        default:
            // Geçersiz seçenek
            cout << "Gecersiz secenek. Lutfen 1 ile 4 arasinda bir deger girin." << endl;
            break;
        }

    } while (islem != 4); // 4 dışındaki seçenekler için döngüyü devam ettir

    return 0;
}
