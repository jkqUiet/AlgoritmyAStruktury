#pragma once
#include "structures/list/array_list.h"
#include "JednotkaUzemna.h"
#include "Kriteria/UJKriterium.h"

using namespace std;
using namespace structures;

template <typename T, typename V>
class Triedenie
{
private :
	void rekShell(bool typKriteria, int pKrokov);
	structures::ArrayList<T>* dataNaTriedenie;
	UJKriterium<V>* kriterium;
public:
	Triedenie();
	~Triedenie();
	void utried(structures::ArrayList<T>* data, UJKriterium<V>* pKriterium, bool typTriedenia);
};

template<typename T, typename V>
inline void Triedenie<T, V>::rekShell(bool typKriteria, int pKrokov)
{

	for (int delta = 0; delta < pKrokov; delta++) {
		for (int i = delta; i < dataNaTriedenie->size(); i += pKrokov) {
			int j = i;
			if (typKriteria) {
				while ((j - pKrokov >= delta) &&
					(kriterium->ohodnot((*dataNaTriedenie)[j]) < kriterium->ohodnot((*dataNaTriedenie)[j - pKrokov]))) {
					std::swap((*dataNaTriedenie)[j], (*dataNaTriedenie)[j - pKrokov]);
					j -= pKrokov;
				}
			} else {
				while ((j - pKrokov >= delta) &&
					(kriterium->ohodnot((*dataNaTriedenie)[j]) > kriterium->ohodnot((*dataNaTriedenie)[j - pKrokov]))) {
					std::swap((*dataNaTriedenie)[j], (*dataNaTriedenie)[j - pKrokov]);
					j -= pKrokov;
				}
			}
		}
	}

	if (pKrokov > 1) {
		int var = pKrokov - 1;
		rekShell(typKriteria, var);
	}
}

template<typename T, typename V>
inline Triedenie<T, V>::Triedenie()
{
}

template<typename T, typename V>
inline Triedenie<T, V>::~Triedenie()
{
}

template<typename T, typename V>
inline void Triedenie<T, V>::utried(ArrayList<T>* data, UJKriterium<V>* pKriterium, bool typTriedenia)
{
	dataNaTriedenie = data;
	kriterium = pKriterium;

	int pocetKrokov = log10(dataNaTriedenie->size());
	if (pocetKrokov == 0) {
		pocetKrokov++;
	}

	rekShell(typTriedenia, pocetKrokov);
}
