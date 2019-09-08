#ifndef JERARQUIA_LISTAS_LIST_H
#define JERARQUIA_LISTAS_LIST_H

#include <iostream>
#include "Node.h"
template<class T>
class List{
public:
    List();
    virtual T& Front();
    T& Back() = 0;
    void push_back(const T& a) = 0;
    void push_front(const T& a) = 0;
    T& pop_back() = 0;
    T& pop_front() = 0;
    bool empty() = 0;
    unsigned int size() = 0;
    void clear() = 0;
    void erase(Node<T>*) = 0;
    void insert(Node<T>*,T) = 0;
    void drop(T) = 0;//elimina los nodos que en la lista tengan los valores iguales al del parametro
    void sort() = 0;
    void reverse() = 0;
};

#endif