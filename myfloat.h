#pragma once
//#ifndef MYFLOAT_H
//#define MYFLOAT_H

#include <iostream>

class MyFloat {
private:
    int whole;
    int frac;
    void normalize();

public:

    MyFloat(double num);
    MyFloat(int w, int f);
    double toDouble() const;
    friend std::ostream& operator<<(std::ostream& os, const MyFloat& num);

    MyFloat operator+(const MyFloat& other) const;
    MyFloat operator-(const MyFloat& other) const;
    MyFloat operator*(const MyFloat& other) const;
    MyFloat operator/(const MyFloat& other) const;

    void print() const;
};

//#endif
