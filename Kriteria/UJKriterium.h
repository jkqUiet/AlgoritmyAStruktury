#pragma once
#include "../Kriteria/UJPodmienene/Kriterium.h"
#include "JednotkaUzemna.h"

template <typename T>
class UJKriterium : public Kriterium<T,JednotkaUzemna*> {
};
