#pragma once
//#ifndef MYFLOAT_H
//#define MYFLOAT_H

#include <iostream>

class MyFloat {
protected:
    int whole;
    int frac;
    void normalize();

public:
    MyFloat() : whole(0), frac(0) {}
    MyFloat(double num);
    MyFloat(int w, int f);
    double toDouble() const;
    friend std::ostream& operator<<(std::ostream& os, const MyFloat& num);

    MyFloat operator+(const MyFloat& other) const;
    MyFloat operator-(const MyFloat& other) const;
    MyFloat operator*(const MyFloat& other) const;
    MyFloat operator/(const MyFloat& other) const;

    void print() const;

    int getWhole() const { return whole; }
    int getFrac() const { return frac; }
    void setWhole(int w) { whole = w; }
    void setFrac(int f) { frac = f; }


};

//#endif