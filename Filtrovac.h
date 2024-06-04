#pragma once
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"
#include "FZlozeny.h"

template<typename K, typename T>
class Filtrovac
{
	FZlozeny<T>* zlozenyFilter;

public:
	Filtrovac();
	~Filtrovac();
	void pridajFilter(UniverzalnyFilter<T>* filter);
	void vyfiltruj(structures::SortedSequenceTable<K, T>* tabulka, structures::ArrayList<T>& prazdnaTab);
	void vycistiFiltre();
	void odoberFilter();
};

template<typename K, typename T>
inline Filtrovac<K,T>::Filtrovac()
{
	zlozenyFilter = new FZlozeny<T>();
}

template<typename K, typename T>
inline Filtrovac<K ,T>::~Filtrovac()
{
	delete zlozenyFilter;
	zlozenyFilter = nullptr;
}

template<typename K, typename T>
inline void Filtrovac<K, T>::pridajFilter(UniverzalnyFilter<T>* filter)
{
	zlozenyFilter->pridajFilter(filter);
}

template<typename K, typename T>
inline void Filtrovac<K ,T>::vyfiltruj(structures::SortedSequenceTable<K, T>* tabulka, 
	structures::ArrayList<T>& prazdnaTab)
{
	for (auto item : *tabulka) {
		if (item->accessData()->getNazov() == "Okres Nitra") {
			cout << endl;
		}
		if (zlozenyFilter->splnaFilter(item->accessData())) {
			prazdnaTab.add(item->accessData());
		}
	}
}

template<typename K, typename T>
inline void Filtrovac<K, T>::vycistiFiltre()
{
	zlozenyFilter->vycistiFiltre();
}

template<typename K, typename T>
inline void Filtrovac<K, T>::odoberFilter()
{
	if (zlozenyFilter->getPocetFiltrov() > 0) {
		zlozenyFilter->odoberFilter();
	}
}
