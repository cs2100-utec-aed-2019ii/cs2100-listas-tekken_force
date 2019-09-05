#include <iostream>
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