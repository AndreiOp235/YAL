#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "auxString.h"
#include "hash.h"
#include "meniu.h"

using std::string;
using std::vector;
using std::cin;
using std::endl;
using std::cout;

int sizeH=16;
int numarInserari = 0;
double factorCritic = 0.7;


int main()
{
	help();
	string operatie;
	bool flag=true; 
	getline(cin, operatie);


	vector<Element*> HT(sizeH); //initializare la zero cu sizeH elemente

	string optiune = cuvant(operatie);
	
	while (flag)
	{
		if (optiune == "PUT")
		{
			PUTb(HT, operatie);
		}

		else if (optiune == "GET")
		{
			std::vector<std::string> s;

			s = GETb(HT, operatie);

			afisareVector(s);
			cout << endl;
		}

		else if (optiune == "PLAY")
		{
			std::vector<std::string> s;
			s = PLAYb(HT, operatie);
			afisareVector(s);
			cout << endl;
		}
		else
			flag = false;

		getline(cin, operatie);
		optiune = cuvant(operatie);
	}


	return 0;
}