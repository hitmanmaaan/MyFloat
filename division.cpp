#include "myfloat.h"

// Оператор деления
MyFloat MyFloat::operator/(const MyFloat& other) const {
    if (other.toDouble() == 0) {
        throw std::runtime_error("Деление на ноль!");
    }
    return MyFloat(this->toDouble() / other.toDouble());
}
