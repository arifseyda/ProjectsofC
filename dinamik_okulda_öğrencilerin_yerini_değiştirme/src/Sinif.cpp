/*
*@file               Sinif.cpp
*@description        Ogrenci ve ogrenci adreslerini ogrenci ekle metodu ile ekleme yapıyor
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#include "Sinif.h"
#include "Ogrenci.h"
#include <iostream>
Sinif::Sinif(int sinifNo,int ogrSayisi) 
	{
		ogrenci = new Ogrenci*[ogrSayisi];
		sinifNumarasi = sinifNo;
		siradakiOgrenci = 0;
	
	}
	Sinif::~Sinif()
	{
		delete ogrenci;
	}
	int Sinif::sinifGetir()
	{
		return sinifNumarasi;
	}
	int Sinif::ogrenciSayisi()
	{
		return siradakiOgrenci;
	}
	void Sinif::ogrenciEkle(char adi)
	{
		ogrenci[siradakiOgrenci++] = new Ogrenci(adi);
	}
	Sinif::Sinif()
	{
		siradakiOgrenci = 0;
	}
	void Sinif::OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2)
	{
		int o1 = -1, o2 = -1;
		for (int i = 0; i < ogrenciSayisi(); i++)
		{
			if (ogrenci[i]->harfGetir() == ogrenciharfi1)
				o1 = i;
			else if (ogrenci[i]->harfGetir() == ogrenciharfi2)
				o2 = i;
			
		}
		if (o1 == -1 || o2 == -1)
		{
			return;
		}
		Ogrenci* yedek1 = ogrenci[o1];
		ogrenci[o1] = ogrenci[o2];
		ogrenci[o2] = yedek1;
	}
	
