#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class PPoprod : public UJKriterium<int> {
public:
	int ohodnot(JednotkaUzemna* jed) override;
};

inline int PPoprod::ohodnot(JednotkaUzemna* jed) { // tuna to prerobit
	return jed->getPoProd();
}
