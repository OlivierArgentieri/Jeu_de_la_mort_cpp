#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class MyNewList
{
	template <typename T> friend class Iterator;
	template<typename T> friend class Node;
public:
	MyNewList()//Initialize list
	{
		Header = nullptr;
		Queue = nullptr;
		size = 0;
	}
	MyNewList(const MyNewList &_refNewList)
	{
		size = 0;
		for(Node<T> *ptr_node = _refNewList.Header; ptr_node != nullptr ; ptr_node = ptr_node->Next)
		{
			PushBack(ptr_node->value);
		}
	}
	~MyNewList()
	{
		Clear();
	}
	void PushFront(T NewElement)//Add new element at front of the list
	{
		AddAt(NewElement, this->Begin());
	}
	void PushBack(T NewElement)//Add new element at back of the list
	{
		AddAt(NewElement, this->End());
	}
	void AddAt(T NewElement, Iterator<T> Position)//Add new element at a position i
	{
		Node<T> *newNode = new Node<T>();
		newNode->value = NewElement;
		if (Position.element == nullptr && size == 0)
		{
			Header = newNode;
			Queue = newNode;
		}
		else if (Position.element == nullptr)
		{
			Queue->Next = newNode;
			newNode->Previous = Queue;
			Queue = newNode;
		}
		else if (Position.element->Previous == nullptr)
		{
			newNode->Next = Header;
			Header->Previous = newNode;
			Header = newNode;
		}
		else
		{
			newNode->Previous = Position.element->Previous;
			newNode->Next = Position.element;
			Position.element->Previous->Next = newNode;
			Position.element->Previous = newNode;
		}
		size++;
	}
	void EraseFront()//Erase first element of the list
	{
		EraseAt(this->Begin());
	}
	void EraseBack()//Erase last element of the list
	{
		EraseAt(this->Begin().operator++(size - 1));
	}

	Iterator<T> EraseAt(Iterator<T> Position)//Erase at a position i
	{
		if (Position.element != nullptr)
		{
			Iterator<T> ToReturn;
			if (Header != Queue)
			{
				if (Position.element->Next == nullptr)
				{
					Queue = Queue->Previous;
					Queue->Next = nullptr;
					ToReturn = End();
				}
				else if (Position.element->Previous == nullptr)
				{
					Header = Header->Next;
					Header->Previous = nullptr;
					ToReturn = Begin();
				}
				else
				{
					Position.element->Next->Previous = Position.element->Previous;
					Position.element->Previous->Next = Position.element->Next;
					ToReturn = Position;
				}
				delete(Position.element);
			}
			else
			{
				delete(Header);
				ToReturn = End();
			}
			size--;
			return ToReturn;
		}
		else
			throw std::out_of_range("ERROR");
	}

	void Clear()//Erase all elements
	{
		while (size != 0)
		{
			EraseFront();
		}
		Header = nullptr;
		Queue = nullptr;
	}
	void Remove(T i)//Remove an element i of the liste
	{
		int j = 0;
		Iterator<T> it = Begin();
		while (j != size)
		{
			if (it.element->HaveValue() == i && it.element->Previous == nullptr)
			{
				EraseFront();
				it = Begin();
				j--;
			}
			else if (it.element->HaveValue() == i && it.element->Next == nullptr)
			{
				EraseBack();
				it = End();
				j--;
			}
			else if (it.element->HaveValue() == i)
			{
				EraseAt(this->Begin().operator++(j));
				j--;
				it = this->Begin().operator++(j + 1);
			}
			else
				it.operator++();
			j++;
		}
	}

	Iterator<T> Begin()//Get first element of the list
	{
		return Iterator<T>(Header, this);
	}

	Iterator<T> End()//Get last element of the list
	{
		return Iterator<T>(nullptr, this);
	}

	int Size()//Get list size
	{
		return size;
	}

	Iterator<T> At(int i)//Search a node at a position i
	{
		int j = 0;
		Iterator<T> it = Iterator<T>(Header, this);
		while (j != i)
		{
			if (it.element != nullptr)
			{
				it.operator++();
				j++;
			}
			else
				throw std::out_of_range("ERROR");
		}
		return it;
	}

private:

	Node<T> *Header;
	Node<T> *Queue;
	int size;

	//void SwapNodes(Iterator<T> *First, Iterator<T> *Second)//Swap Nodes
	//{
	//	Iterator<T> *swapnode = new Iterator<T>();
	//	if (First->element != nullptr && Second->element != nullptr)
	//	{
	//		InitializationNewNode(swapnode, First);
	//		ChangeNode(First, Second);
	//		ChangeNode(Second, swapnode);
	//		delete(swapnode);
	//	}
	//	else
	//		throw std::out_of_range("ERROR");
	//}

	//void InitializationNewNode(Iterator<T> *NewNode, Iterator<T> *BaseNode)//Initialization for placing a new node
	//{
	//	NewNode->element->Next = BaseNode->element->Next;
	//	NewNode->element->Previous = BaseNode->element->Previous;
	//	NewNode->element->value = BaseNode->element->value;
	//}

	//void ChangeNode(Iterator<T> *First, Iterator<T> *Second)//Affect second node to first node
	//{
	//	if (First->element->Next == Second->element)
	//	{
	//		First->element->Next = Second->element->Next;
	//		First->element->Previous = Second->element;
	//	}
	//	else if (First->element->Previous = Second->element)
	//	{
	//		First->element->Previous = Second->element->Previous;
	//		First->element->Next = First->element;
	//	}
	//	else
	//	{
	//		First->element->Next = Second->element->Next;
	//		First->element->Previous = Second->element->Previous;
	//	}
	//	Verification(First, Second);
	//}

	//void Verification(Iterator<T> *First, Iterator<T> *Second)
	//{
	//	if (Second->element->Next != nullptr)
	//		Second->element->Next->Previous = First->element;
	//	if (Second->element->Previous != nullptr)
	//		Second->element->Previous->Next = First->element;
	//	if (First->element->Next == nullptr)
	//		Queue = First->element;
	//	if (First->element->Previous == nullptr)
	//		Header = First->element;
	//}
};
