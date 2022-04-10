#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"

using namespace std;

int main() {
	SinglyLinkedList<int> list;
	cout<<"Single linked list :"<<endl;
	list.Insert(1,8);
	list.Insert(3,1);
	list.Insert(2,9);
	list.Insert(0,2);
	list.Insert(4,11)
	// display average
		cout <<"the average:"<<list.Aver()<<endl;
	system("pause");
	return 0;
}
