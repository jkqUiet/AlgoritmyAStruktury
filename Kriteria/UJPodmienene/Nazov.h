#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"

using namespace std;

class Nazov : public UJKriterium<string> {
public :
	string ohodnot(JednotkaUzemna* jed) override;
};

inline string Nazov::ohodnot(JednotkaUzemna* jed) {
	return jed->getNazov();
}
