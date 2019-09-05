#include "ForwardList.h"
#include "Node.h"

template<typename T>
ForwardList<T>::ForwardList(){
    head = nullptr;
}
template<typename T>
ForwardList<T>::ForwardList(const T& element){
    head = new Node<T>(element);
}
template<typename T>
T& ForwardList<T>::Front(){
    return *head->value;
}
template<typename T>
T& ForwardList<T>::Back(){
    Node<T>** A = &(this->head);
    while(*A){
        if((*A)->Next == nullptr){
            return (*A)->value;
        }
        A = &(*A)->Next;
    }
}
template<typename T>
void ForwardList<T>::Push_back(const T& element){
    if(this->Empty()){
        head = new Node<T>(element);
    }
    else{
        Node<T>** A = &(this->head);
        while(*A){
            if((*A)->Next == nullptr){
                (*A)->Next = new Node<T>(element);
                break;
            }
            A = &(*A)->Next;
        }
    }
}
template<typename T>
void ForwardList<T>::Push_front(const T& element){
    Node<T>* temp = head;
    head = new Node<T>(element);
    head->Next = temp;
}
template<typename T>
T ForwardList<T>::Pop_front(){
    Node<T>* temp = head;
    T copia;
    if(temp->Next == nullptr){
        copia = temp->value;
        delete temp;
        head = nullptr;
        return copia;
    }
    else{
        head = temp->Next;
        copia = temp->value;
        delete temp;
        return copia;
    }
}

template<typename T>
T ForwardList<T>::Pop_back(){
 Node<T>* temp = this->head;
 T copia;
 if(temp->Next == nullptr){
     copia = temp->value;
     delete temp;
     head = nullptr;
     return copia;
 }
 else {
     while (temp) {
         if ((temp->Next)->Next == nullptr) {
             copia = temp->Next->value;
             delete temp->Next;
             temp->Next = nullptr;
             return copia;
         }
         temp = temp->Next;
     }
 }
}
template<typename T>
T& ForwardList<T>::operator[](int v){
    Node<T>** pp = &(this->head);
    while(v){
        pp = &(*pp)->Next;
        v--;
    }
    return (*pp)->value;
}
template<typename T>
bool ForwardList<T>::Empty(){
    if(this->head == nullptr)
        return true;
    else
        return false;
}
template<typename T>
unsigned int ForwardList<T>::size(){
    Node<T>** A = &(this->head);
    unsigned int cont = 0;
    while(*A){
        cont++;
        A = &(*A)->Next;
    }
    return cont;
}
template<typename T>
void ForwardList<T>::clear(){
    while(this->head != nullptr){
        this->Pop_back();
    }
}
template<typename T>
ForwardList<T>& ForwardList<T>::sort(){

}
template<typename T>
ForwardList<T>& ForwardList<T>::reverse() {
}

