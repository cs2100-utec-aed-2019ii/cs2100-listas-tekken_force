#include <iostream>
<<<<<<< HEAD
#include "ForwardList.cpp"
#include "Node.cpp"
int main() {
    int a = 2;
    ForwardList<int> A(32);
    A.Push_back(1);

    A.Push_front(12);

    A.Push_front(22);
    A.Push_front(100);
    for(int i = 0; i < A.size(); i++){
        std::cout <<"agregado " << A[i]  <<std::endl;
    }

    std::cout << A << "nullptr"<< std::endl;
    std::cout <<std::endl;

    std::cout << "El último valor de la lista es : " << A.Back() << std::endl;
    std::cout <<std::endl;
    std::cout << "El size de la lista es : " << A.size() << std::endl;
    std::cout <<std::endl;
    int i =2;
    std::cout << "El valor de la posicion "<< i<<" es " << A[i] << std::endl;
    A.Pop_back();
    A.Pop_front();
    std::cout <<std::endl;
    std::cout << " Pop_back y pop_front de lista" << std::endl;

    std::cout << "El tamaño de la lista es : " << A.size() << std::endl;

    std::cout << "la nueva lista es: " << std::endl;

    for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << std::endl;
    }
    A.clear();

    std::cout << "limpiar lista, el nuevo tamaño es: " << std::endl;

    std::cout << A.size() << std::endl;
    return 0;
}
=======
#include "DoubleList.h"
#include "List.h"
#include "CircularList.h"

int main() {
    //int* b = new int[32]{15};
    List<int>* a = new CircularList<int>();
	std::cout<<"crea bien "<<std::endl;
	 a->push_front(21);
	std::cout<< a->Back()<<std::endl;
	std::cout<< a->Front()<<std::endl;
//	 a->push_front(14);
	 a->push_front(10);
	std::cout<< a->Back()<<std::endl;
	std::cout<< a->Front()<<std::endl;
//	 a->push_front(5);
	 a->push_front(9);
	std::cout<< a->Back()<<std::endl;
	std::cout<< a->size()<<std::endl;
//	std::cout<<"pushea bien"<<std::endl;
	//std::cout<<"backea bien"<<std::endl;
    return 0;
}
>>>>>>> feature/CircularList
