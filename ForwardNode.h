#ifndef JERARQUIA_LISTAS_FORWARDNODE_H
#define JERARQUIA_LISTAS_FORWARDNODE_H
#include "Node.h"

template<class T>
class ForwardNode : public Node<T>{
public:
    ForwardNode<T>* Next;
    template<class R>
    friend class List;

    template<class Y>
    friend class ForwardList;

    template<class U>
    friend class CircularList;
};
#endif //JERARQUIA_LISTAS_FORWARDNODE_H
