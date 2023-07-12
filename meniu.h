#pragma once
#include "hash.h"
#include <vector>

void help();

void PUTb(std::vector<Element*>& HT, std::string &operatie);
std::vector<std::string> GETb(std::vector<Element*>& HT, std::string& operatie);
std::vector<std::string> PLAYb(std::vector<Element*>& HT, std::string& operatie);