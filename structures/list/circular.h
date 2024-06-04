#pragma once

#include "list.h"
#include "../structure_iterator.h"
#include "../ds_routines.h"

namespace structures
{
	/**
	Atributy CircularListItemu	:	next_ - ako v linkedListe, ukazuje na dalsi prvok v poradi
									prevoius_ ukazuje na jeho predchodcu
	*/

	template<typename T>
	class CircularListItem : public DataItem<T>
	{
	public:
		CircularListItem(T data);
		CircularListItem(const CircularListItem<T>& other);
		~CircularListItem();
		CircularListItem<T>* getNext();
		CircularListItem<T>* getPrevious();
		void setNext(CircularListItem<T>* next);
		void setPrevious(CircularListItem<T>* previous);
	private:
		CircularListItem<T>* next_;
		CircularListItem<T>* previous_;
	};

	/**
	Atributy CircularListItemu	:	size_  = pocet prvkov v zozname
									first_ = ako v linkedListe, ukazuje na prvy prvok zoznamu
									last_  = --------||-------, ukazuje na posledny prvok zoznamu
	*/


	/*
	POPIS	:	ide o obojstranne zretazeny zoznam teda sa vieme posuvat smerom ku koncu aj k zaciatku, pricom 
				ak sme na zaciatku a zapytame si predchodcu tak nam vrati posledny a naopak ak sme na konci 
				a zapytame si nasledovnika tak nam vrati prvy prvok. 

				az na to obojstranne zretazenie je to v principe linkedlist
	*/

	template<typename T>
	class CircularList : public List<T>
	{
	public:
		CircularList();
		CircularList(const CircularList<T>& other);
		~CircularList();
		Structure* clone() const override;
		size_t size() const override;
		List<T>& operator=(const List<T>& other) override;
		CircularList<T>& operator=(const CircularList<T>& other);
		T& operator[](const int index) override;
		const T operator[](const int index) const override;
		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;
		Iterator<T>* getBeginIterator() const override;
		Iterator<T>* getEndIterator() const override;
	private:
		size_t size_;
		CircularListItem<T>* first_;
		CircularListItem<T>* last_;
	private:
		CircularListItem<T>* getItemAtIndex(int index) const;
	private:
		class CircularListIterator : public Iterator<T>
		{
		public:
			CircularListIterator(CircularListItem<T>* position);
			~CircularListIterator();
			Iterator<T>& operator= (const Iterator<T>& other) override;
			bool operator!=(const Iterator<T>& other) override;
			const T operator*() override;
			Iterator<T>& operator++() override;
			Iterator<T>& operator--();
		private:
			CircularListItem<T>* position_;
		};
	};

	template<typename T>
	inline CircularListItem<T>::CircularListItem(T data) :
		DataItem<T>(data),
		next_(nullptr),
		previous_(nullptr)
	{
	}

	template<typename T>
	inline CircularListItem<T>::CircularListItem(const CircularListItem<T>& other) :
		DataItem<T>(other),
		next_(other.next_),
		previous_(other.previous_)
	{
	}

	template<typename T>
	inline CircularListItem<T>::~CircularListItem()
	{
		next_ = nullptr;
		previous_ = nullptr;
	}

	template<typename T>
	inline CircularListItem<T>* CircularListItem<T>::getNext()
	{
		return next_;
	}

	template<typename T>
	inline CircularListItem<T>* CircularListItem<T>::getPrevious()
	{
		return previous_;
	}

	template<typename T>
	inline void CircularListItem<T>::setNext(CircularListItem<T>* next)
	{
		next_ = next;
	}

	template<typename T>
	inline void CircularListItem<T>::setPrevious(CircularListItem<T>* previous)
	{
		previous_ = previous;
	}

	template<typename T>
	inline CircularList<T>::CircularList() :
		List<T>::List(),
		size_(0),
		first_(nullptr),
		last_(nullptr)
	{
	}

	template<typename T>
	inline CircularList<T>::CircularList(const CircularList<T>& other) :
		CircularList<T>()
	{
		*this = other;
	}

	template<typename T>
	inline CircularList<T>::~CircularList()
	{
		clear();
	}

	template<typename T>
	inline Structure* CircularList<T>::clone() const
	{
		return new CircularList<T>(*this);
	}

	template<typename T>
	inline size_t CircularList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	inline List<T>& CircularList<T>::operator=(const List<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const CircularList<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other)
	{
		if (this != &other)
		{
			clear();
			CircularListItem<T>* item = other.first_;
			int var = 0;

			while (var < size_)
			{
				add(item->accessData());
				item = item->getNext();
				var++;
			}
			delete item;
		}

		return *this;
	}

	template<typename T>
	inline T& CircularList<T>::operator[](const int index)
	{
		return getItemAtIndex(index)->accessData();
	}

	template<typename T>
	inline const T CircularList<T>::operator[](const int index) const
	{
		return getItemAtIndex(index)->accessData();
	}

	template<typename T>
	inline void CircularList<T>::add(const T& data)
	{
		CircularListItem<T>* item = new CircularListItem<T>(data);

		if (first_ == nullptr)
		{
			first_ = item;
			last_ = item;
			item->setPrevious(last_);
			item->setNext(first_);
		}
		else
		{
			last_->setNext(item);
			item->setNext(first_);
			item->setPrevious(last_);
			first_->setPrevious(item);
			last_ = item;
		}
		size_++;
	}

	template<typename T>
	inline void CircularList<T>::insert(const T& data, const int index)
	{
		if (index - 1 == size_ || size_ == 0)
		{
			add(data);
		}
		else
		{
			if (index >= size_) {
				throw std::out_of_range("Invalid index in cycled!");
			}

			CircularListItem<T>* item = new CircularListItem<T>(data);
			CircularListItem<T>* previousItem;
			if (index == 0)
			{
				item->setNext(first_);
				previousItem = last_;
				previousItem->setNext(item);
				first_->setPrevious(item);
				first_ = item;
			}
			else
			{
				previousItem = getItemAtIndex(index - 1);
				item->setNext(previousItem->getNext());
				item->getNext()->setPrevious(item);
				previousItem->setNext(item);
				item->setPrevious(previousItem);
			}
			size_++;
		}
	}

	template<typename T>
	inline bool CircularList<T>::tryRemove(const T& data)
	{
		int index = getIndexOf(data);
		if (index == -1)
			return false;
		else
		{
			removeAt(index);
			return true;
		}
	}

	template<typename T>
	inline T CircularList<T>::removeAt(const int index)
	{
		if (index >= size_) {
			throw std::out_of_range("Invalid index in cycled!");
		}

		CircularListItem<T>* dItem = nullptr;

		if (index != 0)
		{
			dItem = getItemAtIndex(index);
			CircularListItem<T>* previousItem = dItem->getPrevious();
			CircularListItem<T>* nextItem = dItem->getNext();
			previousItem->setNext(nextItem);
			nextItem->setPrevious(previousItem);

			if (last_ == dItem)
			{
				last_ = previousItem;
				last_->setNext(first_);
				first_->setPrevious(last_);
			}
		}
		else
		{
			dItem = first_;

			if (size_ == 1)
			{
				first_ = nullptr;
				last_ = nullptr;
			}
			else
			{
				first_ = first_->getNext();
				last_->setNext(first_);
				first_->setPrevious(last_);
			}
		}

		size_--;
		T data = dItem->accessData();

		delete dItem;

		return data;
	}


	template<typename T>
	inline int CircularList<T>::getIndexOf(const T& data)
	{
		CircularListItem<T>* cur = first_;
		int index = 0;

		if (index >= size_) {
			throw std::out_of_range("Invalid index in cycled!");
		}

		while (index < size_)
		{
			if (cur->accessData() == data)
			{
				return index;
				break;
			}
			index++;
			cur = cur->getNext();
		}
		return -1;
	}

	template<typename T>
	inline void CircularList<T>::clear()
	{
		CircularListItem<T>* dItem = first_;
		if (size_ > 0) {
			last_->setNext(nullptr);
			while (dItem != nullptr) {
				first_ = dItem->getNext();
				delete dItem;
				dItem = first_;
			}
		}
		first_ = nullptr;
		last_ = nullptr;
		size_ = 0;
	}

	template<typename T>
	inline CircularListItem<T>* CircularList<T>::getItemAtIndex(int index) const
	{
	
		if (index >= size_) {
			throw std::out_of_range("Invalid index in cycled!");
		}
		CircularListItem<T>* cur;

		if (index < (size_) / 2) {
			cur = first_;
			for (int i = 0; i < index; i++)
			{
				cur = cur->getNext();
			}
		}
		else {
			cur = last_;
			for (int i = size_-1; i > index; i--)
			{
				cur = cur->getPrevious();
			}
		}

		return cur;
	}

	template<typename T>
	inline Iterator<T>* CircularList<T>::getBeginIterator() const
	{
		return new CircularListIterator(first_);
	}

	template<typename T>
	inline Iterator<T>* CircularList<T>::getEndIterator() const
	{
		return new CircularListIterator(last_);
	}

	template<typename T>
	inline CircularList<T>::CircularListIterator::CircularListIterator(CircularListItem<T>* position) :
		position_(position)
	{

	}

	template<typename T>
	inline CircularList<T>::CircularListIterator::~CircularListIterator()
	{
		position_ = nullptr;
	}

	template<typename T>
	inline Iterator<T>& CircularList<T>::CircularListIterator::operator=(const Iterator<T>& other)
	{
		position_ = dynamic_cast<const CircularListIterator&>(other).position_;
		return *this;
	}

	template<typename T>
	inline bool CircularList<T>::CircularListIterator::operator!=(const Iterator<T>& other)
	{
		return position_ != dynamic_cast<const CircularListIterator&>(other).position_;
	}

	template<typename T>
	inline const T CircularList<T>::CircularListIterator::operator*()
	{
		return position_->accessData();
	}

	template<typename T>
	inline Iterator<T>& CircularList<T>::CircularListIterator::operator++()
	{
		position_ = position_->getNext();
		return *this;
	}

	template<typename T>
	inline Iterator<T>& CircularList<T>::CircularListIterator::operator--()
	{
		position_ = position_->getPrevious();
		return *this;
	}
}