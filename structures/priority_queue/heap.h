#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include <exception>

namespace structures
{
	/// <summary> Prioritny front implementovany haldou. Implementujucim typom haldy je struktura ArrayList. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class Heap : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Heap();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Halda, z ktorej sa prevezmu vlastnosti. </param>
		Heap(const Heap<T>& other);

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat haldy. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Prioritny front implementovany zoznamom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento prioritny front nachadza po priradeni. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak vstupny parameter nie je halda. </exception>  
		/// <remarks> Vyuziva typovy operator priradenia. </remarks>
		virtual PriorityQueueList<T>& operator=(const PriorityQueueList<T>& other) override;

		/// <summary> Operator priradenia pre haldu. </summary>
		/// <param name = "other"> Halda, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato halda nachadza po priradeni. </returns>
		virtual Heap<T>& operator=(const Heap<T>& other);

		/// <summary> Vlozi prvok s danou prioritou do haldy. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(const int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z haldy. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je halda prazdna. </exception>  
		T pop() override;

	protected:
		/// <summary> Vrati index v ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je ArrayList prazdny. </exception>  
		int indexOfPeek() const override;

	private:
		/// <summary> Vrati index v ArrayList-e, na ktorom by sa mal nachadzat otec daneho prvku. </summary>
		/// <param name = "index"> Index prvku, ktoreho otca chceme vratit. </param>
		/// <returns> Index, na ktorom ba sa mal nachadzat otec prvku. </returns>
		int getParentIndex(const int index);

		/// <summary> Vrati index v ArrayList-e, na ktorom by mal mat dany prvok syna s najvacsou prioritou. </summary>
		/// <param name = "index"> Index prvku, ktoreho syna chceme vratit. </param>
		/// <returns> Index, na ktorom by sa mal nachadzat syn prvku. </returns>
		int getGreaterSonIndex(const int index);
	};

	template<typename T>
	Heap<T>::Heap() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	Heap<T>::Heap(const Heap<T>& other) :
		Heap<T>()
	{
		*this = other;
	}

	template<typename T>
	Structure* Heap<T>::clone() const
	{
		return new Heap<T>(*this);
	}

	template<typename T>
	inline PriorityQueueList<T>& Heap<T>::operator=(const PriorityQueueList<T>& other)
	{
		return *this = dynamic_cast<const Heap<T>&>(other);
	}

	template<typename T>
	inline Heap<T>& Heap<T>::operator=(const Heap<T>& other)
	{
		if (this != &other)
		{
			PriorityQueueList<T>::operator=(other);
		}
		return *this;
	}

	template<typename T>
	void Heap<T>::push(const int priority, const T& data)
	{
		list_->add(new PriorityQueueItem<T>(priority, data));

		int indexCur = list_->size() - 1;
		int indexPar = getParentIndex(indexCur);

		while (indexPar != -1 && (*list_)[indexCur]->getPriority() < (*list_)[indexPar]->getPriority())
		{
			DSRoutines::swap((*list_)[indexCur], (*list_)[indexPar]);
			indexCur = indexPar;
			indexPar = getParentIndex(indexCur);
		}
	}

	template<typename T>
	T Heap<T>::pop()
	{
		int indexPopped = indexOfPeek();
		int indexLast = list_->size() - 1;

		DSRoutines::swap((*list_)[indexPopped], (*list_)[indexLast]);
		PriorityQueueItem<T>* item = list_->removeAt(indexLast);

		int indexCur = list_->size() - 1;
		int indexSon = getParentIndex(indexCur);

		while (indexSon != -1 && (*list_)[indexCur]->getPriority() < (*list_)[indexSon]->getPriority())
		{
			DSRoutines::swap((*list_)[indexCur], (*list_)[indexSon]);
			indexCur = indexSon;
			indexSon = getParentIndex(indexCur);
		}

		T result = item->accessData();
		delete item;
		return result;
	}

	template<typename T>
	inline int Heap<T>::getParentIndex(const int index)
	{
		return (index + 1) / 2 - 1;
	}

	template<typename T>
	inline int Heap<T>::getGreaterSonIndex(const int index)
	{
		int indexLeft = 2 * index + 1;
		int indexRight = 2 * index + 2;

		PriorityQueueItem<T>* sonLeft = indexLeft < list_ ->size() ? (*list_)[indexLeft] : nullptr;
		PriorityQueueItem<T>* sonRight = indexRight < list_ ->size() ? (*list_)[indexRight] : nullptr;

		if (sonLeft == nullptr && sonRight == nullptr) {
			return -1;
		}
		if (sonLeft != nullptr && sonRight != nullptr) {
			return sonLeft->getPriority() < sonRight->getPriority() ? indexLeft : indexRight;
		}
		return indexLeft;
	}

	template<typename T>
	inline int Heap<T>::indexOfPeek() const
	{
		if (list_->isEmpty()) {
			throw std::logic_error("Class : PriorityQueueList : funkcia indexOfPeek, List je prazdny!!!");
		}

		return 0;
	}
}