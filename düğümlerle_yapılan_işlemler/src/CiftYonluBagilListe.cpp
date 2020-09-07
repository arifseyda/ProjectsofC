#include "CiftYonluBagilListe.hpp"
#include "Dugum.hpp"
#include <iostream>

	void CiftYonluBagilListe::ilkEleman(Node *lb)
	{
		lb->setPnext(lb);
	}
	void CiftYonluBagilListe::soneleman(Node *lb)
	{
		lb->setPrev(lb);
	}
	void CiftYonluBagilListe::degerata(Node *yedek)
	{
		yedek->getPnext()->setPrev(yedek);
	}
	void CiftYonluBagilListe::degeratama2(Node *lb,Node *yedek)
	{
		yedek->getPnext()->setPnext(lb);
	}
	void CiftYonluBagilListe::degeratama3(Node *lb,Node *yedek)
	{
		lb->setPrev(yedek->getPnext());
	}
	void CiftYonluBagilListe::degeratama4(Node *lb,Node *ls)
	{
		ls = lb->getPprev();
	}