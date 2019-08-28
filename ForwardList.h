#include "Node.h"

template <typename T>
class ForwardList{
protected:
	Node<T>* head;
public:
	ForwardList();
	T& Front();
	T& Back();
	void Push_back();
	void Push_front();
	Node<T>* Pop_front();
	Node<T>* Pop_back();
	T& operator[](int a);
	bool Empty();
	int size();
	void clear();
}