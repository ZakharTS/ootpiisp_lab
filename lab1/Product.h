#ifndef LAB1_PRODUCT_H
#define LAB1_PRODUCT_H
#include <string.h>
#include <iostream>


class Product {
public:
    Product(); // конструктор без параметров
    Product(const char *, const int, const float); // конструктор с параметрами
    Product(const Product &); // конструктор копирования
    ~Product(); // деструктор
    char *getName();
    void setName(char *name);
    int getAmount();
    void setAmount(int amount);
    float getPrice();
    void setPrice(float price);
    void display(); // вывод содержимого класса
private:
    char * name = new char[256]; // имя
    int amount; // количество
    float price; // цена
};


#endif