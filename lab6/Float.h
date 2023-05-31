//
// Created by admin on 24.05.2023.
//

#ifndef LAB6_FLOAT_H
#define LAB6_FLOAT_H


#include <iostream>

class Float {
public:
    Float(float val) {
        value = val;
    }
    friend std::ostream& operator<<(std::ostream& os, const Float& ft) {
        os << ft.value;
        return os;
    }
    bool operator<(const Float& r) const {
        return this->value < r.value;
    }
    bool operator>(const Float& r) const {
        return this->value > r.value;
    }
    bool operator<=(const Float& r) {
        return this->value <= r.value;
    }
    bool operator>=(const Float& r) {
        return this->value >= r.value;
    }
    bool operator==(const Float& r) {
        return this->value == r.value;
    }
    bool operator!=(const Float& r) {
        return this->value != r.value;
    }
//    Float& operator=(const Float& r) {
//        return const_cast<Float &>(r);
//    }

    float value;

    Float() {
        value = 0;
    }
};


#endif //LAB6_FLOAT_H
