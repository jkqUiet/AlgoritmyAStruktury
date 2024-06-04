#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Pobyv : public UJKriterium<int> {
public:
	int ohodnot(JednotkaUzemna* jed) override;
};

inline int Pobyv::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getPocetObyvatelov();
}
