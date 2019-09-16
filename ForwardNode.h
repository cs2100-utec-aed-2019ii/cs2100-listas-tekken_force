#ifndef JERARQUIA_LISTAS_FORWARDNODE_H
#define JERARQUIA_LISTAS_FORWARDNODE_H
#include "Node.h"

template<class T>
class ForwardNode : public Node<T>{
public:
    ForwardNode<T>* next;
    ForwardNode();
	ForwardNode(T v);
    template<class Y>
    friend class ForwardList;

    template<class U>
    friend class CircularList;
};

template<class T>
ForwardNode<T>::ForwardNode() : Node<T>(){
	next = nullptr;
}


template<class T>
ForwardNode<T>::ForwardNode(T v) : Node<T>(v){
	next = nullptr;
}


#endif //JERARQUIA_LISTAS_FORWARDNODE_H
