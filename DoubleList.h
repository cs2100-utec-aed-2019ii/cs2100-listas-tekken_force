#ifndef JERARQUIA_LISTAS_DOUBLELIST_H
#define JERARQUIA_LISTAS_DOUBLELIST_H
#include "List.h"
#include "DoubleListNode.h"
template<class T>
class DoubleList {
private:
    DoubleListNode<T>* Head;
    DoubleListNode<T>* Tail;
public:
    DoubleList(DoubleList<T>&);
    DoubleList(T*);
    DoubleList(DoubleListNode<T>*);
    DoubleList(int);
    DoubleList();
    ~DoubleList();
};

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& copia) {

}

template<class T>
DoubleList<T>::DoubleList(T * arr) {

}

template<class T>
DoubleList<T>::DoubleList(int n) {

}

template<class T>
DoubleList<T>::DoubleList(DoubleListNode<T>* p) {

}

template<class T>
T& Front(){
    return DoubleList<T>::Head->value;
}


#endif