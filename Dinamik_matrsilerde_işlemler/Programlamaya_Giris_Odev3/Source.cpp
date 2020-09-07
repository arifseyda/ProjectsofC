/****************************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**						    PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI......:Odev 2
**				ÖÐRENCÝ ADI........:Arif Seyda ÖZÇELÝK
**				ÖÐRENCÝ NUMARASI...:b171210393
**				DERS GRUBU.........:2/C
****************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

const int girisboyutu = 6;
//Ýþlem structý
struct Islem 
{
	int GirisMatris[girisboyutu][girisboyutu] =
	{
		0,0,0,0,0,0,
		0,2,1,0,1,0,
		0,0,3,5,0,0,
		0,4,1,1,0,0,
		0,0,0,5,3,0,
		0,0,0,0,0,0
	};
	int KaymaMiktari = 0;
	int CekirdekBoyutu = 0;
	int SonucMatrisBoyutu = 0;
}islem;

void SonucMatrisOlustur(int**);// Sonuc Matrisi olusturur
void CekirdekMatrisOlustur(const int); //Cekirdek matrisi oluþturur

int main()
{
	cout << "Cekirdek Boyutunu Giriniz: ";
	cin >> islem.CekirdekBoyutu;
	cout << "Kayma Miktarini Giriniz: ";
	cin >> islem.KaymaMiktari;
	CekirdekMatrisOlustur(islem.CekirdekBoyutu);

	system("pause");
	return 0;
}
void CekirdekMatrisOlustur(const int Cekirdek_Boyutu)
{
	if ((girisboyutu - islem.CekirdekBoyutu) % islem.KaymaMiktari == 0)
	{
		int** Cekirdek_Matris = new int*[Cekirdek_Boyutu];
		for (int i = 0; i < Cekirdek_Boyutu; i++)
			Cekirdek_Matris[i] = new int[Cekirdek_Boyutu];

		for (int i = 0; i < Cekirdek_Boyutu; i++)//Cekirdek matrisi kullanýcadan alýr
		{
			for (int j = 0; j < Cekirdek_Boyutu; j++)
			{
				cout << "Cekirdek[" << i << "][" << j << "]=";
				cin >> Cekirdek_Matris[i][j];
			}
		}
		cout << endl << "Cekirdek Matris:" << endl; //Cekirdek boyutu Yazdýrýr
		for (int i = 0; i < Cekirdek_Boyutu; i++)
		{
			for (int j = 0; j < Cekirdek_Boyutu; j++)
			{
				cout.setf(ios::left);
				cout << setw(10) << Cekirdek_Matris[i][j];
			}
			cout << endl;
		}
		SonucMatrisOlustur(Cekirdek_Matris);
	}
	else
		cout << "Islem Yapilamaz. Cekirdek Boyutu Islem Icin Uygun Degil" << endl;
}
void SonucMatrisOlustur(int** Cekirdek_Matris)
{
	islem.SonucMatrisBoyutu = ((girisboyutu - islem.CekirdekBoyutu) / islem.KaymaMiktari) + 1; 

	int** Sonuc_Matris = new int*[islem.SonucMatrisBoyutu];
	for (int i = 0; i < islem.SonucMatrisBoyutu; i++)
		Sonuc_Matris[i] = new int[islem.SonucMatrisBoyutu];

	for (int i = 0; i < islem.SonucMatrisBoyutu; i++) //Sonuc Matrise 0 atýyoruz
	{
		for (int j = 0; j < islem.SonucMatrisBoyutu; j++)
		{
			Sonuc_Matris[i][j] = 0;
		}
	}

	int a = 0, b = 0, eski_konumA = 0, eski_konumB = 0;
	for (int i = 0; i < islem.SonucMatrisBoyutu; i++) //Sonuc matrisi oluþturmaya yarar
	{
		for (int j = 0; j < islem.SonucMatrisBoyutu; j++)
		{
			for (int c = 0; c < islem.CekirdekBoyutu; c++, a++)
			{
				for (int d = 0; d < islem.CekirdekBoyutu; d++, b++)
				{
					Sonuc_Matris[i][j] += islem.GirisMatris[a][b] * (Cekirdek_Matris[c][d]);
				}
				b = eski_konumB;
			}
			b = eski_konumB + islem.KaymaMiktari;
			eski_konumB = b;
			a = eski_konumA;
		}
		a = eski_konumA + islem.KaymaMiktari;
		eski_konumA = a;
		b = 0; eski_konumB = 0;
	}


	cout << endl << "Cikis Matris:" << endl;
	for (int i = 0; i < islem.SonucMatrisBoyutu; i++) //Sonuc matrisini Yazdýrýr
	{
		for (int j = 0; j < islem.SonucMatrisBoyutu; j++)
		{
			cout.setf(ios::left);
			cout << setw(10) << Sonuc_Matris[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < islem.CekirdekBoyutu; i++) //Çekirdek matrisi heap'den siler
	{
		delete Cekirdek_Matris[i];
	}
	delete Cekirdek_Matris;
	for (int i = 0; i < islem.SonucMatrisBoyutu; i++) //Sonuc matrisini heap'den siler
	{
		delete Sonuc_Matris[i];
	}
	delete Sonuc_Matris;
}