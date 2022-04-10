#include "SinglyLinkedList.h"

// constructor
template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	leftEnd = rightEnd = nullptr;
	length = 0;
}

// destructor _ free memory
template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	// delete each node of linked list
	SingleNode<T> *it = leftEnd, *temp;
	while (it != nullptr) {
		temp = it;
		it = it->next;
		delete temp;
	}

	leftEnd = rightEnd = nullptr;
	length = 0;
}

template<class T>
int SinglyLinkedList<T>::Length() const
{
	return length;
}

// A method takes a starting point and a key to find and check if the key exists
template<class T>
bool SinglyLinkedList<T>::Find(int k, T & x) const
{
	if (k < 0 || k >= length)
		return false;


	SingleNode<T> *it = leftEnd;

	// repeat until the position
	for (int i = 0; i < k; i++) {
		it = it->next;
	}

	x = it->data;
	return true;
}

// A method that searches for a specific key and return its position
template<class T>
int SinglyLinkedList<T>::Search(const T & x) const
{
	// declare repeat ptr
	SingleNode<T> *it = leftEnd;

	// repeat until find it
	for (int i = 0; i < length; i++) {
		if (it->data == x)
			return i;
		it = it->next;
	}

	// otherwise
	return -1;
}

// A method that deletes an element by a given key
template<class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Delete(int k, T & x)
{
	// repeat ptr
	SingleNode<T> *it = leftEnd, *temp;

	// check index and that's not empty
	if (k < 0 || k >= length || isEmpty())
		return *this;


	// in case its the first element
	else if (k == 0) {
		temp = leftEnd;
		leftEnd = leftEnd->next;
	}

	// otherwise iterate untill the prev to the position given
	else {
		for (int i = 0; i < k - 1; i++) {
			it = it->next;
		}

		// in case it's the last element
		if (k == length - 1) {
			temp = rightEnd;
			rightEnd = it;
			rightEnd->next = nullptr;
		}

		// in case it's in between
		else {
			temp = it->next;
			it->next = temp->next;
		}
	}

	// delete the element and save its value
	x = temp->data;
	delete temp;
	length--;
	return *this;
}

// A methdod that inserts an element into agiven position
template<class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Insert(int k, const T & x)
{
	// A method that check the index is valid
	checkIndex(k);

	// create a new node
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data = x;

	// insert in case it's empty
	if (isEmpty()) {
		leftEnd = rightEnd = newNode;
	}

	// insert in case at the beginning
	else if (k == 0) {
		newNode->next = leftEnd;
		leftEnd = newNode;
	}

	// in case at the end
	else if (k == length) {
		rightEnd->next = newNode;
		rightEnd = newNode;
	}

	// otherwise in case in between
	else {
		// iterate untill the prev of the position given
		SingleNode<T> *it = leftEnd;
		for (int i = 0; i < k - 1; i++)
			it = it->next;

		SingleNode<T> *temp = it->next;
		it->next = newNode;
		newNode->next = temp;
	}

	length++;
	return *this;
}

// A method that prints the list to the given stream
template<class T>
void SinglyLinkedList<T>::Output(std::ostream & out) const
{
	// iterate and print every element
	SingleNode<T> *it = leftEnd;
	while (it != nullptr) {
		out << it->data;
		if (it->next != nullptr)
			out << ", ";
		it = it->next;
	}
}

// A method that gets the average value in the list using the sum
template<class T>
T SinglyLinkedList<T>::Aver()
{
	if (isEmpty())
		return 0;

	T sum = leftEnd->data;
	SingleNode<T> *it = leftEnd->next;
	while (it != nullptr) {
		sum += it->data;
		it = it->next;
	}
	return sum/length;
}

// A method to check if a list is empty
template<class T>
bool SinglyLinkedList<T>::isEmpty() {
	return (length == 0);
}

// A method that checks valid index
template<class T>
void SinglyLinkedList<T>::checkIndex(int index) {
	if (index < 0 || index > length)
		throw std::out_of_range("Index Out of Bounds");
}
