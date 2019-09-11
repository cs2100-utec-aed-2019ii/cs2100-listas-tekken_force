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