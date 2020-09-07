/*
*@file               Okul.cpp
*@description        Ogrenci degiştir ve sinif degiştir işlemlerini yapan başlık dosyasıdır
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç   huseyin.ozkilic@ogr.sakarya.edu.tr  
*/

#ifndef Yonetim_H
#define Yonetim_H
#include "Okul.h"
#include <iostream>
using namespace std;

class Yonetim
{
public:
	Yonetim(Okul* okul);
	void OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2);
	void sinifDegistir(char sinifsayisi1, char sinifsayisi2);
	~Yonetim();
	Yonetim();
private:
	Ogrenci **ogrenci;
	Sinif **sinif;
	Okul* okul;

};
#endif