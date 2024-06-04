#pragma once

#include <string>

template <typename T, typename O>
class Kriterium {
public :
	virtual T ohodnot(O o) = 0;
};