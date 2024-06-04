#pragma once

#include "../UJKriterium.h"
#include "../../JednotkaUzemna.h"
using namespace std;

class Prislusnost : public UJKriterium<bool> {
private:
	JednotkaUzemna* horeNad;

public:
	void setHore(JednotkaUzemna* nad);
	bool ohodnot(JednotkaUzemna* jed) override;
};

bool Prislusnost::ohodnot(JednotkaUzemna* jed) {
	return jed == horeNad;
}

void Prislusnost::setHore(JednotkaUzemna* nad) {
	horeNad = nad;
}
