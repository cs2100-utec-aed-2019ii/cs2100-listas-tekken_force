#ifndef JERARQUIA_LISTAS_DOUBLELISTNODE_H
#define JERARQUIA_LISTAS_DOUBLELISTNODE_H

#include "Node.h"

template <class T>
class DoubleListNode : public Node<T>{
public:
    Node<T>* Prev;
    DoubleListNode(T v);
    ~DoubleListNode();
};

template <class T>
DoubleListNode<T>::DoubleListNode(T v) : Node<T>(v){
    this->Prev = nullptr;
}


#endif