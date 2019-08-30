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
	return *Head->value;
}

template<typename T>
T& ForwardList<T>::Back(){

}

template<typename T>
void ForwardList<T>::Push_back(const T& element){
	Node<T>** A = this->head;
	if(this->Empty()){
		head = new Node<T>(element);
	}
	else{
		while(*A != nullptr){
			if(*A->next == nullptr){
				A->next = new Node<T>(element);
			}
			*A = *A->next;
		}
	}
}

template<typename T>
void ForwardList<T>::Push_front(const T& element){
	Node<T>* temp = head;
	head = new Node<T>(element);
	*head->next = temp;
}

template<typename T>
Node<T>* ForwardList<T>::Pop_front(){

}

template<typename T>
Node<T>* ForwardList<T>::Pop_back(){

}
//el [] trabaja como iterador en la lista 
template<typename T>
T& ForwardList<T>::operator[](const int&){

}

template<typename T>
bool ForwardList<T>::Empty(){
	if(this->head == nullptr)
		return 1;
	else
		return 0;
}

template<typename T>
unsigned int ForwardList<T>::size(){

}

template<typename T>
void ForwardList<T>::clear(){

}

template<typename T>
ForwardList& ForwardList<T>::sort(){

}

template<typename T>
ForwardList& ForwardList<T>::reverse(){

}

