#include "SaturationFloat.h"
#include <iostream>

void SaturationFloat::check() {
  flag = false;
    if (getWhole() < -1000 || getWhole() > 1000) {
        flag = true;
        setWhole(999);
        setFrac(999);
    }
}

SaturationFloat::SaturationFloat(const MyFloat& mf) : MyFloat(mf) {
    check();//??? flag = false
}

SaturationFloat SaturationFloat::operator+(const SaturationFloat& other) const {
    return SaturationFloat(MyFloat::operator+(other));
}

SaturationFloat SaturationFloat::operator-(const SaturationFloat& other) const {
    return SaturationFloat(MyFloat::operator-(other));
}

SaturationFloat SaturationFloat::operator*(const SaturationFloat& other) const {
    return SaturationFloat(MyFloat::operator*(other));
}

SaturationFloat SaturationFloat::operator/(const SaturationFloat& other) const {
    return SaturationFloat(MyFloat::operator/(other));
}

void SaturationFloat::print() const {
    printf("%d.%03d ", getWhole(), getFrac());//?????
    if (flag) {
        printf(" *");
    }
}
