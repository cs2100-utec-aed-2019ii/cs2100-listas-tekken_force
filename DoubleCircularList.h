#ifndef ALGORITMOS_DOUBLECIRCULARLIST_H
#define ALGORITMOS_DOUBLECIRCULARLIST_H
#include "List.h"
#include "DoubleListNode.h"
#include <ctime>

template<class T>
class DoubleCircularList : public List<T>{
public:
    DoubleListNode<T>* Head;

    DoubleCircularList();
    DoubleCircularList(T*,int);
    DoubleCircularList(DoubleListNode<T>*);
    DoubleCircularList(DoubleCircularList<T>&);
    DoubleCircularList(int);

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

    template <class _T>
    friend std::ostream& operator<< (std::ostream& os, const DoubleCircularList<_T>& F){
        DoubleListNode<T>* temp = F.Head;
        while(temp->Next!=F.head){
            os << temp->get_value() << "->";
            temp = temp->Next;
        }
        os << temp->get_value() << "->";
        return os;
    }
    template <class _Y>
    friend DoubleCircularList<_Y>& operator<<(DoubleCircularList<_Y>& list,const _Y& data) {//push_back
        list.push_back(data);
        return list;
    }

    template <class _Y>
    friend DoubleCircularList<_Y>& operator>>(DoubleCircularList<_Y>& list,const _Y& data) {//pop_back
        list.drop(data);
        return list;
    }

    DoubleListNode<T>* get_head();
};

template<class T>
void DoubleCircularList<T>::Init_h_t() {
    DoubleCircularList<T>::Head = nullptr;
}

template<class T>
DoubleCircularList<T>::DoubleCircularList() : List<T>(){
    DoubleCircularList<T>::Init_h_t();
}

template<class T>
DoubleCircularList<T>::DoubleCircularList(DoubleListNode<T>* a) : List<T>(a) {
    DoubleCircularList<T>::Head = a;
}

template<class T>
DoubleCircularList<T>::DoubleCircularList(T* arr, int size) : List<T>(arr,size) {
    DoubleCircularList<T>::Init_h_t();
    for(int i = 0; i < size; i++){
        DoubleCircularList::push_back(arr[i]);
    }
}

template<class T>
DoubleCircularList<T>::DoubleCircularList(DoubleCircularList<T>& copia) : List<T>(copia){
    DoubleCircularList<T>::Head = copia.get_head();
}

template<class T>
DoubleCircularList<T>::DoubleCircularList(int size) : List<T>(size){
    srand(time(NULL));
    T data;
    DoubleCircularList<T>::Init_h_t();
    for(int i = 0; i < size; i++){
        data = rand()%10+1;
        DoubleCircularList::push_back(data);
    }
}

template<class T>
T& DoubleCircularList<T>::Front() {
    return DoubleCircularList::Head;
}

template<class T>
T& DoubleCircularList<T>::Back() {
    return DoubleCircularList::Head;
}

template<class T>
void DoubleCircularList<T>::push_back(const T &a) {
    DoubleListNode<T> *nuevo = new DoubleListNode<T>(a);
    if(!DoubleCircularList<T>::Head){
        DoubleCircularList<T>::Head = nuevo;
        DoubleCircularList<T>::Head->Prev = nuevo;
        DoubleCircularList<T>::Head->Next = nuevo;
    }
    else{
        nuevo->Prev = DoubleCircularList::Head->Prev;
        DoubleCircularList::Head->Prev->Next = nuevo;
        DoubleCircularList::Head->Prev = nuevo;
        nuevo->Next = DoubleCircularList::Head;

    }
}

template<class T>
void DoubleCircularList<T>::push_front(const T &a) {
    DoubleListNode<T> *nuevo = new DoubleListNode<T>(a);
    if(!DoubleCircularList<T>::Head){
        DoubleCircularList<T>::Head = nuevo;
        DoubleCircularList<T>::Head->Prev = nuevo;
        DoubleCircularList<T>::Head->Next = nuevo;
    }
    else{
        nuevo->Next = DoubleCircularList::Head;
        nuevo->Prev = DoubleCircularList::Head->Prev;
        DoubleCircularList::Head->Prev = nuevo;
        nuevo->Prev->Next = nuevo;
        DoubleCircularList::Head = nuevo;
    }
}

template<class T>
Node<T>* DoubleCircularList<T>::pop_back() {
    DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
    DoubleListNode<T>::Head = DoubleListNode<T>::Head->Next;
    DoubleCircularList<T>::temp->Prev->Next = DoubleCircularList<T>::temp->Next->Prev;
    return temp;
}

template<class T>
Node<T>* DoubleCircularList<T>::pop_front() {
    DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
    DoubleListNode<T>::Head = DoubleListNode<T>::Head->Prev;
    DoubleCircularList<T>::temp->Prev->Next = DoubleCircularList<T>::temp->Next->Prev;
    return temp;
}

template<class T>
bool DoubleCircularList<T>::empty() {
    if(DoubleCircularList::Head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
unsigned int DoubleCircularList<T>::size() {
    unsigned int size = 0;
    if(DoubleCircularList<T>::empty()){
        return size;
    }
    else{
        DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
        int cont = 0;
        while(cont < 2){
            if(temp == DoubleCircularList<T>::Head){
                cont++;
                size++;
            }
            temp = temp->Next;
        }
    }
}

template<class T>
void DoubleCircularList<T>::clear(){
    if(DoubleCircularList<T>::Head == nullptr) {
        return;
    }
    else {
        DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
        DoubleListNode<T>* erase = DoubleCircularList<T>::Head;
        while(temp->Next != DoubleCircularList<T>::Head) {
            erase = temp;
            temp = temp->Next;
            delete erase;
        }
        delete temp->Next;
        delete temp;
        DoubleCircularList<T>::Head = nullptr;
    }
}

template<class T>
void DoubleCircularList<T>::erase(Node<T> * a) {
    DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
    if(a == temp) {
        temp->Prev->Next = temp->Next;
        return;
    }
    else if(a == temp && temp->Next == nullptr) {
        delete temp;
        return;
    }
    while(temp->Next != DoubleCircularList<T>::Head) {
        if(temp == a) {
            temp->Prev->Next = temp->Next;
            delete temp;
            break;
        }
        temp = temp->Next;
    }
}

template<class T>
void DoubleCircularList<T>::insert(Node<T> * data, T a) {
    DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
    DoubleListNode<T>* in = new DoubleListNode<T>(data->Value);
    T pos = DoubleCircularList<T>::size() % a;
    if(pos == 0) {//probar con el push_front, debería funcionar
        in->Prev = temp->Prev;
        in->Next = temp;
        temp->Prev->Next = in;
        temp->Prev = in;
        return;
    }
    else if(pos == DoubleCircularList<T>::size()) {//probar con el push_back, debería funcionar
        in->Prev = temp->Prev;
        in->Next = temp;
        temp->Prev->Next = in;
        temp->Prev = in;
        return;
    }
    else if(pos > DoubleCircularList<T>::size()) {
        std::cout << "Fuera de rango." << std::endl;
        return;
    }
    else {
        for(int i = 0; i < pos; i++) {
            temp = temp->Next;
        }
        in->Prev = temp->Prev;
        in->Next = temp;
        temp->Prev->Next = in;
        temp->Prev = in;
        return;
    }
}

template<class T>
void DoubleCircularList<T>::drop(T a) {
    DoubleListNode<T>* temp = DoubleCircularList<T>::Head;
    DoubleListNode<T>* erase = temp;
    while(temp->Next != DoubleCircularList<T>::Head) {
        if(temp->Value == a){
            temp->Prev->Next = temp->Next;
            temp->Next->Prev = temp->Prev;
        }
        erase = temp;
        temp = temp->Next;
        delete erase;
    }
    if(temp->Value == a) {
        temp->Prev->Next = temp->Next;
        temp->Next->Prev = temp->Prev;
    }
    erase = temp;
    temp = temp->Next;
    delete erase;
}

template<class T>
List<T>& DoubleCircularList<T>::sort(){
    T* a = new T[DoubleCircularList<T>::size()];
    DoubleListNode<T>* temp =  DoubleCircularList<T>::Head;
    for(int i = 0; i < DoubleCircularList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    for(int i = 0; i < DoubleCircularList<T>::size()-1; i++) {
        for(int j = 0; j < DoubleCircularList<T>::size()-i-1; j++) {
            if(a[j] > a[j+1]) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < DoubleCircularList<T>::size(); i++) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
}

template<class T>
List<T>& DoubleCircularList<T>::reverse(){
    T* a = new T[DoubleCircularList<T>::size()];
    DoubleListNode<T>* temp =  DoubleCircularList<T>::Head;
    for(int i = 0; i < DoubleCircularList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    for(int i = DoubleCircularList<T>::size()-1; i >= 0; i--) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
}

template<class T>
T& DoubleCircularList<T>::operator[](int a) {
    DoubleListNode<T>* temp = DoubleCircularList::Head;
    while(a>0){
        temp = temp->Next;
        a--;

    }
    return temp->Value;
}

template<class T>
DoubleListNode<T>* DoubleCircularList<T>::get_head() {
    return DoubleCircularList<T>::Head;
}
#endif //ALGORITMOS_DOUBLECIRCULARLIST_H
