#ifndef Yonetim_HPP
#define Yonetim_HPP
#include "Dugum.hpp"
#include <iostream>
using namespace std;
class Yonetim
{
public:
	string oku;
	~Yonetim();
	friend ostream& operator<<(ostream& ekran, Yonetim &sag) ;
	void hepsiniyazdir(Node *listeb);
	void dugumKonumu(int istdugum, Node *LB,string okuma);
	void sagaKaydir(Node *degisken,string okuma,int dugumsayisi);
	void solaKaydir(Node *degisken,string okuma,int dugumsayisi);
private:
	Node* Yedek;
	Node *LB;
	Node *LS;
};
#endif