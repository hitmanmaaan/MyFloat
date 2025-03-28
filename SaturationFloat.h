#pragma once
#include "myfloat.h"

class SaturationFloat : public MyFloat {
    //using MyFloat::MyFloat; //????
    bool flag;//???
    void check();

public:
    SaturationFloat(const MyFloat& mf);

    SaturationFloat operator+(const SaturationFloat& other) const;
    SaturationFloat operator-(const SaturationFloat& other) const;
    SaturationFloat operator*(const SaturationFloat& other) const;
    SaturationFloat operator/(const SaturationFloat& other) const;

    void print() const;
};
