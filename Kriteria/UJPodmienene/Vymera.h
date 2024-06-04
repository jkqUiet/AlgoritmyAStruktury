#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Vymera : public UJKriterium<double> {
public:
	double ohodnot(JednotkaUzemna* jed) override;
};

inline double Vymera::ohodnot(JednotkaUzemna* jed) {
	return jed->getVymera();
}

