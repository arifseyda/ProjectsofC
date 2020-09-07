/*
*@file               Okul.cpp
*@description        Ogrenci degiştir ve sinif degiştir işlemlerini yapan başlık dosyasıdır
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#ifndef Ogrenci_HPP
#define Ogrenci_HPP
#include <iostream>
using namespace std;
class Ogrenci
{
private:
	char Harf;
	char siradakiHarf;
public:
	Ogrenci **ogrenci;
	Ogrenci(char harf);
	Ogrenci();
	~Ogrenci();
	char harfGetir();
};
#endif