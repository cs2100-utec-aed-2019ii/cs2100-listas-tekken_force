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

}

template<typename T>
T& ForwardList<T>::Back(){

}

template<typename T>
void ForwardList<T>::Push_back(const T& element){
	if(head == nullptr){
		head = new Node<T>(element);
	}
	else{
		head->next = new Node<T>(element);
	}
}

template<typename T>
void ForwardList<T>::Push_front(const T& element){

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

template<typename T>
std::ostream& ForwardList<T>::operator<<(const ForwardList& F, std::ostream& os){
	os << "El valor de la cabeza es : " << *(F.head) << "\n";
	return os;
}