/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:2 ÖDEV
**				ÖĞRENCİ ADI......:Arif Seyda ÖZÇELİK
**				ÖĞRENCİ NUMARASI.:B171210393
**				DERS GRUBU…………...:2/C
****************************************************************************/


#include "pch.h"
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <cstdlib>


using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");
	const int boyut = 200;
	char harfler[boyut];
	cout << "200 Harflik Cumle Giriniz: ";
	cin.get(harfler, boyut);
	int sayacA=0, sayacE=0 , sayacU=0 , sayacÜ =0, sayacO = 0, sayacÖ = 0, sayacI = 0, sayacİ = 0;
	int toplamSayi=0,sayacBosluk=0;
	do
	{
			for (int i = 0;i<boyut; i++) 
			{
				if (harfler[i] == 'A' || harfler[i] == 'a')//a sayısını yazarsak sayacA yı artırır
				{
					sayacA++;
				}
				else if (harfler[i] == 'E' || harfler[i] == 'e') //e sayısını yazarsak sayacE yı artırır
				{
					sayacE++;
				}
				else if (harfler[i] == 'O' || harfler[i] == 'o')//o sayısını yazarsak sayacO yı artırır
				{
					sayacO++;
				}
				else if (harfler[i] == 'U' || harfler[i] == 'u')//u sayısını yazarsak sayacU yı artırır
				{
					sayacU++;
				}
				else if (harfler[i] ==(int)-127 || harfler[i] ==(int)-102 )//ü sayısını yazarsak sayacÜ yı artırır
				{
					sayacÜ++;
				}
				else if (harfler[i] == (int)-108 || harfler[i] == (int)-103)//ö sayısını yazarsak sayacÖ yı artırır
				{
					sayacÖ++;
				}
				else if (harfler[i] == 'i' || harfler[i] == (int)-104)//i sayısını yazarsak sayacİ yı artırır
				{
					sayacİ++;
				}
				else if (harfler[i] == 'I' || harfler[i] == (int)-115)//ı sayısını yazarsak sayacI yı artırır
				{
					sayacI++;
				}
				else if (harfler[i]=='\0') //cumle nin uzunlugunun bitiminde calısmayı durdurur
				{
					break;
					
				}
				else if (harfler[i]=' ')
				{
					sayacBosluk++;
				}
				
			}
	} while (harfler[boyut]=='\0');
	toplamSayi = sayacA + sayacE + sayacI + sayacİ + sayacO + sayacÖ + sayacU + sayacÜ +sayacBosluk;
	cout << "H" << "  " << "TS";
	for (int j = 1; j <= toplamSayi; j++) //10 tane sayıyı yan yana yazıyor
	{
		cout << " " << j;
	}
	cout << endl;
	cout << "a  " << sayacA << " ";
	for (int k = 0; k < sayacA; k++) //A sayısını ve sayacA kadar a yazdırır
	{
		cout << " " << "a";
	}
	cout << endl;
	cout << "e  " << sayacE << " ";
	for (int k = 0; k < sayacE; k++) //E sayısını ve sayacE kadar e yazdırır
	{
		cout << " " << "e";
	}
	cout << endl;
	cout << "u  " << sayacU << " ";
	for (int k = 0; k < sayacU; k++)//U sayısını ve sayacU kadar u yazdırır
	{
		cout << " " << "u";
	}
	cout << endl;
	cout << "o  " << sayacO << " ";
	for (int k = 0; k < sayacO; k++)//O sayısını ve sayacO kadar o yazdırır
	{
		cout << " " << "o";
	}
	cout << endl;
	cout << "ü  " << sayacÜ << " ";
	for (int k = 0; k < sayacÜ; k++)//Ü sayısını ve sayacÜ kadar ü yazdırır
	{
		cout << " " << "ü";
	}
	cout << endl;
	cout << "ö  " << sayacÖ << " ";
	for (int k = 0; k < sayacÖ; k++)//Ö sayısını ve sayacÖ kadar ö yazdırır
	{
		cout << " " << "ö";
	}
	cout << endl;
	cout << "i  " << sayacİ << " ";
	for (int k = 0; k < sayacİ; k++)//İ sayısını ve sayacİ kadar i yazdırır
	{
		cout << " " << "i";
	}
	cout << endl;
	cout << "ı  " << sayacI << " ";
	for (int k = 0; k < sayacI; k++)//I sayısını ve sayacI kadar ı yazdırır
	{
		cout << " " << "ı";
	}
	cout << endl;
	
	cout << endl;
	system("pause");
	return 0;

}