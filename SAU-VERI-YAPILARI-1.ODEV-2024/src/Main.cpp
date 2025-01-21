#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main() {
    LinkedList nesne('c'); // Ornek bir nesne olusturuluyor
    nesne.DosyadanOkuVeEkle(); // Dosyadan veriler okunuyor

    int secim;
    do {
        cout << "-------------------------------" << endl;
        cout << "Lutfen bir secenek secin:" << endl;
        cout << "1 - Caprazlama" << endl;
        cout << "2 - Mutasyon" << endl;
        cout << "3 - Otomatik Islemler" << endl;
        cout << "4 - Ekrana Yaz" << endl;
        cout << "5 - Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        switch (secim) {
        case 1: {
            int satir1, satir2;
            cout << "Caprazlamak istediginiz Kromozomun numarasini girin: ";
            cin >> satir1;
            cout << "Caprazlamak istediginiz Kromozomun numarasini girin: ";
            cin >> satir2;
            nesne.Caprazlama(satir1, satir2);
            cout << "Caprazlama islemi tamamlandi." << endl;
            cout << endl;
            nesne.Yazdir();
            cout << endl;
            break;
        }
        case 2: {
            int satir, sutun;
            cout << "Mutasyon yapilacak Kromozom satir numarasini girin: ";
            cin >> satir;
            cout << "Mutasyon yapilacak Gen sutun numarasini girin: ";
            cin >> sutun;
            nesne.Mutasyon(satir, sutun);
            cout << "Mutasyon islemi tamamlandi." << endl;
            cout << endl;
            nesne.Yazdir();
            cout << endl;
            break;
        }
        case 3:
            nesne.OtomatikIslemler();
            cout << "Otomatik islemler tamamlandi." << endl;
            cout << endl;
            nesne.Yazdir();
            cout << endl;
            break;
        case 4:
            nesne.Yazdir();
            cout << "----------------------------------" << endl;
            cout << endl;
            nesne.EkranaYaz();
            cout << endl;
            break;
        case 5:
            cout << "Programdan cikiliyor ve kromozom ve gen listeleri silindi..." << endl;
            cout << endl;
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
            cout << endl;
            break;
        }
    } while (secim != 5);

    return 0;
}
