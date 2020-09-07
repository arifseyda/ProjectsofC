/*
*@file               Okul.cpp
*@description        Ogrenci ve ogrenci adreslerini ogrenci ekle metodu ile ekleme yapan başlık dosyasıdır
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/
#ifndef Sinif_H
#define Sinif_H
#include "Ogrenci.h"
#include <iostream>
using namespace std;
class Sinif
{
private:
	int sinifNumarasi;
	int siradakiOgrenci;
public:
	Sinif(int,int);	
	Ogrenci **ogrenci;
	int sinifGetir();
	int ogrenciSayisi();
	void ogrenciEkle(char  adi);
	Sinif();
	~Sinif();
	void OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2);
	
};
#endif