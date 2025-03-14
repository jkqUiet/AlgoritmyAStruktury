#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Zastavane : public UJKriterium<double> {
public:
	double ohodnot(JednotkaUzemna* jed) override;
};

inline double Zastavane::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getZastavne();
}
