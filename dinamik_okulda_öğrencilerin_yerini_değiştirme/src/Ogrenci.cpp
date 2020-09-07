/*
*@file               Ogrenci.cpp
*@description        Sinifin harf almasını sağlıyor
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#include "Ogrenci.h"
#include <iostream>
Ogrenci::Ogrenci(char harf)
{
	Harf = harf;
}
Ogrenci::Ogrenci()
{

}
char Ogrenci::harfGetir()
{
	return Harf;
}
Ogrenci::~Ogrenci()
{

}
