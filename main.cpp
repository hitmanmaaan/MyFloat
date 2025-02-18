#include "myfloat.h"
#include <iostream>

int main() {
    MyFloat a(3.141);
    MyFloat b(1.234);

    std::cout << "Сложение: " << (a + b) << std::endl;
    std::cout << "Вычитание: " << (a - b) << std::endl;
    std::cout << "Умножение: " << (a * b) << std::endl;

    try {
        std::cout << "Деление: " << (a / b) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
