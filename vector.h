#ifndef VECTOR_H
#define VECTOR_H

#include <cstdio>
#include <type_traits>
#include "myfloat.h"

template <typename T>
class Vector {
private:
    T* data;
    int size;
public:
    Vector(int s = 0);  // Конструктор по умолчанию
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    void set(int index, const T& value);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    void print() const;

    int getSize() const { return size; }  // Метод для получения размера
};

// ---------------- Конструктор ----------------
template <typename T>
Vector<T>::Vector(int s) : size(s), data(nullptr) {
    if (size > 0) {
        data = static_cast<T*>(operator new[](size * sizeof(T)));

        for (int i = 0; i < size; ++i) {
            new (data + i) T();
        }
    }
}

// --------------- Конструктор копирования ---------------
template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), data(nullptr) {
    if (size > 0) {
        data = static_cast<T*>(operator new[](size * sizeof(T)));
        for (int i = 0; i < size; ++i) {
            new (data + i) T(other.data[i]);
        }
    }
}

// --------------- Оператор присваивания ---------------
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) return *this;

    if (size != other.size) {
        for (int i = 0; i < size; ++i) {
            data[i].~T();  // Вызываем деструкторы
        }
        operator delete[](data);

        size = other.size;
        data = static_cast<T*>(operator new[](size * sizeof(T)));
        for (int i = 0; i < size; ++i) {
            new (data + i) T(other.data[i]);
        }
    } else {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// ---------------- Деструктор ----------------
template <typename T>
Vector<T>::~Vector() {
    if (data) {
        for (int i = 0; i < size; ++i) {
            data[i].~T();
        }
        operator delete[](data);
    }
}

// ---------------- Метод set ----------------
template <typename T>
void Vector<T>::set(int index, const T& value) {
    if (index < 0 || index >= size) {
        printf("Ошибка: индекс %d вне диапазона!\n", index);
        return;
    }
    data[index] = value;
}

// --------------- Оператор сложения ---------------
template <typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// --------------- Оператор вычитания ---------------
template <typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// ---------- Универсальный print() ----------
template <typename T>
void Vector<T>::print() const {
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        if constexpr (std::is_class<T>::value) {
            data[i].print();  // Если T — класс, вызываем его print()
        } else {
            printf("%d", data[i]);  // Если T — число, печатаем напрямую
        }
        if (i < size - 1) printf(", ");
    }
    printf(" ]\n");
}

#endif
