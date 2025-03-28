#include "myfloat.h"
#include <cmath>
#include <iomanip>

MyFloat::MyFloat(double num) {
    whole = static_cast<int>(num);
    frac = static_cast<int>(round((num - whole) * 1000));
    normalize();
}

MyFloat::MyFloat(int w, int f) : whole(w), frac(f) {
    normalize();
}

void MyFloat::normalize() {
    if (frac >= 1000) {
        whole += frac / 1000;
        frac %= 1000;
    } else if (frac < 0) {
        whole -= 1;
        frac += 1000;
    }
}

double MyFloat::toDouble() const {
    return whole + frac / 1000.0;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const MyFloat& num) {
    os << std::fixed << std::setprecision(3) << num.toDouble();
    return os;
}
// ???? printf

MyFloat MyFloat::operator+(const MyFloat& other) const {
    return MyFloat(whole + other.whole, frac + other.frac);
}

MyFloat MyFloat::operator-(const MyFloat& other) const {
    return MyFloat(whole - other.whole, frac - other.frac);
}

MyFloat MyFloat::operator*(const MyFloat& other) const {
    return MyFloat(this->toDouble() * other.toDouble());
}

MyFloat MyFloat::operator/(const MyFloat& other) const {
    if (other.toDouble() == 0) {
        throw std::runtime_error("Деление на ноль!");
    }
    return MyFloat(this->toDouble() / other.toDouble());
}

void MyFloat::print() const {
    printf("%d.%03d ", whole, abs(frac));
}

