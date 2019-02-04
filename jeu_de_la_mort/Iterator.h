#pragma once
#include "Node.h"
#include <stdexcept>

template<typename T>
class MyNewList;

template<typename T>
class Iterator
{
	template<typename T> friend class MyNewList;
	template<typename T> friend class Node;
public:

	Iterator()
	{

	}

	Iterator(Node<T> *position, MyNewList<T>* list)
	{
		element = position;
		m_list = list;
	}

	~Iterator()
	{

	}

	Iterator<T>& operator++(int i)
	{
		int j = 0;
		while (j != i && element != nullptr)
		{
			element = element->Next;
			j++;
		}
		if (j == i)
			return *this;
		else
			throw std::out_of_range("ERROR");
	}

	Iterator<T>& operator--(int i)
	{
		int j = 0;
		while (j != i && element != nullptr)
		{
			element = element->Previous;
			j++;
		}
		if (j == i)
			return *this;
		else
			throw std::out_of_range("ERROR");
	}

	bool operator==(Iterator<T> FirstElement)
	{
		return FirstElement.element == element;
	}

	bool operator!=(Iterator<T> FirstElement)
	{
		return FirstElement.element != element;
	}

	Iterator<T>& operator++()
	{
		if (element != nullptr)
		{
			element = element->Next;
			return *this;
		}
		else
			throw std::out_of_range("ERROR");
	}
	Iterator<T>& operator--()
	{
		if (element != nullptr)
		{
			element = element->Previous;
			return *this;
		}
		else if (element == m_list->End().element)
		{
			element = m_list->Queue;
			return *this;
		}
		else
			throw std::out_of_range("ERROR");
	}

	T& operator*()
	{
		return element->value;
	}

private:
	Node<T> *element;
	MyNewList<T> *m_list;
};