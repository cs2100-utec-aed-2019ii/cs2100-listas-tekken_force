#include <iostream>
#include "DoubleList.h"
#include "List.h"

int main() {
    int* b = new int[32]{15};
    List<int>* a = new DoubleList<int>();
    a->push_front(23);
    std::cout << a->Front() << std::endl;
    return 0;
}