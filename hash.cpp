#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "hash.h"

using std::vector;
using std::string;

extern int sizeH;
extern int numarInserari;
int modKey(std::string cheie)
{
	int s = 0;

	for (int i = 0; i < cheie.length(); i++)
		s += cheie[i];

	return s % sizeH;
}

void insertHT(vector<Element*>& HT, string cuv_carte, string titlu)
{
	int index = modKey(cuv_carte);

	if (HT[index])
	{
		Element *p = HT[index];
		while (p&&p->cheie!=cuv_carte)
		{
			p = p->next;
		}
		if (p)
		{
			if (find(p->valori.begin(), p->valori.end(), titlu) == p->valori.end()) //cauta daca cuvantul deja exista
			{
				p->valori.push_back(titlu); //si insereaza-l daca nu exista
				sort(p->valori.begin(), p->valori.end()); //mentin vectorul sortat lexicografic
			}
		}
		else //inlantuire element
		{
			Element* p = HT[index];
			while (p->next)
				p = p->next;

			Element* nod = new Element;
			nod->cheie = cuv_carte;
			nod->valori.push_back(titlu);
			nod->next = 0;
			p->next = nod;
			numarInserari++;
		}
	}
	else //HT[index]nu mai are alte elemente
	{
		Element* nod = new Element;
		nod->cheie = cuv_carte;
		nod->valori.push_back(titlu);
		nod->next = 0;
		HT[index] = nod;
		numarInserari++;
	}
}

vector<Element*> redimensionare(vector<Element*> HT)
{
	sizeH = sizeH * 2;
	vector<Element*> HTnou(sizeH); //HT de 2 ori mai mare cu toate valorile la 0

	for (int i = 0; i < sizeH / 2; i++)
	{
		Element* p = HT[i];

		while (p)
		{
			Element* q = p->next;
			p->next = 0;

			Element* aux = HTnou[modKey(p->cheie)]; 
			if (!aux) //nu am gasit niciun element la cheia respectiva, incep lista
				HTnou[modKey(p->cheie)] = p; 
			else //inlantuire
			{
				while (aux->next)
				{
					aux = aux->next;
				}
				aux->next = p;
			}
			
			p = q; //continui sa parcurg linia din HT original
		}
	}

	return HTnou;
}

double calcFI()
{
	return (numarInserari*1.0)/sizeH;
}

