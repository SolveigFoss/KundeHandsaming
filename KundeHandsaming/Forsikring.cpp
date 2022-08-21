#include "Forsikring.h"

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<map>
#include<vector>
#include<tuple>
#include <sstream>


using namespace std;
#include <iostream>

void Forsikring::DummyForsikring(std::map<int, std::map<string, string>>& forsikring_) {
	forsikring_[101]["mail"] = "arvid.hansen@gmail.com";
	forsikring_[101]["forsikringType"] = "Bil";
	forsikring_[101]["forsikringsSum"] = "100000";
	forsikring_[101]["Pris"] = "1000";
	forsikring_[101]["status"] = "sendt";

	forsikring_[102]["mail"] = "arvid.hansen@gmail.com";
	forsikring_[102]["forsikringType"] = "Hus";
	forsikring_[102]["forsikringsSum"] = "5000000";
	forsikring_[102]["Pris"] = "5000";
	forsikring_[102]["status"] = "sendt";

	forsikring_[103]["mail"] = "janne.hansen@gmail.com";
	forsikring_[103]["forsikringType"] = "Bil";
	forsikring_[103]["forsikringsSum"] = "150000";
	forsikring_[103]["Pris"] = "1500";
	forsikring_[103]["status"] = "sendt";

}

void Forsikring::PrintForsikring(std::map<int, std::map<string, string>>& forsikring_) {
	cout << "Forsikring" << endl;
	for (auto const& ent1 : forsikring_) {
		cout << endl;
		for (auto const& ent2 : ent1.second) {
			cout << "Forsikringsnummer: " << ent1.first << ", " << ent2.first << ", " << ent2.second << endl;
		}
	}
}

void Forsikring::LeggTilForsikring(std::map<int, std::map<string, string>>& forsikring_,string mail, string type, double sum,int forsikringsNr) {
	forsikring_[forsikringsNr]["mail"] = mail;
	forsikring_[forsikringsNr]["forsikringType"] = type;
	forsikring_[forsikringsNr]["forsikringsSum"] = std::to_string(sum);
	double pris;
	if (type == "Bil"|| type=="bil"||type=="BIL") {
		pris = 0.01 * sum;
	}
	else {
		pris = 0.001 * sum;
	}
	
	forsikring_[forsikringsNr]["Pris"] = std::to_string(pris);
	forsikring_[forsikringsNr]["status"] = "";
}

void Forsikring::SendLetter(std::map<int, std::map<string, string>>& forsikring_, int forsikringsNr){
	forsikring_[forsikringsNr]["status"] = "Sendt";
	cout << "\nSender brev og oppdaterer status\n";

}

void Forsikring::OppdaterKunde(std::map<int, std::map<string, string>>& customers, int kundeNr, int forsikringsNr) {
	if (customers[kundeNr]["forsikring1"]==""){
		customers[kundeNr]["forsikring1"] = std::to_string(forsikringsNr);
	}
	else if (customers[kundeNr]["forsikring2"] == "") {
		customers[kundeNr]["forsikring2"] = std::to_string(forsikringsNr);
	}
	else {
		customers[kundeNr]["forsikring3"] = std::to_string(forsikringsNr);
	}
}