#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "meniu.h"
#include "auxString.h"
#include "hash.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

extern int sizeH;
extern int numarInserari;
extern double factorCritic;

void help()
{
	int n;
	char trash;
	cout << "Aplicatie biblioteca. Apasati o tasta pentru a primi sintaxa. Orice alta tasta inchide meniul" << endl;
	cout << "1. Adaugare carti in blioteca" << endl;
	cout << "2. Extragere carti din bibliteoca" << endl;
	cout << "3. Joc de bibliteca" << endl;
	cout << "4. Iesire aplicatie" << endl;

	cin >> n;
	trash = getchar(); //debounce 
	while (n)
	{
		switch (n)
		{
		case 1:
			cout << "PUT titlu_carte cuv1 cuv2 .. cuvN. Rolul acestei comenzi este de a indexa continutul cartii titlu_carte si anume : cuv1 cuv2 ... cuvN"<<endl;
			break;
		case 2:
			cout << "GET cuv1_interogare cuv2_interogare ..cuvN_interogare. Aceasta comanda va intoarce toate cartile in care apar toti termenii interogarii." << endl;
			break;
		case 3:
			cout << "PLAY titlu_carte cuv1_concurent cuv2_concurent ... cuvN_concurent. Aceasta comanda verifica daca toti termenii din interogarea : cuv1_concurent cuv2_concurent...cuvN_concurent exista in cartea titlu_carte." << endl;;
			break;
		case 4:
			cout << "Apasati de 2 ori ENTER pentru a iesi din program. Iesirea din acest meniu v-a fost adusa la cunostiinta anterior." << endl;;
			break;
		default:
			return;
		}
		cin >> n;
		trash = getchar();//debounce last enter
	}
}

void PUTb(vector<Element*>& HT, std::string& operatie)
{
	string titlu = cuvant(operatie);
	string cuv_carte = cuvant(operatie);

	while (cuv_carte.length())
	{
		insertHT(HT, cuv_carte, titlu);
		cuv_carte = cuvant(operatie);
	}

	if (calcFI() > factorCritic)
	{
		//cout << "S-a REDIMENSIONAT"<<endl;
		HT = redimensionare(HT);
	}
}

std::vector<std::string> GETb(vector<Element*>& HT, std::string& operatie)
{
	std::vector<std::string> s;
	string cuv_carte = cuvant(operatie);
	string cuv_carte2 = cuvant(operatie);

	int index = modKey(cuv_carte);

	if (HT[index])
	{
		Element* p = HT[index];
		while (p && p->cheie != cuv_carte)
		{
			p = p->next;
		}
		if (p == 0)
		{
			s.clear();
			s.push_back("BOOK_NOT_FOUND");
			return s;
		}
		else
		{
			s = p->valori;
		}
	}
	else
	{
		s.clear();
		s.push_back("BOOK_NOT_FOUND");
		return s;
	}

	if (!cuv_carte2.length() == 0)
	{
		while (cuv_carte2.length())
		{
			int index = modKey(cuv_carte2);
			if (HT[index])
			{
				Element* p = HT[index];
				while (p && p->cheie != cuv_carte2)
				{
					p = p->next;
				}
				if (p == 0)
				{
					s.clear();
					s.push_back("BOOK_NOT_FOUND");
					return s;
				}
				else
				{
					s = interclasare(s, p->valori);
					SI(s);
				}
			}
			else
			{
				s.clear();

				return s;
			}
			cuv_carte2 = cuvant(operatie);
		}
	}
	if (s.size() == 0)
		s.push_back("BOOK_NOT_FOUND");
	return s;
}

std::vector<std::string> PLAYb(std::vector<Element*>& HT, std::string& operatie)
{
	std::vector<std::string> s,aux;

	string titlu = cuvant(operatie);
	aux = GETb(HT, operatie);

	if (aux[0] != "BOOK_NOT_FOUND" && exista(aux, titlu))
		s.push_back("YOU_WIN");
	else
		s.push_back("YOU_LOSE");

	return s;
}
