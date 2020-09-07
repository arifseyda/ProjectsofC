/*
*@file               Okul.cpp
*@description        Ogrenci degiştir ve sinif degiştir işlemlerini yapıyor
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#include "Yonetim.h"
#include <iostream>
Yonetim::Yonetim(Okul* okul)
{
	this->okul = okul;
}
void Yonetim::OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2)
{
	okul->OgrenciDegistir(ogrenciharfi1, ogrenciharfi2);
}
void Yonetim::sinifDegistir(char sinifsayisi1, char sinifsayisi2)
{
	okul->sinifDegistir(sinifsayisi1, sinifsayisi2);
}
Yonetim::~Yonetim()
{
	delete ogrenci, sinif, okul;
}
Yonetim::Yonetim()
{

}