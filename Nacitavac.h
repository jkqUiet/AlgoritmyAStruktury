#pragma once
#include <string>

#include "structures/table/sorted_sequence_table.h"
#include "JednotkaUzemna.h"

class Nacitavac
{
public:
	Nacitavac(structures::SortedSequenceTable<std::string, JednotkaUzemna*>& pobce, structures::SortedSequenceTable<std::string,
		JednotkaUzemna*>& pokresy, structures::SortedSequenceTable<std::string, JednotkaUzemna*>& pkraje, 
		structures::SortedSequenceTable<std::string, JednotkaUzemna*>& svk);
	~Nacitavac();

	void nacitaj(std::string nazovSuboruClenenie, std::string nazovSuboruObce);

private:
	structures::SortedSequenceTable<std::string, JednotkaUzemna*>& obce;
	structures::SortedSequenceTable<std::string, JednotkaUzemna*>& okresy;
	structures::SortedSequenceTable<std::string, JednotkaUzemna*>& kraje;
	structures::SortedSequenceTable<std::string, JednotkaUzemna*>& slovensko;
};

