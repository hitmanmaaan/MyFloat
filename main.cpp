#include "myfloat.h"
#include <iostream>
#include "vector.h"
#include "SaturationFloat.h"

int main() {
    MyFloat a(3.141);
    MyFloat b(3.252);
    a.print();
    b.print();
    printf("\nСложение: ");
    (a+b).print();
    printf("\nВычитание: ");
    (a-b).print();
    printf("\nУмножение: ");
    (a*b).print();
    printf("\nДеление: ");
    (a/b).print();

    printf("\n");
    SaturationFloat s(9999.333);
    SaturationFloat g(2345.444);
    s.print();
    g.print();
    printf("\nСложение: ");
    (s+g).print();
    printf("\nВычитание: ");
    (s-g).print();
    printf("\nУмножение: ");
    (s*g).print();
    printf("\nДеление: ");
    (s/g).print();


    Vector<MyFloat> vecFloat(3);
    vecFloat.set(0, MyFloat(1, 500));
    vecFloat.set(1, MyFloat(2, 250));
    vecFloat.set(2, MyFloat(3, 750));
    vecFloat.print();

    Vector<Vector<MyFloat>> vecOfVec(3);
    vecOfVec.set(0, vecFloat);
    vecOfVec.set(1, vecFloat);
    vecOfVec.set(2, vecFloat);
    vecOfVec.print();

    Vector<Vector<Vector<MyFloat>>> vecOfVec2(3);
    vecOfVec2.set(0, vecOfVec);
    vecOfVec2.set(1, vecOfVec);
    vecOfVec2.set(2, vecOfVec);
    vecOfVec2.print();
}
