#ifndef Single_
#define Single_
#include <iostream>
#include <string>
template <class T>
class SingleNode
{
public:
	T data;
	SingleNode<T> *next;

	SingleNode()
	{
		next = nullptr;
	}
	~SingleNode() {}
};

template <class T>
class SinglyLinkedList
{
public:
	// constructor
	SinglyLinkedList();
	//destructor
	~SinglyLinkedList();

	// needed and basic methods
	int Length() const;
	int Search(const T& x) const;
	SinglyLinkedList<T>& Delete(int k, T& x);
	bool Find(int k, T& x) const;
	void Output(std::ostream& out) const;
	SinglyLinkedList<T>& Insert(int k, const T& x);

	//my method
	//the method that get the average
	T Aver();
private:
	// data members
	SingleNode<T> *leftEnd, *rightEnd;
	int length;

	// methods needed
	bool isEmpty();
	void checkIndex(int index);
};

#endif
