#include <iostream>
#include <string>
#include <vector>
#include "auxString.h"

using std::string;
using std::vector;
using std::cout;

std::string cuvant(std::string &sir)
{
    string aux;

    while (sir.length() && sir[0] != 32)
    {
        aux.push_back(sir[0]);
        sir.erase(0, 1);
    }
    sir.erase(0, 1);
    return aux;

}

std::vector<std::string> interclasare(std::vector<std::string> s1, std::vector<std::string> s2)
{
    int i = 0;
    int j = 0;
    std::vector<std::string> s3;

    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] < s2[j])
            s3.push_back(s1[i++]);
        else
            s3.push_back(s2[j++]);
    }

    while (i < s1.size())
        s3.push_back(s1[i++]);

    while (j < s2.size())
        s3.push_back(s2[j++]);

    return s3;
}

void SI(std::vector<std::string> &s)
{
    unsigned long long i = 0;

    while (i < s.size())
    {
        if (((i + 1) < s.size()) && s[i] == s[i + 1])// daca in vector exista 2 elemente asemenea incremeneteaza
            i++;
        s.erase(s.begin()+i); //oricum trebuie sters elementul duplicat sau cel unic
    }
}

void afisareVector(std::vector<std::string> s)
{
    std::vector<std::string>::iterator i;
    i=s.begin();

    while (i!=s.end())
    {
        cout << *i << " ";
        i++;
    }

}

bool exista(std::vector<std::string> s, std::string titlu)
{
    long long l = 0;
    long long r = s.size() - 1;
    long long m = 0;

    while (l <= r) 
    {
        m = l + (r - l) / 2;
        if (s[m] == titlu)
            return true;
        if (s[m] < titlu)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
}