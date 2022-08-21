#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<map>
#include "Kunder.h"
#include "Forsikring.h"
typedef long HRESULT;
typedef long SCODE;
#include<tuple>
using namespace std;
#include <iostream>

int main()
{
	Kunder k;
	Forsikring f;
	std::map<int, std::map<string, string>> customers;

	std::map<int, std::map<string, string>> insurance;

	bool boo = true;
	k.DummyKunde(customers);
	f.DummyForsikring(insurance);
	int  kundeNummer=0;
	while (boo) {

		cout << "[1] Ny avtale" << endl << "[2] List kunde" << endl << "[3] List forsikring"<<endl;
		string input;
		cin >> input;


		if (input == "1") {
			k.Avtale_info(customers);

			bool exists = k.SjekkKonto(k.mail, customers);

			if (exists == true) {
				cout << "\n\n\nKontoen eksisterer..";
				//Get_account
			}
			else {
				kundeNummer = k.NesteNummer(customers);
				k.LeggTilKunde(customers, kundeNummer, k.name, k.lastName, k.mail, k.type);
				
				cout << "\n\n\nNy konto opretta..\n\n\n";
			}
			int forsikringsNr = k.NesteNummer(insurance);

			f.LeggTilForsikring(insurance, k.mail, k.type, k.sum, forsikringsNr);
			f.OppdaterKunde(customers, kundeNummer, forsikringsNr);
			f.SendLetter(insurance, forsikringsNr);
		}
		else if(input=="2") {
			k.PrintKunder(customers);
		}
		else if (input == "3") {
			f.PrintForsikring(insurance);
		}
		

		cout << "\n\nContinue : [y/n]";
		string tf ;
		cin >> tf;
		if (tf == "y"|| tf == "Y") {
			boo = true;
		}
		else {
			boo = false;
		}
	}
}

