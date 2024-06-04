#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Nacitavac.h"

using namespace std;
using namespace structures;

#define P_NAS_OBYV 1

Nacitavac::Nacitavac(structures::SortedSequenceTable<std::string, JednotkaUzemna*>& pobce, structures::SortedSequenceTable<std::string, 
	JednotkaUzemna*>& pokresy, structures::SortedSequenceTable<std::string, JednotkaUzemna*>& pkraje, 
	structures::SortedSequenceTable<std::string, JednotkaUzemna*>& svk):
obce(pobce), okresy(pokresy), kraje(pkraje), slovensko(svk)
{
}

Nacitavac::~Nacitavac()
{
}

void Nacitavac::nacitaj(std::string nazovSuboruClenenie, std::string nazovSuboruObce)
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

		ifstream suborClenenie;
		suborClenenie.open(nazovSuboruClenenie);

		ifstream suborObce;
		suborObce.open(nazovSuboruObce);

		int index = 0;
		while ((!suborClenenie.eof() && suborClenenie.is_open()) && (!suborObce.eof() && suborObce.is_open())) {
			string pom = "";
			string pomCisla = "";
			getline(suborClenenie, pom);
			getline(suborObce, pomCisla);
			if (index != 0) {
				string delimiter = ";";
				string pole[3];
				size_t pos = 0;
				string token;
				for (int i = 0; i < 3; i++) {
					pos = pom.find(delimiter);
					token = pom.substr(0, pos);
					pom.erase(0, pos + delimiter.length());
					pole[i] = token;
				}
				
				int poleCiselnych[5];
				string tokenNumber;
				
				for (int i = 0; i < 6; i++) {
					pos = pomCisla.find(delimiter);
					tokenNumber = pomCisla.substr(0, pos);
					pomCisla.erase(0, pos + delimiter.length());
					if (i != 0) {
						poleCiselnych[i-1] = std::stoi(tokenNumber);
					}
				}
				JednotkaUzemna* svk;
				JednotkaUzemna* smernikKraj;
				slovensko.tryFind("Slovensko", svk);
				if (!kraje.tryFind(pole[2], smernikKraj)) {
					smernikKraj = new JednotkaUzemna(pole[2], svk, UJTyp::Kraj, 0, 0, 0, 0, 0);
					kraje.insert(pole[2], smernikKraj);					
					svk->pridajPod(smernikKraj);		
				}
				JednotkaUzemna* smernikOkres;
				if (!okresy.tryFind(pole[1], smernikOkres)) {
					smernikOkres = new JednotkaUzemna(pole[1], smernikKraj, UJTyp::Okres, 0, 0, 0, 0, 0);
					okresy.insert(pole[1], smernikOkres);
					smernikKraj->pridajPod(smernikOkres);
				}
				JednotkaUzemna* smernikObec = new JednotkaUzemna(pole[0], smernikOkres, UJTyp::Obec, poleCiselnych[4],
					poleCiselnych[3], poleCiselnych[0] * P_NAS_OBYV, poleCiselnych[1] * P_NAS_OBYV, poleCiselnych[2] * P_NAS_OBYV);
				obce.insert(pole[0], smernikObec);
				smernikOkres->pridajPod(smernikObec);
			

				JednotkaUzemna* predchodca = smernikObec->getTenNadomnou();
				while (predchodca != nullptr) {
					predchodca->setZastavane(smernikObec->getZastavne()+ predchodca->getZastavne());
					predchodca->setVymera(smernikObec->getVymera() + predchodca->getVymera());
					predchodca->setProd(smernikObec->getProd() + predchodca->getProd());
					predchodca->setPreProd(smernikObec->getPreProd() + predchodca->getPreProd());
					predchodca->setPoProd(smernikObec->getPoProd() + predchodca->getPoProd());
					predchodca = predchodca->getTenNadomnou();
				}
		
			
			}
			index++;
		}
		suborClenenie.close();
		suborObce.close();
}
