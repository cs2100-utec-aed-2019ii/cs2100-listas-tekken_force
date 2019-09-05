#include "Node.h"
#include <iostream>

template <typename T>
class ForwardList{
protected:
    Node<T>* head;
public:
    ForwardList();
    ForwardList(const T&);
    T& Front();
    T& Back();
    void Push_back(const T&);
    void Push_front(const T&);
    T Pop_front();
    T Pop_back();
    bool Empty();
    unsigned int size();
    void clear();
    ForwardList& sort();
    ForwardList& reverse();

    T& operator[](int v);

    template <typename _T>
    friend std::ostream& operator<< (std::ostream& os, const ForwardList<_T>& F){
        Node<T>* temp;
        temp = F.head;
        while(temp){
            os << temp->get_value() << " ";
            temp = temp->Next;
        }
        return os;
    }
};
