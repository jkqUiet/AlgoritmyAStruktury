#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class PPreprod : public UJKriterium<int> {
public:
	int ohodnot(JednotkaUzemna* jed) override;
};

inline int PPreprod::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getPreProd();
}
