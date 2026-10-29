#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

#include <iostream>
#include <iomanip>
#include "Vector3D.h"

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    std::cout << std::fixed << std::setprecision(3) << std::boolalpha;

    std::cout << "===== 1. Конструкторы =====\n";
    Vector3D zero;
    Vector3D ones(1.0);
    Vector3D a(3, 4, 0);
    Vector3D b(1, 2, 2);
    Vector3D aCopy(a);
    std::cout << "zero  = " << zero << '\n';
    std::cout << "ones  = " << ones << '\n';
    std::cout << "a     = " << a << ", длина " << a.length() << '\n';
    std::cout << "b     = " << b << ", длина " << b.length() << '\n';
    std::cout << "aCopy = " << aCopy << '\n';
    std::cout << "Создано векторов: " << Vector3D::getCreatedCount() << "\n\n";

    std::cout << "\nКонец main, дальше деструкторы оставшихся векторов:\n";
    return 0;
}