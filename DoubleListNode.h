#ifndef ALGORITMOS_DOUBLELISTNODE_H
#define ALGORITMOS_DOUBLELISTNODE_H
#include "Node.h"

template <class T>
class DoubleListNode : public Node<T>{
public:
    Node<T>* Prev;
    DoubleListNode(T v);

    template<class _Y>
    friend class DoubleList;

    template<class H>
    friend class DoubleCircularList;
};

template <class T>
DoubleListNode<T>::DoubleListNode(T v) : Node<T>(v){
    this->Prev = nullptr;
}
#endif //ALGORITMOS_DOUBLELISTNODE_H
