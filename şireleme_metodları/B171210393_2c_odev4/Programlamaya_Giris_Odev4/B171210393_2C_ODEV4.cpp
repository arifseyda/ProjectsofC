/****************************************************************************
**								SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						  B�LG�SAYAR M�HEND�SL��� B�L�M�
**						    PROGRAMLAMAYA G�R��� DERS�
**
**				ODEV NUMARASI......:Odev 4
**				��RENC� ADI........:Arif Seyda OZCELIK
**				��RENC� NUMARASI...:b171210393
**				DERS GRUBU.........:2/C
****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include<cstring>
using namespace std;

class Sifre
{
private:
	char* alfabe = new char[1000];
	char* sifre = new char[1000];
	char* sifreKelimesi = new char[1000];
	char* sifreliMetin = new char[1000];
	char* cozulmusMetin = new char[1000];
	int alfabe_uzunluk = 0;
	int sifre_kelimesi_uzunluk = 0;
	int sifreli_metin_uzunluk = 0;
	int sifre_uzunluk = 0;
	char katar2[1000];
public:
	Sifre() //Bir alfabe de�eri at�yor e�er alfabeyi de�i�tirmek istiyorsak onun i�inde se�enek veriyor ve �ifre metnini al�yor.
	{
		int secim = 0;
		char katar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		while (true)
		{
			cout << "Yeni Alfabe Girmek Icin (1), Varsayilan Alfabeyi Kullanmak Icin (2) Seciniz: ";
			cin >> secim;
			if (secim == 1)
			{
				cout.setf(ios::left);
				cout << setw(22) << "ALFABE" << setw(2) << ":";
				cin >> katar;
				if (AlfabeKontrol(katar))
				{
					strcpy_s(alfabe, sizeof(katar), katar);
				}
				else
				{
					cout << "Alfabede Tekrarlanan Karakterler Mevcut." << endl;
					continue;
				}
				cout.setf(ios::left);
				cout << setw(22) << "SIFRE" << setw(2) << ": ";
				cin >> katar2;
				int boyut = 0;
				while (katar2[boyut++] != 0);
				if (SifreKontrol(katar2))
				{
					strcpy_s(sifre, boyut, katar2);
					break;
				}
				else
					cout << "Sifredeki Karakterler Alfabede Mevcut Degil." << endl;
			}
			else if (secim == 2)
			{
				strcpy_s(alfabe, sizeof(katar), katar);
				cout.setf(ios::left);
				cout << setw(22) << "SIFRE" << setw(2) << ": ";
				cin >> katar2;
				int boyut = 0;
				while (katar2[boyut++] != 0);
				if (SifreKontrol(katar2))
				{
					strcpy_s(sifre, boyut, katar2);
					break;
				}
				else
					cout << "Sifredeki Karakterler Alfabede Mevcut Degil." << endl;
			}
			else
			{
				cout << "Yalnis Secim Yaptiniz:" << endl;
			}
		}
	}

	Sifre(char* alfabe, char* sifre)
	{
		this->alfabe = alfabe;
		this->sifre = sifre;
	}
	 
	char* sifrele(char* sifrelenecekMetin) //�ifreleme i�lemini yap�yor
	{
		int deger = 0;
		int index = 0;
		for (int i = 0; i < sifreli_metin_uzunluk; i++)
		{
			deger = AlfabeHarf(sifrelenecekMetin[i]) + AlfabeHarf(sifreKelimesi[i]);
			if (deger > 26)
				deger -= 26;
			sifreliMetin[i] = AlfabeSayi(deger);
			index++;
		}
		sifreliMetin[index] = 0;
		return sifreliMetin;
	}

	char* sifrecoz(char* sifreliMetin) //�ifrelenmi� metini ��z�yor
	{
		int deger = 0;
		int index = 0;
		for (int i = 0; i < sifreli_metin_uzunluk; i++)
		{
			deger = AlfabeHarf(sifreliMetin[i]) - AlfabeHarf(sifreKelimesi[i]);
			if (deger < 1)
				deger += 26;
			cozulmusMetin[i] = AlfabeSayi(deger);
			index++;
		}
		cozulmusMetin[index] = 0;
		return cozulmusMetin;
	}

	void sifreKelimeAta(char* sifrelenecekMetin) //Sifrenin uzulunlugunu girilecek metin kadar yapmaya yard�mc� oluyor
	{
		for (int i = 0; i < sifrelenecekMetin[i] != 0; i++)
		{
			sifreli_metin_uzunluk++;
		}
		int count1 = sifreli_metin_uzunluk / sifre_uzunluk;
		int count2 = sifreli_metin_uzunluk % sifre_uzunluk;
		int a = 0;
		for (int k = 0; k < count1; k++)
		{
			for (int i = 0; i < sifre_uzunluk; i++)
			{
				sifreKelimesi[a++] = sifre[i];
			}
		}
		for (int l = 0; l < count2; l++)
		{
			sifreKelimesi[a++] = sifre[l];
		}
		sifreKelimesi[a] = '\0';
	}

	int length()
	{
		return sifreli_metin_uzunluk;
	}

	int AlfabeHarf(char harf) //Harfleri d�nd�rt�yor
	{
		if (harf == 'A' || harf == 'a')
			return 1;
		else if (harf == 'B' || harf == 'b')
			return 2;
		else if (harf == 'C' || harf == 'c')
			return 3;
		else if (harf == 'D' || harf == 'd')
			return 4;
		else if (harf == 'E' || harf == 'e')
			return 5;
		else if (harf == 'F' || harf == 'f')
			return 6;
		else if (harf == 'G' || harf == 'g')
			return 7;
		else if (harf == 'H' || harf == 'h')
			return 8;
		else if (harf == 'I' || harf == 'i')
			return 9;
		else if (harf == 'J' || harf == 'j')
			return 10;
		else if (harf == 'K' || harf == 'k')
			return 11;
		else if (harf == 'L' || harf == 'l')
			return 12;
		else if (harf == 'M' || harf == 'm')
			return 13;
		else if (harf == 'N' || harf == 'n')
			return 14;
		else if (harf == 'O' || harf == 'o')
			return 15;
		else if (harf == 'P' || harf == 'p')
			return 16;
		else if (harf == 'Q' || harf == 'q')
			return 17;
		else if (harf == 'R' || harf == 'r')
			return 18;
		else if (harf == 'S' || harf == 's')
			return 19;
		else if (harf == 'T' || harf == 't')
			return 20;
		else if (harf == 'U' || harf == 'u')
			return 21;
		else if (harf == 'V' || harf == 'v')
			return 22;
		else if (harf == 'W' || harf == 'w')
			return 23;
		else if (harf == 'X' || harf == 'x')
			return 24;
		else if (harf == 'Y' || harf == 'y')
			return 25;
		else if (harf == 'Z' || harf == 'z')
			return 26;
	}

	char AlfabeSayi(int sayi) 
	{
		if (sayi == 1)
			return 'A';
		else if (sayi == 2)
			return 'B';
		else if (sayi == 3)
			return 'C';
		else if (sayi == 4)
			return 'D';
		else if (sayi == 5)
			return 'E';
		else if (sayi == 6)
			return 'F';
		else if (sayi == 7)
			return 'G';
		else if (sayi == 8)
			return 'H';
		else if (sayi == 9)
			return 'I';
		else if (sayi == 10)
			return 'J';
		else if (sayi == 11)
			return 'K';
		else if (sayi == 12)
			return 'L';
		else if (sayi == 13)
			return 'M';
		else if (sayi == 14)
			return 'N';
		else if (sayi == 15)
			return 'O';
		else if (sayi == 16)
			return 'P';
		else if (sayi == 17)
			return 'Q';
		else if (sayi == 18)
			return 'R';
		else if (sayi == 19)
			return 'S';
		else if (sayi == 20)
			return 'T';
		else if (sayi == 21)
			return 'U';
		else if (sayi == 22)
			return 'V';
		else if (sayi == 23)
			return 'W';
		else if (sayi == 24)
			return 'X';
		else if (sayi == 25)
			return 'Y';
		else if (sayi == 26)
			return 'Z';
	}
	bool AlfabeKontrol(char* alfabe) //Alfabe icin girilen harfler ayn�ysa hata verdirmesini sa�l�yor
	{
		for (int i = 0; i < alfabe[i] != 0; i++)
		{
			alfabe_uzunluk++;
		}
		for (int i = 0; i < alfabe_uzunluk; i++)
		{
			for (int j = 0; j < alfabe_uzunluk; j++)
			{
				if (i != j)
				{
					if (alfabe[i] == alfabe[j])
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	bool SifreKontrol(char* sifre) //�ifre de girilen metindeki harfler ayn� ise bunlar�n kontrolunu sa�l�yor.
	{
		bool bayrak = true;
		for (int i = 0; i < sifre[i] != 0; i++)
		{
			sifre_uzunluk++;
		}
		for (int i = 0; i < alfabe[i] != 0; i++)
		{
			alfabe_uzunluk++;
		}
		for (int i = 0; i < sifre_uzunluk; i++)
		{
			for (int j = 0; j < alfabe_uzunluk; j++)
			{
				if (sifre[i] == alfabe[j])
				{
					bayrak = true;
					break;
				}
				else
					bayrak = false;
			}
		}
		return bayrak;
	}

	~Sifre()
	{
		delete alfabe;
		delete sifre;
		delete sifreKelimesi;
		delete sifreliMetin;
		delete cozulmusMetin;
	}
};


int main()
{
	Sifre *sifre = new Sifre();
	unsigned int yaziBoyutu = 1000;

	char* sifrelenecek_metin = new char[yaziBoyutu];
	char* sifreli_metin;
	char* cozulmus_metin;
	cout.setf(ios::left);
	cout << setw(22) << "METIN" << setw(2) << ":";

	cin >> sifrelenecek_metin;

	sifre->sifreKelimeAta(sifrelenecek_metin);

	cout.setf(ios::left);

	cout << setw(22) << "SIFRELENMIS METIN" << setw(2) << ":";

	sifreli_metin = sifre->sifrele(sifrelenecek_metin);

	for (int i = 0; i < sifre->length(); i++)
	{
		cout << sifreli_metin[i];
	}
	cout.setf(ios::left);
	cout << endl << setw(22) << "DESIFRE METIN" << setw(2) << ":";
	cozulmus_metin = sifre->sifrecoz(sifreli_metin);
	for (int i = 0; i < sifre->length(); i++)
	{
		cout << cozulmus_metin[i];
	}
	cout << endl;
	delete sifrelenecek_metin;
	delete sifre;
	system("pause");
	return 0;

}

