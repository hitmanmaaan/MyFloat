#include "myfloat.h"
#include <cmath>
#include <iomanip>

// Конструктор из double
MyFloat::MyFloat(double num) {
    whole = static_cast<int>(num);
    frac = static_cast<int>(round((num - whole) * 1000));
    normalize();
}

// Конструктор из целой и дробной части
MyFloat::MyFloat(int w, int f) : whole(w), frac(f) {
    normalize();
}

// Приведение числа к корректному виду
void MyFloat::normalize() {
    if (frac >= 1000) {
        whole += frac / 1000;
        frac %= 1000;
    } else if (frac < 0) {
        whole -= 1;
        frac += 1000;
    }
}

// Преобразование в double
double MyFloat::toDouble() const {
    return whole + frac / 1000.0;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const MyFloat& num) {
    os << std::fixed << std::setprecision(3) << num.toDouble();
    return os;
}

// Операторы сложения, вычитания и умножения
MyFloat MyFloat::operator+(const MyFloat& other) const {
    return MyFloat(whole + other.whole, frac + other.frac);
}

MyFloat MyFloat::operator-(const MyFloat& other) const {
    return MyFloat(whole - other.whole, frac - other.frac);
}

MyFloat MyFloat::operator*(const MyFloat& other) const {
    return MyFloat(this->toDouble() * other.toDouble());
}
