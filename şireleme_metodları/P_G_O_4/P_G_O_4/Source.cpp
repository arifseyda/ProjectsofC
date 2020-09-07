#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Sifre
{

private:
	string alfabe = "";
	string sifre = "";
	string sifreKelimesi = "";
	string sifreliMetin = "";
	string cozulmusMetin = "";
public:
	Sifre()
	{
		int secim = 0;
		string katar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string katar2;
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
					alfabe = katar;
				}
				else
				{
					cout << "Alfabede Tekrarlanan Karakterler Mevcut." << endl;
					continue;
				}
				cout.setf(ios::left);
				cout << setw(22) << "SIFRE" << setw(2) << ": ";
				cin >> katar2;
				if (SifreKontrol(katar2))
				{
					sifre = katar2;
					break;
				}
				else
					cout << "Sifredeki Karakterler Alfabede Mevcut Degil." << endl;
			}
			else if (secim == 2)
			{
				alfabe = katar;
				cout.setf(ios::left);
				cout << setw(22) << "SIFRE" << setw(2) << ": ";
				cin >> katar2;
				if (SifreKontrol(katar2))
				{
					sifre = katar2;
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

	Sifre(string alfabe, string sifre)
	{
		this->alfabe = alfabe;
		this->sifre = sifre;
	}

	string sifrele(string sifrelenecekMetin)
	{
		int deger = 0;
		for (int i = 0; i < sifrelenecekMetin.length(); i++)
		{
			deger = AlfabeHarf(sifrelenecekMetin[i]) + AlfabeHarf(sifreKelimesi[i]);
			if (deger > 26)
				deger -= 26;
			sifreliMetin += AlfabeSayi(deger);
		}
		return sifreliMetin;
	}

	string sifrecoz(string sifreliMetin)
	{
		int deger = 0;
		for (int i = 0; i < sifreliMetin.length(); i++)
		{
			deger = AlfabeHarf(sifreliMetin[i]) - AlfabeHarf(sifreKelimesi[i]);
			if (deger < 1)
				deger += 26;
			cozulmusMetin += AlfabeSayi(deger);
		}
		return cozulmusMetin;
	}

	void sifreKelimeAta(string sifrelenecekMetin)
	{
		int count1 = sifrelenecekMetin.length() / sifre.length();
		int count2 = sifrelenecekMetin.length() % sifre.length();
		int a = 0;
		for (int k = 0; k < count1; k++)
		{
			for (int i = 0; i < sifre.length(); i++)
			{
				sifreKelimesi += sifre[i];
			}
		}
		for (int l = 0; l < count2; l++)
		{
			sifreKelimesi += sifre[l];
		}
	}

	int lenght()
	{
		return sifreliMetin.length();
	}

	int AlfabeHarf(char harf)
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

	bool AlfabeKontrol(string alfabe)
	{
		for (int i = 0; i < alfabe.length(); i++)
		{
			for (int j = 0; j < alfabe.length(); j++)
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

	bool SifreKontrol(string sifre)
	{
		bool bayrak = true;
		for (int i = 0; i < sifre.length(); i++)
		{
			for (int j = 0; j < alfabe.length(); j++)
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
};


int main()
{
	Sifre sifre;
	string sifrelenecek_metin;
	string sifreli_metin;
	string cozulmus_metin;
	cout.setf(ios::left);
	cout << setw(22) << "METIN" << setw(2) << ":";
	cin >> sifrelenecek_metin;
	sifre.sifreKelimeAta(sifrelenecek_metin);
	sifreli_metin = sifre.sifrele(sifrelenecek_metin);
	cout.setf(ios::left);
	cout << setw(22) << "SIFRELENMIS METIN" << setw(2) << ":" << sifreli_metin << endl;
	cozulmus_metin = sifre.sifrecoz(sifreli_metin);
	cout.setf(ios::left);
	cout << setw(22) << "DESIFRE METIN" << setw(2) << ":" << cozulmus_metin << endl;
	system("pause");
	return 0;

}