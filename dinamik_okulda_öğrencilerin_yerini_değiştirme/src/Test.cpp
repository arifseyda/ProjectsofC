/*
*@file               Test.cpp
*@description        Dosya islemleri ve seçim işlemlerini yapıyor
*@course             Veri Yapıları 1/C
*@assigment          1. Odev
*@date               30.10.2018
*@outhor             Arif Seyda Özçelik  arif.ozcelik@ogr.sakarya.edu.tr /Hüseyin Halid Özkılıç     huseyin.ozkilic@ogr.sakarya.edu.tr
*/


#include "Yonetim.h"
#include "Ogrenci.h"
#include "Sinif.h"
#include "Okul.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int main()
{
	
	string veriler;
	string oku;
	int sinifNumara;
	int ogrenciSayisi;
	char harfler;
	int sinifSayisi = 0;
	int atamasayim = 0;
	char satiradisinif;
	int okunansatir = 0;
	int atananogr = 0;
	int parametreson = 0;
	ifstream dosyaOku("okul.txt");
	while (std::getline(dosyaOku, oku))
	{
		sinifSayisi++;
	}
	dosyaOku.close();
	dosyaOku.open("okul.txt");
	Okul  *o1 = new Okul(sinifSayisi);
	
	
	while (std::getline(dosyaOku, oku))
	{
		
		stringstream ss(oku);
		stringstream dd(oku);
		
		ss >> sinifNumara;
		
		
		ogrenciSayisi = 0;
		
		while (ss >> harfler)
		{
			ogrenciSayisi++;
		}
		
		o1->sinifEkle(new Sinif(sinifNumara,ogrenciSayisi));
		
		
		dd >> sinifNumara;
		
		while (dd >> harfler)
		{
			
			o1->SinifDizisi[atamasayim]->ogrenciEkle(harfler);
			
		}		
		
		atamasayim++;
	}
	
	int sinifsayisi1, sinifsayisi2;
	char ogrenci1, ogrenci2;
	
	o1->Yazdir(parametreson - 1);
	
	Yonetim *y = new Yonetim(o1);
	
	int secim;
	do
	{
		cout << "1. Sinif Degistir" << endl;
		cout << "2. Ogrenci Degistir" << endl;
		cout << "3. Cikis" << endl;
		cout << "=> ";
		
		cin >> secim;
		switch (secim)
		{
		case 1:
			
			cout << "1. Sinif Adi: ";
			cin >> sinifsayisi1;
			cout << "2. Sinif Adi: ";
			cin >> sinifsayisi2;
			y->sinifDegistir(sinifsayisi1, sinifsayisi2);
			o1->Yazdir(parametreson - 1);
			break;
		case 2:
			
			cout << "1. Ogrenci: ";
			cin >> ogrenci1;
			cout << "2. Ogrenci: ";
			cin >> ogrenci2;
			y->OgrenciDegistir(ogrenci1, ogrenci2);
			cout<<"Ayni sinifin icersinde ogrenci degistiriyor"<<endl;
			o1->Yazdir(parametreson - 1);
			break;
		case 3:
			break;
		default: cout << "Oyle bir islem bulunmamaktadir" << endl;
			cout << "=> ";

			break;
		}
		
	} while (secim != 3);

	delete o1, y;

	return 0;

}