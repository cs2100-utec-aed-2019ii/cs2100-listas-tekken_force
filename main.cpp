#include <iostream>
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
