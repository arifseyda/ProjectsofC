/*
*@file               Okul.h
*@description        Sınıf ve ogrencileri yazdırıyor ve ogrenci degiştir ve sinif degiştir işlemlerini yapıldığı başlık dosyasıdır
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#ifndef Okul_H
#define Okul_H
#include "Sinif.h"
#include <iostream>
using namespace std;
class Okul
{
private:
	Sinif *yedek2;
	int siradakiSinif;
	int sinifSayisi;
	int ogrenciSayisi;
	int maxogrsayi;
	
public:
	Sinif **SinifDizisi;
	Okul(int sinifSayisi);
	~Okul();
	void Yazdir(int);
	Okul();
	void OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2);
	void sinifDegistir(int sinifsayisi1, int sinifsayisi2);
	void sinifEkle(Sinif *yeni);
};
#endif