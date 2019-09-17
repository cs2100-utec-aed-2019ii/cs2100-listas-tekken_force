#ifndef ALGORITMOS_FORWARDLIST_H
#define ALGORITMOS_FORWARDLIST_H
#include "ForwardNode.h"
#include "List.h"
#include <ctime>
#include <vector>
#include <algorithm>

template <class T>
class ForwardList : public List<T>{
public:
    ForwardNode<T>* Head;
    ForwardNode<T>* Tail;
    ForwardList();
    ForwardList(ForwardList<T>&);
    ForwardList(T*, int);
    ForwardList(ForwardNode<T>*);
    ForwardList(int);

    void Init_h_t();
    T& Front() override;
    T& Back() override;
    void push_back(const T& a) override;
    void push_front(const T& a) override;
    Node<T>* pop_back() override;
    Node<T>* pop_front() override;
    bool empty() override;
    unsigned int size() override;
    void clear() override;
    void erase(Node<T>*) override;
    void insert(Node<T>*,T) override;
    void drop(T) override;//elimina los nodos que en la lista tengan los valores iguales al del parametro
    List<T>& sort() override;
    List<T>& reverse() override;
    T& operator[](int) override;
    ForwardNode<T>* get_head();
    ForwardNode<T>* get_tail();
    //SOBRECARGA DE LOS OPERADORES
    template <class _T>
    friend std::ostream& operator<< (std::ostream& os, const ForwardList<_T>& F){
        ForwardNode<T>* temp = F.Head;
        while(temp){
            os << temp->get_value() << "->";
            temp = temp->Next;
        }
        return os;
    }
    template <class _Y>
    friend ForwardList<_Y>& operator<<(ForwardList<_Y>& list,const _Y& data) {//push_back
        list.push_back(data);
        return list;
    }

    template <class _Y>
    friend ForwardList<_Y>& operator>>(ForwardList<_Y>& list,const _Y& data) {//pop_back
        list.drop(data);
        return list;
    }
};

template <class T>
void ForwardList<T>::Init_h_t() {
    ForwardList<T>::Head = nullptr;
    ForwardList<T>::Tail = nullptr;
}

template <class T>
ForwardList<T>::ForwardList() : List<T>() {
    ForwardList<T>::Init_h_t();
}

template <class T>
ForwardList<T>::ForwardList(int f) : List<T>(f) {
    srand(time(NULL));
    T data;
    ForwardList<T>::Init_h_t();
    for(int i = 0; i < f; i++){
        data = rand()%10+1;
        ForwardList<T>::push_back(data);
    }
}

template <class T>
ForwardList<T>::ForwardList(T * a, int size) : List<T>(a,size) {
    ForwardList<T>::Init_h_t();
    for(int i = 0; i < size; i++){
        ForwardList<T>::push_back(a[i]);
    }
}

template <class T>
ForwardList<T>::ForwardList(ForwardList<T> & v) : List<T>(v) {
    ForwardList<T>::Head = v.get_head();
    ForwardList<T>::Tail = v.get_tail();
}

template <class T>
ForwardList<T>::ForwardList(ForwardNode<T> * d) : List<T>(d) {
    ForwardList<T>::Head = d;
    ForwardList<T>::Tail = d;
}

template <class T>
T& ForwardList<T>::Front() {
    return ForwardList<T>::Head->Value;
}

template <class T>
T& ForwardList<T>::Back() {
    return ForwardList<T>::Tail->Value;
}

template <class T>
void ForwardList<T>::push_back(const T &a) {
    ForwardNode<T>* temp = new ForwardNode<T>(a);
    if(ForwardList<T>::empty()) {
        ForwardList<T>::Head = temp;
        ForwardList<T>::Tail = temp;
    }
    else {
        ForwardList<T>::Tail->Next = temp;
        ForwardList<T>::Tail = temp;
    }
}

template <class T>
void ForwardList<T>::push_front(const T &a) {
    ForwardNode<T>* temp = new ForwardNode<T>(a);
    if(ForwardList<T>::empty()) {
        ForwardList<T>::Head = temp;
        ForwardList<T>::Tail = ForwardList<T>::Head;
    }
    else {
        temp->Next = ForwardList<T>::Head;
        ForwardList<T>::Head = temp;
    }
}

template <class T>
Node<T>* ForwardList<T>::pop_back() {
    if(ForwardList<T>::empty()) {
        return NULL;
    }
    else if (ForwardList<T>::Head == ForwardList<T>::Tail) {
        ForwardNode<T>* temp = ForwardList<T>::Head;
        ForwardList<T>::Head = nullptr;
        ForwardList<T>::Tail = nullptr;
        return temp;
    }
    else {
        ForwardNode<T>* temp = ForwardList<T>::Head;
        while(1) { //con while temp->Next->Next != nullptr creo que tmb funciona
            if(temp->Next->Next == nullptr) {
                ForwardList<T>::Tail = temp;
                return temp->Next;
            }
            temp = temp->Next;
        }
    }
}

template <class T>
Node<T>* ForwardList<T>::pop_front() {
    if(ForwardList<T>::empty()) {
        return NULL;
    }
    else if(ForwardList<T>::Head == ForwardList<T>::Tail) {
        ForwardNode<T>* temp = ForwardList<T>::Head;
        ForwardList<T>::Head = nullptr;
        ForwardList<T>::Tail = nullptr;
        return temp;
    }
    else {
        ForwardNode<T>* temp = ForwardList<T>::Head;
        ForwardList<T>::Head = ForwardList<T>::Head->Next;
        return temp;
    }
}

template <class T>
bool ForwardList<T>::empty() {
    if(ForwardList<T>::Head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
unsigned int ForwardList<T>::size() {
    ForwardNode<T>* temp = ForwardList<T>::Head;
    unsigned int size = 0;
    if(ForwardList<T>::empty()) {
        return size;
    }
    else {
        while(temp != nullptr) {
            size++;
            temp = temp->Next;
        }
        return size;
    }
}

template <class T>
void ForwardList<T>::clear() {
    ForwardNode<T>* temp = ForwardList<T>::Head;
    while(!ForwardList<T>::empty()) {
        ForwardList<T>::Head = Head->Next;
        delete temp;
        temp = ForwardList<T>::Head;
    }
}

template <class T>
void ForwardList<T>::erase(Node<T>* v) {
    ForwardNode<T>* temp = ForwardList<T>::Head;
    while(1) {
        if(temp->Next == v) {
            temp->Next = temp->Next->Next;
            delete temp->Next;
            break;
        }
        else if(temp == v) {
            delete temp;
            ForwardList<T>::Head = nullptr;
            ForwardList<T>::Tail = nullptr;
            break;
        }
        temp = temp->Next;
    }
}

template <class T>
void ForwardList<T>::insert(Node<T>* c, T y) {
    ForwardNode<T>* in = new ForwardNode<T>(c->Value);
    ForwardNode<T>* temp = ForwardList<T>::Head;
    if(y == 0) {//probar con el push_front, debería funcionar
        in->Next = ForwardList<T>::Head;
        ForwardList<T>::Head = in;
    }
    else if(y == ForwardList<T>::size()) {//probar con el push_back, debería funcionar
        ForwardList<T>::Tail->Next = in;
        ForwardList<T>::Tail = in;
    }
    else if(y > ForwardList<T>::size()) {
        std::cout << "Fuera de rango." << std::endl;
        return;
    }
    else {
        for(int i = 0; i < y-1; i++) {
            temp = temp->Next;
        }
        in->Next = temp->Next;
        temp->Next = in;
    }

}

template <class T>
void ForwardList<T>::drop(T a) {
    ForwardNode<T>* temp = ForwardList<T>::Head;
    ForwardNode<T>* temp2 = ForwardList<T>::Head;
    while(temp != nullptr) {
        if(temp->Value == a && temp == ForwardList<T>::Head) {
            ForwardList<T>::Head = ForwardList<T>::Head->Next;
            temp2 = temp;
        }
        else if(temp->Next->Value == a && temp->Next == ForwardList<T>::Tail) {
            temp2 = temp->Next;
            ForwardList<T>::Tail = temp;
            delete temp2;
            temp->Next = nullptr;
            break;
        }
        else if(temp->Next->Value == a) {
            temp2 = temp->Next;
            temp->Next = temp->Next->Next;
        }
        temp = temp->Next;
        delete temp2;
    }
}

template <class T>
List<T>& ForwardList<T>::sort() {
    T* a = new T[ForwardList<T>::size()];
    ForwardNode<T>* temp = ForwardList<T>::Head;
    for(int i = 0; i < ForwardList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    for(int i = 0; i < (ForwardList<T>::size())-1; i++) {
        for(int j = 0; j < ForwardList<T>::size()-i-1; j++) {
            if(a[j] > a[j+1]) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < ForwardList<T>::size(); i++) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
}

template <class T>
List<T>& ForwardList<T>::reverse() {
    T* a = new T[ForwardList<T>::size()];
    for(int i = 0; i < ForwardList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    ForwardNode<T>* temp = ForwardList<T>::Head;
    for(int i = ForwardList<T>::size()-1; i >= 0; i--) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
};

template <class T>
T& ForwardList<T>::operator[](int a) {
    ForwardNode<T>* temp = ForwardList<T>::Head;
    while(a > 0) {
        temp = temp->Next;
        a--;
        if(temp == nullptr){
            throw std::out_of_range ("Fuera de Rango.");
        }
    }
    return temp->Value;
}

template<class T>
ForwardNode<T>* ForwardList<T>::get_tail() {
    return ForwardList<T>::Tail;
}

template<class T>
ForwardNode<T>* ForwardList<T>::get_head() {
    return ForwardList<T>::Head;
}


#endif //ALGORITMOS_FORWARDLIST_H
