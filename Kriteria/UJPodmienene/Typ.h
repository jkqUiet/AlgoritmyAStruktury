#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Typ : public UJKriterium<UJTyp> {
public:
	UJTyp ohodnot(JednotkaUzemna* jed) override;
};

inline UJTyp Typ::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getTyp();
}
