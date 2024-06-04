#include "Manager.h"
#include <iostream>
#include "JednotkaUzemna.h"
#include "UniverzalnyFilter.h"
#include "Filtre/Filter.h"
#include "Filtre/FInterval.h"
#include "Filtre/FTyp.h"
#include "Kriteria/UJKriterium.h"
#include "Kriteria/UJPodmienene/Nazov.h"
#include "Filtre/FPrislusnost.h"
#include "Filtre/FHodnota.h"
#include "Kriteria/UJPodmienene/Pobyv.h"
#include "Kriteria/UJPodmienene/Zastavanost.h"
#include "Kriteria/UJPodmienene/Typ.h"

using namespace std;
using namespace structures;

Manager::Manager(structures::SortedSequenceTable<string, JednotkaUzemna*>& kraje,
	structures::SortedSequenceTable<string, JednotkaUzemna*>& okresy,
	structures::SortedSequenceTable<string, JednotkaUzemna*>& obce, 
	structures::SortedSequenceTable<string, JednotkaUzemna*>& svk):
	UJKraje(kraje), UJOkresy(okresy), UJObce(obce), slovensko(svk)
{
	filtrovac = new Filtrovac<string, JednotkaUzemna*>();
	filtrovaneJednotky = new ArrayList<JednotkaUzemna*>();
}

Manager::~Manager()
{
	delete filtrovac;
	filtrovac = nullptr;
	delete filtrovaneJednotky;
	filtrovaneJednotky = nullptr;
}

structures::SortedSequenceTable<string, JednotkaUzemna*>& Manager::getKraje()
{
	return UJKraje;
}

structures::SortedSequenceTable<string, JednotkaUzemna*>& Manager::getOkresy()
{
	return UJOkresy;
}

structures::SortedSequenceTable<string, JednotkaUzemna*>& Manager::getObce()
{
	return UJObce;
}

void Manager::vycistiFiltre()
{
	filtrovac->vycistiFiltre();
}

void Manager::clearniFiltrovane()
{
	filtrovaneJednotky->clear();
}

void Manager::vypis()
{
	for (JednotkaUzemna* a : *filtrovaneJednotky) {
		vypisKonkretne(a);
	}
}

structures::ArrayList<JednotkaUzemna*>* Manager::getJednotkyFiltrovane()
{
	return filtrovaneJednotky;
}

void Manager::vypisKonkretne(JednotkaUzemna* uzemnaJednotka)
{
	cout << " Nazov : " << uzemnaJednotka->getNazov() << endl;
	JednotkaUzemna* nadomnou = uzemnaJednotka->getTenNadomnou();
	while (nadomnou != nullptr) {
		cout << " Vyssie : " << nadomnou->getNazov() << endl;
		nadomnou = nadomnou->getTenNadomnou();
	}
	cout << " Pocet obyvatelov : " <<uzemnaJednotka->getPocetObyvatelov() << endl;
}

void Manager::manazuj()
{	
	filtrovac->vyfiltruj(&UJObce, *filtrovaneJednotky);
	filtrovac->vyfiltruj(&UJOkresy, *filtrovaneJednotky);
	filtrovac->vyfiltruj(&UJKraje, *filtrovaneJednotky);
	filtrovac->vyfiltruj(&slovensko, *filtrovaneJednotky);
}

void Manager::odoberFilter()
{
	filtrovac->odoberFilter();
}


JednotkaUzemna* Manager::vyhladajJednotku(string nazov)
{
	JednotkaUzemna* var = nullptr;
	slovensko.tryFind(nazov, var);
	if (var != nullptr) { return var; }
	UJKraje.tryFind(nazov, var);
	if (var != nullptr) { return var; }
	UJOkresy.tryFind(nazov, var);
	if (var != nullptr) { return var; }
	UJObce.tryFind(nazov, var);
	if (var != nullptr) { return var; }
	return nullptr;
}

void Manager::pridajFilter(UniverzalnyFilter<JednotkaUzemna*>* filter)
{
	filtrovac->pridajFilter(filter);
}
