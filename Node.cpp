#include "Node.h"
template<typename T>
Node<T>::Node(T data){
	this->value = data;
}

template<typename T>
Node<T>::Node(T data, Node* N){
	this->value = data;
	this->Next = N;
}
