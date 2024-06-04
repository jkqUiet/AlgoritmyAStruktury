#pragma once

#include "Matica.h"
#include "../array/array.h"
#include "../ds_routines.h"

namespace structures
{

	/**
	Atributy MaticeNesuvislej	:	array_ = pointer na pole pointrov na polia o velkostiY s prvkami typu T
									velkostX = rozmer X matice
									velkostY = rozmer Y matice
	*/


	/*
	POPIS	:	ide o maticu implementovanu nesuvislou pametou, teda mame pole, v ktorom su naukladane pointre na dalsie polia, pristupujeme
				dereferencovanim pointrov na polia a naslednim zavolanim []
				operator[][], som nevedel naimplementovat, zamenil som ho za operator(int indexX, int indexY)
	*/

	template<typename T>
	class MaticaNesuvisla : public Matica<T>
	{
	public:

		MaticaNesuvisla(const size_t rozmerX, const size_t rozmerY, size_t iniHodnota);
		MaticaNesuvisla(const MaticaNesuvisla<T>& other);
		~MaticaNesuvisla();
		Structure* clone() const override;
		size_t size() const override;
		size_t sizeX() const override;
		size_t sizeY() const override;
		Matica<T>& operator=(const Matica<T>& other) override;
		MaticaNesuvisla<T>& operator=(const MaticaNesuvisla<T>& other);
		bool operator==(const MaticaNesuvisla<T>& other) const;
		T& operator()(const int indexX, const int indexY);
		const T operator()(const int indexX, const int indexY) const;

	private:
		Array <Array<T>*>* array_;
		size_t velkostX;
		size_t velkostY;
	};

	template<typename T>
	MaticaNesuvisla<T>::MaticaNesuvisla(const size_t rozmerX, const size_t rozmerY, size_t iniHodnota) :
		array_(new Array<Array<T>*>(rozmerX)),
		velkostX(rozmerX),
		velkostY(rozmerY)
	{
		for (int i = 0; i < rozmerX; i++) {
			(*array_)[i] = new Array<T>(rozmerY);
			for (int j = 0; j < rozmerY; j++) {
				(*(*array_)[i])[j] = iniHodnota;
			}
		}
	}

	template<typename T>
	MaticaNesuvisla<T>::MaticaNesuvisla(const MaticaNesuvisla<T>& other) :
		MaticaNesuvisla<T>(other.velkostX, other.velkostY, 0)
	{
		*this = other;
	}

	template<typename T>
	MaticaNesuvisla<T>::~MaticaNesuvisla()
	{
		for (int i = 0; i < velkostX; i++) {
			delete (*array_)[i];
			(*array_)[i] = nullptr;
		}
		velkostX = 0;
		velkostY = 0;
		delete array_;
		array_ = nullptr;
	}

	template<typename T>
	Structure* MaticaNesuvisla<T>::clone() const
	{
		return new MaticaNesuvisla<T>(*this);
	}

	template<typename T>
	inline size_t MaticaNesuvisla<T>::size() const
	{
		return velkostX * velkostY;
	}

	template<typename T>
	Matica<T>& MaticaNesuvisla<T>::operator=(const Matica<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const MaticaNesuvisla<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	MaticaNesuvisla<T>& MaticaNesuvisla<T>::operator=(const MaticaNesuvisla<T>& other)
	{
		if (this != &other)
		{
			if (velkostX != other.velkostX || velkostY != other.velkostY)
			{
				throw std::invalid_argument("Class : maticaNesuvisla : operator= : Rozne velkosti matic");
			}
			
			for (int i = 0; i < velkostX; i++) {
				(*array_)[i] = (*other.array_)[i];
			}
		}
		return *this;
	}

	template<typename T>
	inline size_t MaticaNesuvisla<T>::sizeX() const
	{
		return velkostX;
	}

	template<typename T>
	inline size_t MaticaNesuvisla<T>::sizeY() const
	{
		return velkostY;
	}

	template<typename T>
	inline bool MaticaNesuvisla<T>::operator==(const MaticaNesuvisla<T>& other) const
	{
		if (velkostX != other.velkostX || velkostY != other.velkostY) {
			return false;
		}
		else {
			for (int i = 0; i < velkostX; i++) {
				if (*(array_[i]) != *(other.array_[i])) {
					return false;
				}
			}
		}
		return true;
	}
	// Prerobit excepty kvoli stacku spomaluje to 

	template<typename T>
	inline T& MaticaNesuvisla<T>::operator()(const int indexX, const int indexY)
	{
		if (indexX >= velkostX || indexY >= velkostY) {
			throw std::out_of_range("Class : maticaNesuviska : operator() : out of range");
		}
		return (*(*array_)[indexX])[indexY];
	}

	template<typename T>
	inline const T MaticaNesuvisla<T>::operator()(const int indexX, const int indexY) const
	{
		if (indexX >= velkostX || indexY >= velkostY) {
			throw std::out_of_range("Class : maticaNesuviska : operator() : out of range");
		}
		return (*(*array_)[indexX])[indexY];
	}

}