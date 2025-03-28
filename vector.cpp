// #include "vector.h"
// #include <cstdio>
//
// Vector::Vector(int s) : size(s) {
//     data = new MyFloat[size];
// }
//
// Vector::Vector(const Vector& other) : size(other.size) {
//     data = new MyFloat[size];
//     for (int i = 0; i < size; ++i) {
//         data[i] = other.data[i];
//     }
// }
//
// Vector Vector::operator=(const Vector& other) {
//     if (this == &other) {
//         return *this;
//     }
//
//     if (size != other.size) {
//         delete[] data;
//         size = other.size;
//         data = new MyFloat[size];
//     }
//     for (int i = 0; i < size; ++i) {
//         data[i] = other.data[i];
//     }
//
//     return *this;
// }
//
// Vector::~Vector() {
//     delete[] data;
// }
//
// Vector Vector::operator+(const Vector& other) const {
//     Vector result(size);
//     for (int i = 0; i < size; ++i) {
//         result.data[i] = data[i] + other.data[i];
//     }
//     return result;
// }
//
// Vector Vector::operator-(const Vector& other) const {
//     Vector result(size);
//     for (int i = 0; i < size; ++i) {
//         result.data[i] = data[i] - other.data[i];
//     }
//     return result;
// }
//
// void Vector::set(int index, const MyFloat& value) {
//     if (index < 0 || index >= size) {
//         printf("Ошибка: индекс %d вне диапазона!\n", index);
//         return;
//     }
//     data[index] = value;
// }
//
// void Vector::print() const {
//     printf("[ ");
//     for (int i = 0; i < size; ++i) {
//         data[i].print();
//         if (i < size - 1) printf(", ");
//     }
//     printf(" ]\n");
// }
