#ifndef CiftYonluBagilListe_HPP
#define CiftYonluBagilListe_HPP
#include <iostream>
#include "Dugum.hpp"
using namespace std;
class CiftYonluBagilListe
{
public:
	void ilkEleman(Node*);
	void soneleman(Node*);
	void degerata(Node*);
	void degeratama2(Node*,Node*);
	void degeratama3(Node* ,Node* );
	void degeratama4(Node* ,Node* );
private:
	string oku=NULL;
};

#endif