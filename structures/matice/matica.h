#pragma once
#include "../structure.h"

namespace structures
{
	template <typename T>
	class Matica : public Structure
	{
	public:
		Matica();
		Matica(const Matica<T>& other);
		~Matica();
		virtual Structure* clone() const = 0;
		virtual size_t sizeX() const = 0;
		virtual size_t sizeY() const = 0;
		virtual size_t size() const = 0;
		Structure& operator=(const Structure& other) override;
		virtual Matica<T>& operator=(const Matica<T>& other) = 0;
		virtual T& operator()(const int indexX, const int indexY) = 0;
		virtual const T operator()(const int indexX, const int indexY) const = 0;
	};

	template<typename T>
	inline Matica<T>::Matica() :
		Structure()
	{
	}

	template<typename T>
	inline Matica<T>::~Matica()
	{
	}

	template<typename T>
	inline Matica<T>::Matica(const Matica<T>& other)
	{
	}

	template<typename T>
	inline Structure& Matica<T>::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Matica<T>&>(other);
		}
		return *this;
	}


}

