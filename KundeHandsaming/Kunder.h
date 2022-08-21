#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<map>


using namespace std;
#include <iostream>

class Kunder
{
public:
	string name;
	string lastName;
	string mail;

	string type;
	double sum;
	int kundeNr;

public:
	void  Avtale_info(std::map<int, std::map<string, string>>& customers);	//function to get data from user
	bool SjekkKonto( string mail, std::map<int, std::map<string, string>>& customers);
	int NesteNummer(std::map<int, std::map<string, string>>& customers);
	void DummyKunde(std::map<int, std::map<string, string>>& customers);
	void LeggTilKunde(std::map<int, std::map<string, string>>& customers, int kundeNr, string name, string lastName, string mail, string type);
	void PrintKunder(std::map<int, std::map<string, string>>& customers);
};
