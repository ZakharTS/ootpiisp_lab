// АТД − однонаправленный список с элементами типа char.
// Дополнительно перегрузить следующие операции:
//+= – добавить элемент в начало(char+list);
//-- – удалить элемент из начала(типа –list);
//= = – проверка на равенство.

#include "List.h"

List::List() {
    head = nullptr;
    size = 0;
}

List::List(char input) {
    Node *node = new Node;
    node->value = input;
    node->next = nullptr;
    head = node;
    size = 1;
}

List::~List() {
    if (head == nullptr) return;
    Node *cur;
    Node *tmp = head->next;
    while (cur->next != nullptr) {
        cur = tmp;
        tmp = cur->next;
        delete cur;
    }
    delete head;
}

List& List::operator+=(char value) {
    Node *node = new Node;
    node->value = value;
    node->next = head;
    head = node;
    size++;
    return *this;
}

List &List::operator--() {
    if (head == nullptr) return *this;
    head = head->next;
    size--;
    return *this;
}

bool List::operator==(const List &second) {
    if (head == nullptr && second.head == nullptr) return true;
    if (head->value != head->value) return false;
    if(size != second.size) return false;
    Node *cur1 = head;
    Node *cur2 = second.head;
    while (cur1->next != nullptr && cur2->next != nullptr) {
        cur1 = cur1->next;
        cur2 = cur2->next;
        if (cur1->value != cur2->value) {
            return false;
        }
    }
    return true;
}

void List::print() {
    if (head == nullptr) return;
    Node *cur = head;
    std::cout << head->value;
    while (cur->next != nullptr) {
        cur = cur->next;
        std::cout << ", " << cur->value;
    }
    std::cout << std::endl;
}