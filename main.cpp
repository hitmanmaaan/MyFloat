#include "myfloat.h"
#include <iostream>

int main() {
    MyFloat a(3.141);
    MyFloat b(3.252);
    a.print();
    b.print();
    printf("Сложение: ");
    (a+b).print();
    printf("Вычитание: ");
    (a-b).print();
    printf("Умножение: ");
    (a*b).print();
    printf("Деление: ");
    (a/b).print();
    return 0;
}
