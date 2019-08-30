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

	template<typename _T>
    friend std::ostream& operator<< (std::ostream& os, const ForwardList<_T>& F){
        os << "El valor del head es : " << *(F.head) << std::endl;
        return os;
    }
};
