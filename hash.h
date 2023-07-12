#pragma once
#include <vector>

struct Element
{
	std::string cheie;
	std::vector<std::string> valori;
	Element* next;
};

int modKey(std::string cheie);

void insertHT(std::vector<Element*>& HT, std::string cuv_carte, std::string titlu);

std::vector<Element*> redimensionare(std::vector<Element*> HT);
double calcFI();