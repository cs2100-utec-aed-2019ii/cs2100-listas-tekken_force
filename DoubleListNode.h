#ifndef JERARQUIA_LISTAS_DOUBLELISTNODE_H
#define JERARQUIA_LISTAS_DOUBLELISTNODE_H

#include "Node.h"

template <class T>
class DoubleListNode : public Node<T>{
public:
    DoubleListNode<T>* Prev;
    DoubleListNode<T>* Next;
    DoubleListNode();
    DoubleListNode(T v);
    template<class _Y>
    friend class DoubleList;
};

template<class T>
DoubleListNode<T>::DoubleListNode() : Node<T>(){
    Prev = nullptr;
    Next = nullptr;
}

template <class T>
DoubleListNode<T>::DoubleListNode(T v) : Node<T>(v){
    Prev = nullptr;
    Next = nullptr;
}


#endif //JERARQUIA_LISTAS_DOUBLELISTNODE_H
