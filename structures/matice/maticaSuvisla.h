#pragma once

#include "MaticaSuvisla.h"
#include "../array/array.h"
#include "../ds_routines.h"

namespace structures
{

	/**
	Atributy MaticeSuvislej		:	array_ = pointer na pole o velkosti velkostY*velkostX s prvkami typu T
									velkostX = rozmer X matice
									velkostY = rozmer Y matice
	*/

	/*
	POPIS	:	ide o maticu implementovanu suvislou pametou, teda mame pole, v ktorom su naukladane prvky typu T pristupujeme cez array_[]
				operator[][], som nevedel naimplementovat, zamenil som ho za operator(int indexX, int indexY)
	*/


	template<typename T>
	class MaticaSuvisla : public Matica<T>
	{
	public:
	
		MaticaSuvisla(const size_t rozmerX, const size_t rozmerY, size_t iniHodnota);
		MaticaSuvisla(const MaticaSuvisla<T>& other);
		~MaticaSuvisla();
		Structure* clone() const override;
		size_t sizeX() const override;
		size_t sizeY() const override;
		size_t size() const override;
		Matica<T>& operator=(const Matica<T>& other) override;
		MaticaSuvisla<T>& operator=(const MaticaSuvisla<T>& other);
		bool operator==(const MaticaSuvisla<T>& other) const;
		T& operator()(const int indexX, const int indexY);
		const T operator()(const int indexX, const int indexY) const;

	private:
		Array<T>* array_;
		size_t velkostX;
		size_t velkostY;
	};

	template<typename T>
	MaticaSuvisla<T>::MaticaSuvisla(const size_t rozmerX, const size_t rozmerY, size_t iniHodnota) :
		array_(new Array<T>(rozmerX * rozmerY)),
		velkostX(rozmerX),
		velkostY(rozmerY)
	{
		for (int i = 0; i < velkostX * velkostY; i++) {
			(*array_)[i] = iniHodnota;
		}
	}

	template<typename T>
	MaticaSuvisla<T>::MaticaSuvisla(const MaticaSuvisla<T>& other) :
		MaticaSuvisla<T>(other.velkostX, other.velkostY, 0)
	{
		*this = other;
	}

	template<typename T>
	MaticaSuvisla<T>::~MaticaSuvisla()
	{
		delete array_;
		array_ = nullptr;
		velkostX = 0;
		velkostY = 0;
	}

	template<typename T>
	Structure* MaticaSuvisla<T>::clone() const
	{
		return new MaticaSuvisla<T>(*this);
	}

	template<typename T>
	Matica<T>& MaticaSuvisla<T>::operator=(const Matica<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MaticaSuvisla<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	MaticaSuvisla<T>& MaticaSuvisla<T>::operator=(const MaticaSuvisla<T>& other)
	{
		if (this != &other)
		{
			if (velkostX != other.velkostX || velkostY != other.velkostY)
			{
				throw std::invalid_argument("Class : maticaSuvisla : operator= : Rozne velkosti matic");
			}
			*array_ = *(other.array_);
		}
		return *this;
	}

	template<typename T>
	inline size_t MaticaSuvisla<T>::sizeX() const
	{
		return velkostX;
	}

	template<typename T>
	inline size_t MaticaSuvisla<T>::sizeY() const
	{
		return velkostY;
	}

	template<typename T>
	inline size_t MaticaSuvisla<T>::size() const
	{
		return velkostX * velkostY;
	}

	template<typename T>
	inline bool MaticaSuvisla<T>::operator==(const MaticaSuvisla<T>& other) const
	{
		return *array_ == *other.array_;
	}

	template<typename T>
	inline T& MaticaSuvisla<T>::operator()(const int indexX, const int indexY)
	{
		if (indexX >= velkostX || indexY >= velkostY) {
			throw std::out_of_range("Class : maticaSuviska : operator() : out of range");
		}
		return (*array_)[indexX * velkostY + indexY];
	}

	template<typename T>
	inline const T MaticaSuvisla<T>::operator()(const int indexX, const int indexY) const
	{
		if (indexX >= velkostX || indexY >= velkostY) {
			throw std::out_of_range("Class : maticaSuviska : operator() : out of range");
		}
		return (*array_)[indexX * velkostY + indexY];
	}
}