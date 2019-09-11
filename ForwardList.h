#include "List.h"
#include "ForwardNode.h"

template<class T>
class ForwardList : public List<T>{
protected:
    Node<T>* Tail;
public:
    ForwardList(ForwardList<T>&);
    ForwardList(T*);
    ForwardList(Node<T>*);
    ForwardList(int);
    ForwardList();
    ~ForwardList();
};
template<class T>
ForwardList<T>::ForwardList(ForwardList<T>& copia){

}

template<class T>
ForwardList<T>::ForwardList(T* arr){

}

template<class T>
ForwardList<T>::ForwardList(Node<T>* p){

}

template<class T>
ForwardList<T>::ForwardList(int n){

}

template<class T>
T& Front(){
    return ForwardList<T>::head->value;
}

template<class T>
T& Back(){
    return ForwardList<T>::tail->value;
}

template<class T>
void push_back(const T& a){
    if(ForwardList<T>::head == nullptr && ForwardList<T>::tail == nullptr){
        ForwardList<T>::head = new Node<T>(a);
        ForwardList<T>::tail = ForwardList<T>::head;
    }
    else if(ForwardList<T>::head == ForwardList<T>::tail){
        Node<T>* temp = new Node<T>(a);
        ForwardList<T>::tail = temp;
        ForwardList<T>::head->next = ForwardList<T>::tail;
    }
    else{
        Node<T>* temp = new Node<T>(a);
        ForwardList<T>::tail->next = temp;
        ForwardList<T>::tail = temp;
    }
}

template<class T>
void push_front(const T& a){
    if(ForwardList<T>::head == nullptr && ForwardList<T>::tail == nullptr){
        ForwardList<T>::head = new Node<T>(a);
        ForwardList<T>::tail = ForwardList<T>::head;
    }
    else if(ForwardList<T>::head == ForwardList<T>::tail){
        Node<T>* temp = new Node<T>(a);
        ForwardList<T>::tail = temp;
        ForwardList<T>::head->next = ForwardList<T>::tail;
    }
    else{
        Node<T>* temp = new Node<T>(a);
        temp->next = ForwardList<T>::head;
        ForwardList<T>::head = temp;
    }
}

template<class T>
T& pop_back(){

}

template<class T>
T& pop_front(){

}

template<class T>
bool empty(){

}

template<class T>
unsigned int size(){

}

template<class T>
void clear(){

}

template<class T>
void erase(Node<T>*){

}

template<class T>
void insert(Node<T>*,T){

}

template<class T>
void drop(T){//elimina los nodos que en la lista tengan los valores iguales al del parametro

}
template<class T>
void sort(){

}

template<class T>
void reverse(){

}
