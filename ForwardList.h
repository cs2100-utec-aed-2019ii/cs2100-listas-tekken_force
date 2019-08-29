#include "Node.h"

template <typename T>
class ForwardList{
protected:
	Node<T>* head;
public:
	ForwardList();
	ForwardList(const T&)
	T& Front();
	T& Back();
	void Push_back(const T&);
	void Push_front(const T&);
	Node<T>* Pop_front();
	Node<T>* Pop_back();
	T& operator[](const int&);
	bool Empty();
	unsigned int size();
	void clear();
	ForwardList& sort();
	ForwardList& reverse();
	std::ostream& operator<< (const ForwardList&, std::ostream&);
}