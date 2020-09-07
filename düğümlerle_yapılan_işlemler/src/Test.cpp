#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "Yonetim.hpp"
#include "Dugum.hpp"
#include "Stack.hpp"
#include "CiftYonluBagilListe.hpp"
using namespace std;
int main()
{
	Node *LB =NULL;
	Node *LS=NULL;
	Node *Yedek;
	int dugumsayim = 0;
	CiftYonluBagilListe *liste = NULL;
	string oku;
	string read;
	Yonetim y1;
	ifstream fileRead("Sayi.txt", ios::in);
	while (!fileRead.eof())
	{
		std::getline(fileRead, read);
		fileRead >> read;
		for (int i = 0; i <= read.length(); i++)
		{
			if (read[i]==' ')
			{
				if (dugumsayim==0)
				{
					LB = new Node(stoi(oku));
					liste->ilkEleman(LB);
					liste->soneleman(LB);
					oku = "";
					dugumsayim++;
				}
				else
				{
					Yedek = LB;
					while (Yedek->getPnext()!=LB)
					{
						Yedek = Yedek->getPnext();
					}
					Yedek->setPnext(new Node(stoi(oku)));
					liste->degerata(Yedek);
					liste->degeratama2(LB, Yedek);
					liste->degeratama3(LB, Yedek);
					liste->degeratama4(LB, LS);
					oku = "";
					dugumsayim++;
				}
			}
			else
			{
				oku += read[i];
			}
		}
	}
	Yedek = LB;
	while (Yedek->getPnext() != LB)
	{
		Yedek = Yedek->getPnext();
	}
	Yedek->setPnext(new Node(stoi(oku)));
	Yedek->getPnext()->setPrev(Yedek);
	Yedek->getPnext()->setPnext(LB);
	LB->setPrev(Yedek->getPnext());
	LS = LB->getPprev();
	dugumsayim++;
	fileRead.close();
	int istdugum=0;
	int secim;
	do
	{
		cout << "1. Sola Hareket" << endl;
		cout << "2. Saga Hareket" << endl;
		cout << "3. Bir Dugumun Durumlarini Yazdir" << endl;
		cout << "4. Tum Durumlari Yazdir " << endl;
		cout << "5. Cikis" << endl;
		cout << "Seciminizi giriniz: ";
		cin >> secim;
		switch (secim)
		{
		case 1:
			cout<<"Liste basi elemanindan sonraki 12 elemanini 850 olarak yaziyor"<<endl;
			y1.solaKaydir(LB, oku, dugumsayim);
			oku = y1.oku;
			break;
		case 2:
			y1.sagaKaydir(LB,oku,dugumsayim);
			oku = y1.oku;
			break;
		case 3:
			y1.dugumKonumu(istdugum, LB,oku);
			break;
		case 4:
			y1.hepsiniyazdir(LB);
			break;
		case 5:
			break;
		default:
			cout << "Yanlis Seçim" << endl;
			break;
		}

	} while (secim!=5);
	delete LB,LS,Yedek;
	delete liste;
	exit(0);
	return 0;
}