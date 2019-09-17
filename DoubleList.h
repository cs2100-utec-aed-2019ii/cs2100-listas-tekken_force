#ifndef ALGORITMOS_DOUBLELIST_H
#define ALGORITMOS_DOUBLELIST_H
#include "List.h"
#include "DoubleListNode.h"
#include <ctime>
template<class T>
class DoubleList : public List<T>{
public:
    DoubleListNode<T>* Tail;
    DoubleListNode<T>* Head;

    DoubleList(DoubleList<T>&);
    DoubleList(T*, int);
    DoubleList(DoubleListNode<T>*);
    DoubleList(int);
    DoubleList();

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
    DoubleListNode<T>* get_head();
    DoubleListNode<T>* get_tail();

    //SOBRECARGA DE LOS OPERADORES
    template <class _T>
    friend std::ostream& operator<< (std::ostream& os, const DoubleList<_T>& F){
        DoubleListNode<T>* temp = F.Head;
        while(temp){
            os << temp->get_value() << "->";
            temp = temp->Next;
        }
        return os;
    }
    template <class _Y>
    friend DoubleList<_Y>& operator<<(DoubleList<_Y>& list,const _Y& data) {//push_back
        list.push_back(data);
        return list;
    }

    template <class _Y>
    friend DoubleList<_Y>& operator>>(DoubleList<_Y>& list,const _Y& data) {//pop_back
        list.drop(data);
        return list;
    }
};

template<class T>
void DoubleList<T>::Init_h_t() {
    DoubleList<T>::Head = nullptr;
    DoubleList<T>::Tail = nullptr;
}

template<class T>
DoubleList<T>::DoubleList() : List<T>(){
    DoubleList<T>::Init_h_t();
}

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& copia) : List<T>(copia){
    DoubleList<T>::Head = copia.get_head();
    DoubleList<T>::Tail = copia.get_tail();
}

template<class T>
DoubleList<T>::DoubleList(T * arr, int size) : List<T>(arr,size) {
    DoubleListNode<T>* temp = nullptr;
    DoubleList<T>::Init_h_t();
    for(int i = 0; i < size; i++) {
        if (i == 0) {
            temp = new DoubleListNode<T>(arr[i]);
            DoubleList<T>::Head = temp;
            DoubleList<T>::Tail = temp;
        } else {
            temp->Value = arr[i];
            temp->Prev = DoubleList<T>::Tail;
            DoubleList<T>::Tail = temp;
        }
        temp->Next = new DoubleListNode<T>();
        temp = temp->Next;
    }
}

template<class T>
DoubleList<T>::DoubleList(int n) : List<T>(n) {
    srand(time(NULL));
    DoubleList<T>::Init_h_t();
    for(int i = 0; i < n; i++){
        DoubleList::push_back(rand()%10+1);
    }
}

template<class T>
DoubleList<T>::DoubleList(DoubleListNode<T>* p) : List<T>(p){
    DoubleList<T>::Head = p;
    DoubleList<T>::Tail = p;
}


template<class T>
T& DoubleList<T>::Front(){
    return DoubleList<T>::Head->Value;
}

template<class T>
T& DoubleList<T>::Back(){
    return DoubleList<T>::Tail->Value;
}

template<class T>
void DoubleList<T>::push_back(const T& a){
    DoubleListNode<T> *nuevo = new DoubleListNode<T>(a);
    if(!DoubleList<T>::Head){
        DoubleList<T>::Head = nuevo;
        DoubleList<T>::Tail = nuevo;
    }
    else{
        DoubleList::Tail->Next = nuevo;
        nuevo->Prev = DoubleList::Tail;
        DoubleList::Tail = nuevo;
    }
}

template<class T>
void DoubleList<T>::push_front(const T& a){
    if(DoubleList<T>::Tail == nullptr && DoubleList<T>::Head == nullptr){
        DoubleList<T>::Head = new DoubleListNode<T>(a);
        DoubleList<T>::Tail = DoubleList<T>::Head;
    }
    else{
        DoubleListNode<T>* temp = new DoubleListNode<T>(a);
        temp->Next = DoubleList<T>::Head;
        DoubleList<T>::Head->Prev = temp;
        DoubleList<T>::Head = temp;
    }
}

template<class T>
Node<T>* DoubleList<T>::pop_back(){
    DoubleListNode<T>* temp = DoubleList<T>::Tail;
    DoubleList<T>::Tail = DoubleList<T>::Tail->Prev;
    return temp;
}

template<class T>
Node<T>* DoubleList<T>::pop_front(){
    DoubleListNode<T>* temp = DoubleList<T>::Head;
    DoubleList<T>::Head = DoubleList<T>::Head->Next;
    return temp;
}

template<class T>
bool DoubleList<T>::empty(){
    if(DoubleList<T>::Head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
unsigned int DoubleList<T>::size(){
    unsigned int size = 0;
    DoubleListNode<T>* temp = DoubleList<T>::Head;
    while(temp != nullptr){
        temp = temp->Next;
        size++;
    }
}

template<class T>
void DoubleList<T>::clear(){
    DoubleListNode<T> *temp = DoubleList::Head;
    DoubleListNode<T> *rec = DoubleList::Head;
    while(temp){
        rec = rec->Next;
        delete temp;
        temp = rec;
    }
    DoubleList::Head = nullptr;
}

template<class T>
void DoubleList<T>::erase(Node<T>* a){
    DoubleListNode<T>* temp =DoubleList<T>::Head;
    while(temp != nullptr){
        if(temp == a){
            if(temp->Prev != nullptr && temp->Next != nullptr) {
                temp->Prev->Next = temp->Next;
                temp->Next->Prev = temp->Prev;
                delete temp;
                break;
            }
            else if(temp->Prev == nullptr){
                DoubleList<T>::Head = temp->Next;
                DoubleList<T>::Head->Prev = nullptr;
                delete temp;
                break;
            }
            else if(temp->Next == nullptr){
                DoubleList<T>::Tail = temp->Prev;
                DoubleList<T>::Tail->Next = nullptr;
                delete temp;
                break;
            }
        }
        temp = temp->Next;
    }
}

template<class T>
void DoubleList<T>::insert(Node<T>* a, T b){
    DoubleListNode<T>* temp = DoubleList<T>::Head;
    DoubleListNode<T>* in = new DoubleListNode<T>(a->Value);
    if(b == 0) {//probar con el push_front, debería funcionar
        in->Next = DoubleList<T>::Head;
        DoubleList<T>::Head->Prev = in;
        DoubleList<T>::Head = in;
    }
    else if(b == DoubleList<T>::size()) {//probar con el push_back, debería funcionar
        DoubleList<T>::Head->Next = in;
        in->Prev = DoubleList<T>::Head;
        DoubleList<T>::Head = in;
    }
    else if(b > DoubleList<T>::size()) {
        std::cout << "Fuera de rango." << std::endl;
    }
    else {
        for(int i = 0; i < b; i++){
            temp = temp->Next;
        }
        in->Next = temp;
        in->Prev = temp->Prev;
        temp->Prev->Next = in;
        temp->Prev = in;
    }
}

template<class T>
void DoubleList<T>::drop(T a){
    DoubleListNode<T>* temp = DoubleList<T>::Head;
    DoubleListNode<T>* temp2 = temp;
    while(temp != nullptr){
        if(temp->Value == a){
            temp->Prev->Next = temp->Next;
            temp->Next->Prev = temp->Prev;
        }
        else if(temp->Value == a && temp == DoubleList<T>::Head) {
            DoubleList<T>::Head = temp->Next;
            DoubleList<T>::Head->Prev = nullptr;
        }
        else if(temp->Value == a && temp == DoubleList<T>::Tail) {
            DoubleList<T>::Tail = temp->Prev;
            DoubleList<T>::Tail->Next = nullptr;
        }
        temp2 = temp;
        temp = temp->Next;
        delete temp2;
    }
}

template<class T>
List<T>& DoubleList<T>::sort(){
    T* a = new T[DoubleList<T>::size()];
    DoubleListNode<T>* temp =  DoubleList<T>::Head;
    for(int i = 0; i < DoubleList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    for(int i = 0; i < DoubleList<T>::size()-1; i++) {
        for(int j = 0; j < DoubleList<T>::size()-i-1; j++) {
            if(a[j] > a[j+1]) {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < DoubleList<T>::size(); i++) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
}

template<class T>
List<T>& DoubleList<T>::reverse(){
    T* a = new T[DoubleList<T>::size()];
    DoubleListNode<T>* temp =  DoubleList<T>::Head;
    for(int i = 0; i < DoubleList<T>::size(); i++) {
        a[i] = (*this)[i];
    }
    for(int i = DoubleList<T>::size()-1; i >= 0; i--) {
        temp->Value = a[i];
        temp = temp->Next;
    }
    return *this;
}

template<class T>
T& DoubleList<T>::operator[](int a){
    DoubleListNode<T> *temp = DoubleList::Head;
    while(a>0){
        temp = temp->Next;
        a--;
        if(temp == nullptr){
            throw std::out_of_range ("Fuera de Rango.");
        }
    }
    return temp->Value;
}

template<class T>
DoubleListNode<T>* DoubleList<T>::get_head() {
    return DoubleList<T>::Head;
}

template<class T>
DoubleListNode<T>* DoubleList<T>::get_tail() {
    return DoubleList<T>::Tail;
}
#endif //ALGORITMOS_DOUBLELIST_H
