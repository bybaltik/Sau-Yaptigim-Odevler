/**
* @file B211210091
* @description BST agac
* @course 2.Öğretim A Grubu
* @assignment 2.Ödev
* @date 21.12.2024
* @author Bedirhan Baltık - bedirhan.baltık@ogr.sakarya.edu.tr
*/

#ifndef BST_HPP
#define BST_HPP

#include <string>
#include "CustomQueue.hpp"

class Bst {
public:
    Bst(char veri);
    ~Bst();

    char veri;
    Bst* ilkkok;
    Bst* sol;
    Bst* sag;
    Bst* sonrakikok;
    Bst* seciliAgac;
    int toplam;
    int sayac = 1;
    int agacsayisi =0;

    void DosyadanOkuVeEkle();
    int AgacSayisiBul();
    Bst* Ekle(Bst* kok, char veri);
    void Yazdirma(Bst*root);
    void KendiAdresiniYazdir(Bst*root);
    void SonrakiAdresiniYazdir(Bst*root);
    void ToplamYazdir(Bst*root);
    void SeciliAgaciGoster(Bst*root);
    void printLeftNodes(Bst* root);
    void printRightNodes(Bst* root);
    void CiziliAgacCizdir(Bst* seciliAgac);
    int YukseklikBul(Bst* seciliAgac);
    void SilAgac(Bst* seciliAgac);
    void SilVeriAgac(Bst* root);
    void Aynalama(Bst* kok);
    void KullaniciKontrol();
    int AgacNerde(Bst* root);
};

#endif
