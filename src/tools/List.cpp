#include "List.h"
using namespace std;

template<class T>
List<T>::List() {
	head = new Node();
	tail = head;
	size = 0;
}