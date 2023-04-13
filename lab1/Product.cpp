#include "Product.h"

Product::Product(): amount(0), price(0){
    strcpy(name, "default");
    std::cout << "Object " << this << " created." << std::endl;
}
Product::Product(const char * name, const int amount, const float price): amount(amount), price(price) {
    strcpy(this->name, name);
    std::cout << "Object " << this << " created with parameters." << std::endl;
}
Product::Product(const Product & source): amount(source.amount), price(source.price){
    strcpy(this->name, source.name);
    std::cout << "Object " << this << " created with copying." << std::endl;
}
Product::~Product() {
    delete[] name;
    std::cout << "Object " << this << " deleted." << std::endl;
}

void Product::display() {
    std::cout << "Name: " << name << "; Amount: " << amount << "; Price: " << price << ";" << std::endl << std::endl;
}

char *Product::getName() {
    return name;
}

void Product::setName(char *name) {
    Product::name = name;
}

int Product::getAmount() {
    return amount;
}

void Product::setAmount(int amount) {
    Product::amount = amount;
}

float Product::getPrice() {
    return price;
}

void Product::setPrice(float price) {
    Product::price = price;
}
