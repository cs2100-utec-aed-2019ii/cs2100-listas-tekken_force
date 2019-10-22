<<<<<<< HEAD
#ifndef ALGORITMOS_NODE_H
#define ALGORITMOS_NODE_H
=======
#ifndef JERARQUIA_LISTAS_NODE_H
#define JERARQUIA_LISTAS_NODE_H

>>>>>>> feature/CircularList
template<class T>
class Node{
protected:
    T Value;
public:
    Node();
    Node(T v);
    T get_value();
    template<class R>
    friend class List;

    template<class Y>
    friend class ForwardList;

    template<class U>
    friend class CircularList;
<<<<<<< HEAD

    template<class H>
    friend class DoubleCircularList;
=======
>>>>>>> feature/CircularList
};

template<class T>
Node<T>::Node(){
}

template<class T>
Node<T>::Node(T v){
    this->Value = v;
}

template<class T>
T Node<T>::get_value(){
<<<<<<< HEAD
    return (this->Value);
}
#endif //ALGORITMOS_NODE_H
=======
    return (this->value);
}

#endif
>>>>>>> feature/CircularList
