#pragma once

template <typename T> 
class UniverzalnyFilter {
public :
	virtual bool splnaFilter(T o) = 0;
};