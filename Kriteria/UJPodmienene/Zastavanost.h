#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Zastavanost : public UJKriterium<double> {
public:
	double ohodnot(JednotkaUzemna* jed) override;
};

inline double Zastavanost::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getZastavanost();
}
