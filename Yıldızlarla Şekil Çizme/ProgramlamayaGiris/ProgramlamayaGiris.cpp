/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1.ÖDEV
**				ÖĞRENCİ ADI......:Arif Seyda ÖZÇELİK
**				ÖĞRENCİ NUMARASI.:B171210393
**				DERS GRUBU…………....:2/C
****************************************************************************/

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int sayac = -1;
	for (int i = 6; i >0; i--) 
	{
		sayac = sayac + 2;
		for (int j = i-1; j >0 ; j--) //soldaki yıldızları atıyor
		{
			cout << " * ";
		}
		for (int k = 0; k < sayac; k++) //soldaki ve sagdaki yıldızların arasındaki boslukları atıyor
		{
			cout << "   ";
		}
		for (int l = i-1; l >0; l--) //sagdaki yıldızları atıyor
		{
			cout << " * ";
		}
		if (i==1) //i 1 olunca dongüden çıkıyor
		{
			break;
		}
		cout << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++) //soldaki yıldızları atıyor
		{
			cout << " * ";
		}
		for (int k = 0; k < sayac; k++) //soldaki ve sagdaki yıldızların arasındaki boslukları atıyor
		{
			cout << "   ";
		}
		for (int l = 0; l <i; l++)  //sagdaki yıldızları atıyor
		{
			cout << " * ";
		}
		sayac =sayac-2;
		cout << endl;
	}
	system("pause");
	return 0;
}

