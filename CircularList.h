#ifndef JERARQUIA_LISTAS_CIRCULARLIST_H
#define JERARQUIA_LISTAS_CIRCULARLIST_H

#include "List.h"
#include "ForwardNode.h"
#include <ctime>
template <class T>
class CircularList : public List<T>{
protected:
    ForwardNode<T> *head;
public:
    CircularList(List<T>&);
    CircularList(T*, int);
    CircularList(ForwardNode<T> *);
    CircularList(int);
    CircularList();
    ~CircularList();

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
CircularList<T>::CircularList() : List<T>(){
    CircularList<T>::head = nullptr;
} 
template<class T>
CircularList<T>::CircularList(List<T>& copy) : List<T>(copy){
    CircularList<T>::head = copy.head;
} 
template<class T>
CircularList<T>::CircularList(int n) : List<T>(n){
    srand(time(NULL));
    for (int i=0;i<n;i++){
      CircularList::push_back( rand()%10 +1 );
	
	}

} 

template<class T>
CircularList<T>::CircularList(T* arr, int size) : List<T>(arr,size){

} 
template<class T>
CircularList<T>::CircularList(ForwardNode<T>* node) : List<T>(node){
    CircularList<T>::head = node;
	node.next = head;	
} 


template<class T>
T& CircularList<T>::Front() {
    return head->Value;
}

template<class T>
T& CircularList<T>::Back() {
	
	ForwardNode<T> **pp = &(head);
	while(*pp != head) {
		pp = &(*pp)->next;
	}
	return (*pp)->Value ;
}

template<class T>
void CircularList<T>::push_back(const T& a){
	ForwardNode<T> **head1 = &(head);
	ForwardNode<T> **pp = head1;
	while(*pp != head ) {
		pp=&(*pp)->next;	
	}
	ForwardNode<T> *node = new ForwardNode<T>(a);
	node->next = *pp;
	*pp = node;
	
}

template<class T>
void CircularList<T>::push_front(const T& a){
    ForwardNode<T>**pp = &head ;

	while(*pp != head ) {
		pp=&(*pp)->next;	
	}
   	ForwardNode<T> * node = new ForwardNode<T>(a);
	*pp = node;
	node->next = head;
	head = node; 
}

template<class T>
Node<T>* CircularList<T>::pop_back(){}

template<class T>
Node<T>* CircularList<T>::pop_front(){}

template<class T>
bool CircularList<T>::empty(){}

template<class T>
unsigned int CircularList<T>::size(){
	if (head ==nullptr) return 0;
	ForwardNode<T> ** pp = &head;
	int cant = 1;
	while (*pp !=head){
		pp = &(*pp)->next;
		cant++;
	}
	return cant;
}

template<class T>
void CircularList<T>::clear() {}

template<class T>
void CircularList<T>::erase(Node<T>*){}

template<class T>
void CircularList<T>::insert(Node<T>*,T){}

template<class T>
void CircularList<T>::drop(T) {}

template<class T>
List<T>& CircularList<T>::sort(){}

template<class T>
List<T>& CircularList<T>::reverse(){}


template<class T>
T& CircularList<T>::operator[](int){} 
#endif
