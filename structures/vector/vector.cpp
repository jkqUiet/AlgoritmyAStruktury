#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			size_ = other.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_, other.memory_, size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		//nemusim davat And do zatvorky lebo je to sucin.
		return this == &other || size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
	}

	byte& Vector::operator[](const int index)
	{
		if (index >= size_) {
			throw std::out_of_range("Invalid index! VECTOR out of range");
		}
		//ziskaj ptrB z memory
		//posun ptrb
		//vrat *ptrb

		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte Vector::operator[](const int index) const
	{
		if (index >= size_) {
			throw std::out_of_range("Invalid index! VECTOR out of range");
		}
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		//TODO 01: Vector
		throw std::exception("Vector::readBytes: Not implemented yet.");
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length != 0)
		{
			if (srcStartIndex >= src.size_ || destStartIndex >= dest.size_ || srcStartIndex + length >= src.size_ + 1 || destStartIndex + length >= dest.size_ + 1) {
				throw std::out_of_range("Invalid index! VECTOR out of range");
			}
		
			if ((&src == &dest) && (((srcStartIndex >= destStartIndex) && (srcStartIndex < destStartIndex + length)) || ((destStartIndex >= srcStartIndex) && (destStartIndex < srcStartIndex + length))))
			{
				memmove(src.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
			else
			{
				memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		if (index >= size_) {
			throw std::out_of_range("Invalid index! VECTOR out of range");
		}
		return (reinterpret_cast<byte*>(memory_) + index);
	}

}