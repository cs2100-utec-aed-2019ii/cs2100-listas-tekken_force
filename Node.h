#ifndef ALGORITMOS_NODE_H
#define ALGORITMOS_NODE_H
template<class T>
class Node{
	protected:
		    T Value;
	public:
			Node();
			Node(T v);
			T get_value();
			template<class R>
				friend class List;
			template<class Y>
				friend class ForwardList;
		    template<class U>
				friend class CircularList;
			template<class H>
				friend class DoubleCircularList;
};

template<class T>
Node<T>::Node(){
}

template<class T>
Node<T>::Node(T v){
	    this->Value = v;
}

template<class T>
T Node<T>::get_value(){
	    return (this->Value);
}
#endif //ALGORITMOS_NODE_H
