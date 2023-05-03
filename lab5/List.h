#ifndef LAB5_LIST_H
#define LAB5_LIST_H
#include <iostream>

struct Node {
    char value;
    Node *next;
};

class List {
private:
    Node *head;
    int size;
public:
    List();
    List(char);
    ~List();
    List& operator+=(char);
    List& operator--();
    bool operator==(const List &second);
    void input(std::string);
    void print();
};



#endif //LAB5_LIST_H
