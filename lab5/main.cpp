#include <iostream>
#include "List.h"

int main() {
    List list;
    list.input("aBC");
    list.print();
    --list;
    list.print();

    List list1('a');
    list1 += 'B';
    std::cout << (list == list1) << std::endl;
    list1 += 'C';
    std::cout << (list == list1) << std::endl;
    return 0;
}
