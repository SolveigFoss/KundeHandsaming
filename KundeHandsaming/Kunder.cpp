#include "Kunder.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<map>
#include<vector>
#include<tuple>

using namespace std;
#include <iostream>


//std::tuple < string, string,string,string, double> 
void Kunder::Avtale_info(std::map<int, std::map<string, string>>& customers)
{
	cout << "\n\nFornavn : ";
	cin >> name;

	cout << "\n\nEtternavn : ";
	cin >> lastName;
	// cin.getline(lastName, 50);

	cout << "\n\nMail : ";
	cin >> mail;
	//cin.getline(mail, 50);

	cout << "\n\nAvtaletype Bil/Hus : ";
	cin >> type;
	//cin.getline(type, 50);


	cout << "\n\nForsikringssum : ";
	cin >> sum;
	cout << "\n\n";


	cout << "Namn:\t\t\t" << name << endl;
	cout << "Etternamn:\t\t" << lastName << endl;
	cout << "Mail:\t\t\t" << mail << endl;
	cout << "Forsikring:\t\t" << type << endl;
	cout << "Forsikringssum:\t\t" << sum << endl;
	//return true; std::make_tuple(name, lastName, mail, type, sum);
}

bool Kunder::SjekkKonto(string mail, std::map<int, std::map<string, string>>& customers)
{
	int a = 0;
	for (auto const& ent1 : customers) {
		for (auto const& ent2 : ent1.second) {
			if (ent2.second == mail) {
				a++;
			}
		}
	}

	cout << "\n\nSjekker konto..\n";
	if (a>0) {
		cout << "Konto eksisterer!!\n" << endl;
		return true;
	}
	else {
		cout << "Konto eksisterer ikkje\n" << endl;
		return false;
	}
}

void Kunder::DummyKunde(std::map<int, std::map<string, string>>& customers) {

	customers[1]["name"] = "Arvid";
	customers[1]["lastName"] = "Hansen";
	customers[1]["mail"] = "arvid.hansen@gmail.com";
	customers[1]["forsikring1"] = "101";
	customers[1]["forsikring2"] = "102";
	customers[1]["forsikring3"] = "";
	customers[1]["status"] = "sendt";

	customers[2]["name"] = "Janne";
	customers[2]["lastName"] = "Hansen";
	customers[2]["mail"] = "janne.hansen@gmail.com";
	customers[2]["forsikring1"] = "103";
	customers[2]["forsikring2"] = "";
	customers[2]["forsikring3"] = "";
	customers[2]["status"] = "sendt";

	customers[3]["name"] = "Arne";
	customers[3]["lastName"] = "Jonsen";
	customers[3]["mail"] = "Arne.Jonsen@gmail.com";
	customers[3]["forsikring1"] = "";
	customers[3]["forsikring2"] = "";
	customers[3]["forsikring3"] = "";
	customers[3]["status"] = "";
}

int Kunder::NesteNummer(std::map<int, std::map<string, string>>& customers) {
	int a = customers.rbegin()->first;
	cout << "Nytt nr:\t" << a + 1 << endl;
	return a + 1;
}

void Kunder::LeggTilKunde(std::map<int, std::map<string, string>>& customers, int kundeNr, string name, string lastName, string mail, string type) {

	customers[kundeNr]["name"] = name;
	customers[kundeNr]["lastName"] = lastName;
	customers[kundeNr]["mail"] = mail;
	customers[kundeNr]["forsikring1"] = "";
	customers[kundeNr]["forsikring1"] = "";
	customers[kundeNr]["forsikring1"] = "";
	customers[kundeNr]["status"] = "";
}

void Kunder::PrintKunder(std::map<int, std::map<string, string>>& customers) {
	cout << "Customers" << endl;
	for (auto const& ent1 : customers) {
		cout << endl;
		for (auto const& ent2 : ent1.second) {
			cout << "Customer number "<<ent1.first <<", " <<ent2.first <<", "<< ent2.second << endl;
		}
	}
}