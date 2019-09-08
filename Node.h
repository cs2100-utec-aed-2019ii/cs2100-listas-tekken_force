#ifndef JERARQUIA_LISTAS_NODE_H
#define JERARQUIA_LISTAS_NODE_H

template<class T>
class Node{
protected:
    T value;
public:
    Node<T>* Next;
    Node(T v);
    T get_value();
    ~Node();
    template<class R>
    friend class List;
};

template<class T>
Node<T>::Node(T v){
    this->value = v;
    Next = nullptr;
}

template<class T>
T Node<T>::get_value(){
    return this->value;
}

#endif