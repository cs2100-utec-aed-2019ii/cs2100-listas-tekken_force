#include "List.h"
#include "DoubleListNode.h"
#include <ctime>
template<class T>
class DoubleList : public List<T>{
protected:
    DoubleListNode<T>* Tail;
    DoubleListNode<T>* Head;
public:

    DoubleList(DoubleList<T>&);
    DoubleList(T*, int);
    DoubleList(DoubleListNode<T>*);
    DoubleList(int);
    DoubleList();

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
};

template<class T>
DoubleList<T>::DoubleList() : List<T>(){
    DoubleList<T>::Head = nullptr;
    DoubleList<T>::Tail = nullptr;
}

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& copia) : List<T>(copia){
    DoubleList<T>::Head = copia.Head;
    DoubleList<T>::Tail = copia.Tail;
}

template<class T>
DoubleList<T>::DoubleList(T * arr, int size) : List<T>(arr,size) {
   DoubleListNode<T>* temp = nullptr;
   DoubleList<T>::Tail = nullptr;
   DoubleList<T>::Head = nullptr;
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
    if(DoubleList<T>::Head == nullptr && DoubleList<T>::Tail == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
unsigned int DoubleList<T>::size(){

}

template<class T>
void DoubleList<T>::clear(){

}

template<class T>
void DoubleList<T>::erase(Node<T>* a){

}

template<class T>
void DoubleList<T>::insert(Node<T>* a, T b){

}

template<class T>
void DoubleList<T>::drop(T a){

}

template<class T>
List<T>& DoubleList<T>::sort(){

}

template<class T>
List<T>& DoubleList<T>::reverse(){

}

template<class T>
T& DoubleList<T>::operator[](int a){

}
