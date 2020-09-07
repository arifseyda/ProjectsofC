#include "Yonetim.hpp"
#include "Dugum.hpp"
#include <iomanip>
#include <iostream>
#include <string>
	Yonetim::~Yonetim() 
	{
		delete Yedek;
		delete LB;
		delete LS;
	}
	ostream& operator<<(ostream& ekran, Yonetim &sag) {
		
		return ekran;
	}
	void Yonetim::dugumKonumu(int istdugum, Node *LB,string okuma)  
	{
		int xx = 1;
		cout << "Dugum Konumu: ";
		cin >> istdugum;
		Yedek = LB;
		string yeniDeger = okuma;
		while (xx<= istdugum)
		{
			string onceki = to_string(Yedek->getData());
			yeniDeger = onceki;
			Yedek = Yedek->getPnext();
			xx++;
		}
		cout << Yedek->getData();
		Yedek->dugumYaz();
		cout << endl;
		yeniDeger;
		cout << endl;
	}
	void Yonetim::hepsiniyazdir(Node* listeb)
	{
		
		Yedek = listeb;
		while (Yedek->getPnext() != listeb)
		{
			cout <<setw(4) <<Yedek->getData();
			Yedek->dugumYaz();
			cout<<endl;
			Yedek = Yedek->getPnext();
		}
		cout <<setw(4) <<Yedek->getData();
		Yedek->dugumYaz();
		cout << endl;
	}
	void Yonetim::sagaKaydir(Node *degisken,string okuma,int dugumsayisi)
	{
		string temp2;
		string yeniDeger=okuma;
		Yedek = degisken;
		int i = 0;
		for (int i=0; i <dugumsayisi;i++)
		{
			std::string onceki = std::to_string(Yedek->getData());
			Yedek->kaydir(stoi(yeniDeger));
			oku = std::to_string(Yedek->getData());
			yeniDeger = onceki;
			Yedek = Yedek->getPnext();
		}	
		
	}
	void Yonetim::solaKaydir(Node *degisken, string okuma, int dugumsayisi)
	{
		string temp2;
		string yeniDeger = okuma;
		Yedek = degisken;
		int i = 0;
		for (int i = 0; i < dugumsayisi; i++)
		{
			std::string onceki = to_string(Yedek->getData());
			Yedek->kaydir(stoi(yeniDeger));
			oku = to_string(Yedek->getData());
			yeniDeger = onceki;
			Yedek = Yedek->getPprev();
		}
	}
