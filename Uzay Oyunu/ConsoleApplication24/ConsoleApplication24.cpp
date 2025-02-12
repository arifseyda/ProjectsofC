/****************************************************************************
**								SAKARYA UNIVERSITESI
**							BILGISAYAR VE BILISIM FAKULTESI
**						  BILGISAYAR MUHENDISLIGI BOLUMU
**						    PROGRAMLAMAYA GIRIS DERSI
**
**				ODEV NUMARASI......:Odev Proje
**				OGRENCI ADI........:Arif Seyda OZCELIK
**				OGRENCI NUMARASI...:b171210393
**				DERS GRUBU.........:2/C
****************************************************************************/


#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
const double hızayari = 3.0;
double zamansayaci = 0;
clock_t suzaman = clock();
clock_t eskizaman = suzaman;
const int genislik = 80;
const int yukseklik = 20;
char sahne[genislik][yukseklik];
char tuslar[256];
class Sinirler
{
public:

	void gotoxy(int x, int y) 
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void sinirleriOlustur() //Sinirlari olusturur
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][0] = 219;
			sahne[x][yukseklik - 1] = 219;
		}
		for (int y = 0; y < yukseklik; y++)
		{
			sahne[0][y] = 219;
			sahne[genislik - 1][y] = 219;
		}
	}
	void kursorGizle() //Kursorun haraket etmesini engeller
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);
	}
	void sahneyiCiz() //Sinirlari console ekranına cizer
	{
		for (int y = 0; y < yukseklik; y++)
		{
			for (int x = 0; x < genislik; x++)
			{
				cout << sahne[x][y];
			}
			cout << endl;
		}
	}
	void sahneyiTemizle() //Sahneyi temizler
	{
		for (int y = 0; y < yukseklik; y++)
		{
			for (int x = 0; x < genislik; x++)
			{
				if (sahne[x][y]==char(219))
				{
					sahne[x][y] = ' ';
				}
			}
		}
	}
private:

};

class Ucak:public Sinirler
{
public:
	void ucagıOlustur() //Ucagi olusturur
	{
		kuyrukuzunlugu =5;
		ucak[0].x = 1;
		ucak[0].y = 6;
		ucak[1].x = 2;
		ucak[1].y = 7;
		ucak[2].x = 3;
		ucak[2].y = 8;
		ucak[3].x = 2;
		ucak[3].y = 9;
		ucak[4].x = 1;
		ucak[4].y = 10;
		ucak[0].karakter = ucakKarakteri;
		ucak[1].karakter = ucakKarakteri;
		ucak[2].karakter = ucakKarakteri;
		ucak[3].karakter = ucakKarakteri;
		ucak[4].karakter = ucakKarakteri;
	}

	void ucagiSahneyeYerlestir() //Ucagi sahneye yerlestirir
	{
		for (int i = 0; i < kuyrukuzunlugu; i++)
		{
			int x = ucak[i].x;
			int y = ucak[i].y;
			sahne[x][y] = ucak[i].karakter;
		}
	}
	void klavyeOku(char tuslar[]) //Klavye ile islem yapabilememize yardımcı olur
	{
		for (int x = 0; x < 256; x++)
		{
			tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
		}
	}
	void KlavyeKontrol() //Klavye hareketlerini olusturur
	{
		klavyeOku(tuslar);
		for (int i = 0; i < kuyrukuzunlugu; i++)
		{
			if (tuslar['W'] != 0)
			{
				ucak[i].yon = yyukari;
			}
			if (tuslar['S'] != 0)
			{
				ucak[i].yon = yasagı;
			}
		}
	}
	void ucagiHareketEttir() //Ucagın asagi yukari hareketini olusturur
	{
		for (int i = 0; i < kuyrukuzunlugu; i++)
		{
			switch (ucak[i].yon)
			{
			case yyukari:
				ucak[i].y--;
				break;
			case yasagı:
				ucak[i].y++;
				break;
			default:
				break;
			}
		}
		for (int i = kuyrukuzunlugu - 1; i > 0; i--)
		{
			ucak[i].yon = ucak[i - 1].yon;
		}
	}
	int ucagıdondurx()
	{
		return ucak[2].x;
	}
	int ucagıdondury()
	{
		return ucak[2].y;
	}
protected:
	enum Yon {
		yasagı = 1,
		yyukari = 2,
		ysag=3,
		ysol=4
	};
	const char ucakKarakteri = 219;
	struct UcakHucre
	{
		int x;
		int y;
		Yon yon;
		char karakter;
	};
	const int maxyucakUzunlugu=500;

	UcakHucre ucak[500];
	
	int kuyrukuzunlugu = 5;
};
class  Mermi 
{
public:
	void mermiyiharaketettir() //Mermiyi hareket ettirir
	{
		for (int y = 0; y < yukseklik; y++)
		{
			for (int x = 0; x < genislik; x++)
			{
				if (sahne[x][y] == mermikarakteri)
				{
					sahne[x][y] = ' ';
					sahne[x + 1][y] = mermikarakteri;
					x++;
				}
			}
		}
	}
private:
	const char mermikarakteri = 178;
	const char dusmankarakteri = 176;
};
class Dusman
{
public:
	void dusmanolustur() //dusmanlari random atar
	{
		int dusmanre = 2 + rand() % 16;
		sahne[genislik - 3][dusmanre - 1] = dusmankarakteri;
		sahne[genislik - 3][dusmanre + 1] = dusmankarakteri;
		sahne[genislik - 4][dusmanre - 1] = dusmankarakteri;
		sahne[genislik - 4][dusmanre + 1] = dusmankarakteri;
		sahne[genislik - 2][dusmanre - 1] = dusmankarakteri;
		sahne[genislik - 2][dusmanre + 1] = dusmankarakteri;
		sahne[genislik - 2][dusmanre] = dusmankarakteri;
		sahne[genislik - 4][dusmanre] = dusmankarakteri;
	}
	void dusmanHaraketettir() //dusmanlari hareket ettirir
	{
		for (int y = 0; y < yukseklik; y++)
		{
			for (int x = 0; x < genislik; x++)
			{
				if (sahne[x][y] == dusmankarakteri)
				{
					sahne[x][y] = ' ';
					sahne[x - 1][y] = dusmankarakteri;

				}
			}
		}
	}
	void çarpısma() //Mermi ile dusmanin carpısmasini saglar
	{
		for (int y = 0; y < yukseklik; y++)
		{
			for (int x = 0; x < genislik; x++)
			{
				if (sahne[x][y] == mermikarakteri)
				{
					if (sahne[x][y + 1] == dusmankarakteri || sahne[x][y + 2] == dusmankarakteri)
					{
						sahne[x - 2][y + 1] = ' ';
						sahne[x - 2][y + 2] = ' ';
						sahne[x - 2][y + 3] = ' ';
						sahne[x - 1][y + 1] = ' ';
						sahne[x - 1][y + 2] = ' ';
						sahne[x - 1][y + 3] = ' ';
						sahne[x][y + 1] = ' ';
						sahne[x][y + 2] = ' ';
						sahne[x][y + 3] = ' ';
						sahne[x + 1][y + 1] = ' ';
						sahne[x + 1][y + 2] = ' ';
						sahne[x + 1][y + 3] = ' ';
						sahne[x + 2][y + 1] = ' ';
						sahne[x + 2][y + 2] = ' ';
						sahne[x + 2][y + 3] = ' ';
					}
				}
				if (y == genislik - 1)
				{
					sahne[x][y] = ' ';
				}
			}
		}
	}
private:
	const char dusmankarakteri = 176;
	const char mermikarakteri = 178;
};



int main()
{
	Sinirler sinir;
	Ucak ucak;
	Mermi mermi;
	Dusman dusman;
	sinir.kursorGizle();
	ucak.ucagıOlustur();

	while (true)
	{
		suzaman = clock();
		zamansayaci += (double)(suzaman - eskizaman);
		eskizaman = suzaman;

		sinir.sinirleriOlustur();
		ucak.KlavyeKontrol();
		ucak.ucagiHareketEttir();
		ucak.ucagiSahneyeYerlestir();
		if (tuslar['D'] != 0)
		{
			sahne[ucak.ucagıdondurx() + 1][ucak.ucagıdondury()] = 178;
		}
		if (zamansayaci > (double)(hızayari * CLOCKS_PER_SEC))
		{
			zamansayaci = 0;
			dusman.dusmanolustur();
		}
		
		mermi.mermiyiharaketettir();
		dusman.çarpısma();
		dusman.dusmanHaraketettir();
		sinir.gotoxy(0, 0);
		sinir.sahneyiCiz();
		sinir.sahneyiTemizle();
		Sleep(75);
	}
	return 0;
}