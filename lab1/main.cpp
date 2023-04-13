#include <iostream>
#include "Product.h"

int main() {
    Product def;
    def.display();

    def.setName("Bread");
    def.setAmount(4);
    def.setPrice(1.5);
    def.display();

    Product pr2("Milk", 23, 2.2);
    pr2.display();

    Product pr2Clone(pr2);
    pr2Clone.display();

    Product defClone = def;
    defClone.display();

    Product * def_ptr = &def;
    def_ptr->setName("Yogurt");

    void (Product::*pf)();
    pf = &Product::display;
    (def.*pf)();
    return 0;
}
