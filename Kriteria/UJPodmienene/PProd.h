#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class PProd : public UJKriterium<int> {
public:
	int ohodnot(JednotkaUzemna* jed) override;
};

inline int PProd::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getProd();
}
