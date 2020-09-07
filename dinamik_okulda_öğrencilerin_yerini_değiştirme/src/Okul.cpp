/*
*@file               Okul.cpp
*@description        Sınıf ve ogrencileri yazdırıyor ve ogrenci degiştir ve sinif degiştir işlemlerini yapıyor
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/

#include "Okul.h"
#include "Sinif.h"
#include <iostream>


Okul::Okul(int sinifSayisi) //sadece ogrenci sayısı
	{
		SinifDizisi = new Sinif*[sinifSayisi];
		this->sinifSayisi = sinifSayisi;

		siradakiSinif = 0;
		maxogrsayi=0;

	}
	Okul::~Okul()
	{
		delete SinifDizisi, yedek2;
	}

	void Okul::Yazdir(int ogrsayi)
	{

		for (int i = 0; i < sinifSayisi; i++)
		{
			cout << "Sinif: " << SinifDizisi[i]->sinifGetir() << "         ";

		}cout << endl;
		
		for (int i = 0; i < sinifSayisi; i++)
		{
			if (SinifDizisi[i]->ogrenciSayisi() > ogrsayi)
			{
				ogrsayi = SinifDizisi[i]->ogrenciSayisi();
			}
		}
		
		for (int i = 0; i < ogrsayi; i++)
		{
			for (int y = 0; y < sinifSayisi; y++)
			{
				if (SinifDizisi[y]->ogrenciSayisi() <= i)
				{
					cout << "                ";
					continue;
				}
				
				cout << SinifDizisi[y]->ogrenci[i]->harfGetir() << "     " << SinifDizisi[y]->ogrenci[i] << "  ";
			}
			cout << endl;
		}

	}

	Okul::Okul()
	{
		siradakiSinif = 0;
		sinifSayisi = 0;
	}

	/*void Okul::OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2,int maxogrsayi)
	{
		
		int x1=-1, x2=-1, y1=-1, y2=-1;
		
		for (int i = 0; i < sinifSayisi; i++)
		{
		
			for (int y = 0; y < ogrenciSayisi; y++)
			{
				if (SinifDizisi[i]->ogrenciSayisi() <= y)
				{
					break;
				}
				if (SinifDizisi[i]->ogrenci[y]->harfGetir() == ogrenciharfi1)
				{
					x1 = i;
					y1 = y;
				}
				if (SinifDizisi[i]->ogrenci[y]->harfGetir() == ogrenciharfi2)
				{
					x2 = i;
					y2 = y;
				}
			}
		}
		if (x1 == -1 || x2 == -1||y1==-1||y2==-1)
		{
			return;
		}
		Ogrenci *yedek1 = SinifDizisi[x1-1]->ogrenci[y1-1];
		SinifDizisi[x1-1]->ogrenci[y1-1] = SinifDizisi[x2-1]->ogrenci[y2-1];
		SinifDizisi[x2-1]->ogrenci[y2-1] = yedek1;
		
	}*/
	void Okul::OgrenciDegistir(char ogrenciharfi1, char ogrenciharfi2)
	{
		for (int i = 0; i < sinifSayisi; i++)
		{
			SinifDizisi[i]->OgrenciDegistir(ogrenciharfi1, ogrenciharfi2);
			
		}
		
	}
	void Okul::sinifDegistir(int sinifsayisi1, int sinifsayisi2)
	{
		yedek2 = SinifDizisi[sinifsayisi1 - 1];
		SinifDizisi[sinifsayisi1 - 1] = SinifDizisi[sinifsayisi2 - 1];
		SinifDizisi[sinifsayisi2 - 1] = yedek2;
	}
	void Okul::sinifEkle(Sinif* yeni)
	{
		SinifDizisi[siradakiSinif++] = yeni;
	}