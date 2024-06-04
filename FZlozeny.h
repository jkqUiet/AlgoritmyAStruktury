#pragma once
#include "structures/list/array_list.h"
#include "structures/table/sorted_sequence_table.h"
#include "UniverzalnyFilter.h"

template<typename T>
class FZlozeny : public UniverzalnyFilter<T>{
public:
    FZlozeny();
    bool splnaFilter(T o);
    ~FZlozeny();

    void pridajFilter(UniverzalnyFilter<T>* filter);
    void vycistiFiltre();
    int getPocetFiltrov();
    void odoberFilter();

private:
    structures::ArrayList<UniverzalnyFilter<T>*>* filtre;
};

template<typename T>
inline FZlozeny<T>::FZlozeny()
{
    this->filtre = new structures::ArrayList<UniverzalnyFilter<T>*>(); 
}

template<typename T>
inline bool FZlozeny<T>::splnaFilter(T o)
{
    for (auto a : *filtre) {
        if (!a->splnaFilter(o)) {
            return false;
        }
    }
    return true;
}

template<typename T>
inline void FZlozeny<T>::pridajFilter(UniverzalnyFilter<T>* filter)
{
    filtre->add(filter);
}

template<typename T>
inline void FZlozeny<T>::vycistiFiltre()
{
    for (auto a : *filtre) {
        delete a;
    }
    filtre->clear();
}

template<typename T>
inline int FZlozeny<T>::getPocetFiltrov()
{
    return filtre->size();
}

template<typename T>
inline void FZlozeny<T>::odoberFilter()
{
    delete (*filtre)[filtre->size()-1];
    filtre->removeAt(filtre->size() - 1);
}

template<typename T>
inline FZlozeny<T>::~FZlozeny()
{
    vycistiFiltre();
    delete filtre;
}