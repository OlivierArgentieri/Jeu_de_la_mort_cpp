#pragma once 
template<typename T>
class Node
{
	template <typename T> friend class MyNewList;
	template <typename T> friend class Iterator;
public:
	Node()
	{
		Previous = nullptr;
		Next = nullptr;
	}
	~Node()
	{

	}

private:

	Node<T> *Previous;
	Node<T> *Next;
	T value;
};

#pragma once
