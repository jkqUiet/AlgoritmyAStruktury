#pragma once

#include "priority_queue.h"
#include "priority_queue_limited_sorted_array_list.h"
#include "../list/linked_list.h"
#include <cmath>

#define STRATEGIA1 1
#define STRATEGIA2 2
#define STRATEGIA3 3 

namespace structures
{
	/// <summary> Prioritny front implementovany dvojzoznamom. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	/// <remarks> Implementacia efektivne vyuziva prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou a LinkedList. </remarks>
	template<typename T>
	class PriorityQueueTwoLists : public PriorityQueue<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueTwoLists(int defaultCapacity, int strategia);
		PriorityQueueTwoLists();
		PriorityQueueTwoLists(const PriorityQueueTwoLists<T>& other);
		~PriorityQueueTwoLists();

		Structure* clone() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Prioritny front, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento prioritny front nachadza po priradeni. </returns>
		PriorityQueue<T>& operator=(const PriorityQueue<T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Prioritny front implementovany dvojzoznamom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento prioritny front nachadza po priradeni. </returns>
		PriorityQueueTwoLists<T>& operator=(const PriorityQueueTwoLists<T>& other);

		/// <summary> Vrati pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </summary>
		/// <returns> Pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </returns>
		size_t size() const override;

		/// <summary> Vymaze obsah prioritneho frontu implementovaneho dvojzoznamom. </summary>
		void clear() override;

		void push(const int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z prioritneho frontu implementovaneho dvojzoznamom. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>  
		T pop() override;

		/// <summary> Vrati adresou prvok s najvacsou prioritou. </summary>
		/// <returns> Adresa, na ktorej sa nachadza prvok s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>  
		T& peek() override;

		/// <summary> Vrati kopiu prvku s najvacsou prioritou. </summary>
		/// <returns> Kopia prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>  
		const T peek() const override;

		/// <summary> Vrati prioritu prvku s najvacsou prioritou. </summary>
		/// <returns> Priorita prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>  
		int peekPriority() const override;
	
	private:
		/// <summary> Smernik na prioritny front ako implementovany utriednym ArrayList-om s obmedzenou kapacitou . </summary>
		/// <remarks> Z pohladu dvojzoznamu sa jedna o kratsi utriedeny zoznam. </remarks>
		PriorityQueueLimitedSortedArrayList<T>* shortList_;
		int strategia;
		/// <summary> Smernik na dlhsi neutriedeny zoznam. </summary>
		LinkedList<PriorityQueueItem<T>*>* longList_;
	};

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists(int defaultCapacity, int strategia) :
		strategia(strategia),
		shortList_(new PriorityQueueLimitedSortedArrayList<T>(defaultCapacity)),
		longList_(new LinkedList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists() :
		shortList_(new PriorityQueueLimitedSortedArrayList<T>(4)),
		longList_(new LinkedList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists(const PriorityQueueTwoLists<T>& other) :
		PriorityQueueTwoLists<T>()
	{
		*this = other;
	}

	template<typename T>
	PriorityQueueTwoLists<T>::~PriorityQueueTwoLists()
	{
		clear();
		delete shortList_;
		delete longList_;
		shortList_ = nullptr;
		longList_ = nullptr;
	}

	template<typename T>
	Structure * PriorityQueueTwoLists<T>::clone() const
	{
		return new PriorityQueueTwoLists<T>(*this);
	}

	template<typename T>
	PriorityQueue<T>& PriorityQueueTwoLists<T>::operator=(const PriorityQueue<T>& other)
	{
		return *this = dynamic_cast<const PriorityQueueTwoLists<T>&>(other);
	}

	template<typename T>
	PriorityQueueTwoLists<T>& PriorityQueueTwoLists<T>::operator=(const PriorityQueueTwoLists<T>& other)
	{
		if (this != &other) {

			clear();
			*shortList_ = *other.shortList_;

			for (PriorityQueueItem<T>* p : *other.longList_) {
				this->longList_->add(new PriorityQueueItem<T>(*p));
			}
		}
		return *this;
	}

	template<typename T>
	size_t PriorityQueueTwoLists<T>::size() const
	{
		return this->longList_->size() + shortList_->PriorityQueueList<T>::size();
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::clear()
	{
		shortList_->PriorityQueueList<T>::clear();
		for (PriorityQueueItem<T>* p : *longList_) {
			delete p;
		}
		longList_->clear();// kedze toto boli iba pointre na queueuitemy tak musim najprv vymazat a potom clearnut
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::push(const int priority, const T & data)
	{
		if (longList_->size() == 0  || shortList_->minPriority() > priority) {
			PriorityQueueItem<T>* p = shortList_->pushAndRemove(priority, data);
			if (p != nullptr) {
				longList_->add(p);
			}
		}
		else {
			longList_->add(new PriorityQueueItem<T>(priority, data));
		}
	}

	template<typename T>
	T PriorityQueueTwoLists<T>::pop()
	{
		int defPrvky = 4;

		T p = shortList_->PriorityQueueList<T>::pop();

		if (shortList_->PriorityQueueList<T>::size() == 0 && longList_->size() != 0) {
			if (strategia != STRATEGIA1) {
				if (sqrt(longList_->size()) >= defPrvky) {
					switch (strategia) {
					case STRATEGIA2:
						shortList_->trySetCapacity(sqrt(longList_->size()));
						break;
					case STRATEGIA3:
						shortList_->trySetCapacity(longList_->size() / 2);
						break;
					default:
						shortList_->trySetCapacity(sqrt(longList_->size()));
					}
				}
				else {

					shortList_->trySetCapacity(defPrvky);
				}
			}

			LinkedList<PriorityQueueItem<T>*>* nLList = new LinkedList<PriorityQueueItem<T>*>();

				PriorityQueueItem<T>* newItem;
				PriorityQueueItem<T>* removedItem;

				while (longList_->size() > 0)
				{
					newItem = longList_->removeAt(0);
					removedItem = shortList_->pushAndRemove(newItem->getPriority(), newItem->accessData());
					delete newItem; // mazeme vytvoreny prvok
					if (removedItem != nullptr)
					{
						nLList->add(removedItem);
					}
				}
			delete longList_;
			longList_ = nLList;
		}
		return p;
	}

	template<typename T>
	T & PriorityQueueTwoLists<T>::peek()
	{
		return shortList_->PriorityQueueList<T>::peek();
	}

	template<typename T>
	const T PriorityQueueTwoLists<T>::peek() const  // nevolame pretazenie s PQL lebo je tam N zlozitost
	{
		return shortList_->PriorityQueueList<T>::peek();
	}

	template<typename T>
	int PriorityQueueTwoLists<T>::peekPriority() const
	{
		return shortList_->PriorityQueueList<T>::peekPriority();
	}
}