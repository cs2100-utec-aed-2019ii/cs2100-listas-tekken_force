#include <iostream>
#include "ForwardList.cpp"
#include "Node.cpp"
int main() {
    int a = 2;
    ForwardList<int> A(32);
    A.Push_front(22);
    A.Push_front(12);
    A.Push_front(1);
    A.Push_back(100);
    for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << std::endl;
    }
    std::cout << A << std::endl;
    std::cout << "El último valor de la lista es : " << A.Back() << std::endl;
    std::cout << "El size de la lista es : " << A.size() << std::endl;
    std::cout << A[2] << std::endl;
    A.Pop_back();
    A.Pop_front();
    std::cout << "El tamaño de la lista es : " << A.size() << std::endl;
    for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << std::endl;
    }
    A.clear();
    std::cout << A.size() << std::endl;
    return 0;
}