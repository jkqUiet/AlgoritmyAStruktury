#pragma once
#include "Nacitavac.h"
#include "FZlozeny.h"
#include "Filtrovac.h"
#include "structures/table/sorted_sequence_table.h"
#include "Kriteria/UJKriterium.h"

class Manager
{
	structures::SortedSequenceTable<string, JednotkaUzemna*>& UJKraje;
	structures::SortedSequenceTable<string, JednotkaUzemna*>& UJOkresy;
	structures::SortedSequenceTable<string, JednotkaUzemna*>& UJObce;
	structures::SortedSequenceTable<string, JednotkaUzemna*>& slovensko;
	structures::ArrayList<JednotkaUzemna*>* filtrovaneJednotky;
	void vypisKonkretne(JednotkaUzemna* uzemnaJednotka);
	Filtrovac<string, JednotkaUzemna*>* filtrovac;
	
public:
	Manager(structures::SortedSequenceTable<string, JednotkaUzemna*>& kraje,
		structures::SortedSequenceTable<string,	JednotkaUzemna*>& okresy,
		structures::SortedSequenceTable<string, JednotkaUzemna*>& obce, 
		structures::SortedSequenceTable<string, JednotkaUzemna*>& svk);
	~Manager();

	structures::SortedSequenceTable<string, JednotkaUzemna*>& getKraje();
	structures::SortedSequenceTable<string, JednotkaUzemna*>& getOkresy();
	structures::SortedSequenceTable<string, JednotkaUzemna*>& getObce();

	void clearniFiltrovane();
	structures::ArrayList<JednotkaUzemna*>* getJednotkyFiltrovane();
	void pridajFilter(UniverzalnyFilter<JednotkaUzemna*>* filter);
	void vypis(); 
	void vycistiFiltre();
	void manazuj();
	void odoberFilter();
	JednotkaUzemna* vyhladajJednotku(std::string nazov);

};

