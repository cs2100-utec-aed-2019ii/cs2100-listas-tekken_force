//
// Created by DARIO on 14/09/2019.
//

#ifndef ALGORITMOS_FORWARDNODE_H
#define ALGORITMOS_FORWARDNODE_H
#include "Node.h"
template<class T>
class ForwardNode : public Node<T>{
public:
    typedef typename Node<T>::value_t value_t;
public:
    ForwardNode<T>* Next;
    ForwardNode(T v);
    template<class R>
    friend class List;

    template<class Y>
    friend class ForwardList;

    template<class U>
    friend class CircularList;
};

template <class T>
ForwardNode<T>::ForwardNode(T v) : Node<T>(v){
    this->Next = nullptr;
}
#endif //ALGORITMOS_FORWARDNODE_H
