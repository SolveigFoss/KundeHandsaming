#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<map>

using namespace std;
#include <iostream>

class Forsikring
{
public:
	string mail;
	string type;
	double sum;
	int forsikringsNr;

public:
	void DummyForsikring(std::map<int, std::map<string, string>>& forsikring_);	//function to get data from user
	void PrintForsikring(std::map<int, std::map<string, string>>& forsikring_);
	void LeggTilForsikring(std::map<int, std::map<string, string>>& forsikring_, string mail, string type, double sum, int forsikringsNr);
	void SendLetter(std::map<int, std::map<string, string>>& forsikring_, int forsikringsNr);
	void OppdaterKunde(std::map<int, std::map<string, string>>& customers, int kundeNr, int forsikringsNr);
};
