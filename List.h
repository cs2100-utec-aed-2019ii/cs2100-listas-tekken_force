//
// Created by DARIO on 14/09/2019.
//

#ifndef ALGORITMOS_LIST_H
#define ALGORITMOS_LIST_H
#include <iostream>
#include "Node.h"
template<class T>
class List{
public:
    List(List<T>&);
    List(T*,int);
    List(Node<T>*);
    List(int);
    List();
    virtual T& Front() = 0;
    virtual T& Back() = 0;
    virtual void push_back(const T& a) = 0;
    virtual void push_front(const T& a) = 0;
    virtual Node<T>* pop_back() = 0;
    virtual Node<T>* pop_front() = 0;
    virtual bool empty() = 0;
    virtual unsigned int size() = 0;
    virtual void clear() = 0;
    virtual void erase(Node<T>*) = 0;
    virtual void insert(Node<T>*,T) = 0;
    virtual void drop(T) = 0;//elimina los nodos que en la lista tengan los valores iguales al del parametro
    virtual List<T>& sort() = 0;
    virtual List<T>& reverse() = 0;
    virtual T& operator[](int) = 0;
};

template<class T>
List<T>::List() {

}

template<class T>
List<T>::List(T* arr, int size) {

}

template<class T>
List<T>::List(Node<T>* n) {

}

template<class T>
List<T>::List(int f) {

}
#endif //ALGORITMOS_LIST_H
