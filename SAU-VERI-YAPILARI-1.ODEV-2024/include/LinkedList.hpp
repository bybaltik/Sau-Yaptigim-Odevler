#ifndef LinkedList_H
#define LinkedList_H

#include <string>
using namespace std;

class LinkedList {
public:
    LinkedList(char veri);                   //Kurucu fonksiyonu
    ~LinkedList();                                   //Yıkıcı fonksiyonu
    void DosyadanOkuVeEkle();                           //Dosyadan (Dna.txt) okuma yapıp gen ve kromozom bagıl listelerimi olusturma fonksiyonu
    void Yazdir();                  //Bagıl listelerimi yazdirma fonksiyonu
    void Caprazlama(int satir1, int satir2);                 //Caprazlama fonksiyonu
    void Mutasyon(int satir, int sutun);                //Mutasyon fonksiyon
    void OtomatikIslemler();                 //Otomatikİslemler fonksiyonu
    void EkranaYaz();                                           //EkranaYaz fonksiyon

    char veri;
    LinkedList* gensonraki;
    LinkedList* kromozomsonraki;
    LinkedList* ilk;
};

#endif // LinkedList




