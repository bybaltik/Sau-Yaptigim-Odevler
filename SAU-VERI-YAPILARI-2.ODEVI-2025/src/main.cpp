/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Bst.hpp"

using namespace std;

int main() {
    // Yeni bir Bst nesnesi oluşturuyoruz
    Bst* agac = new Bst(' ');

    // Dosyadaki verileri okuma ve ağaca ekleme
    agac->DosyadanOkuVeEkle();

    agac->seciliAgac=agac->ilkkok;  //secili agacı ilkagac olarak atadım 

    

    // Kullanıcıdan ağacı kontrol etme isteği
    agac->KullaniciKontrol();

    // Belleği temizleme
    delete agac;
    return 0;
}
