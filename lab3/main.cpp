#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

#include <stdexcept>
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
    std::cout << "===== 2. ++ и -- (длина ±1%) =====\n";
    Vector3D v(3, 4, 0);
    std::cout << "v = " << v << ", длина " << v.length() << '\n';
    Vector3D r1 = ++v;
    std::cout << "++v вернул " << r1 << " (уже новое), длина v " << v.length() << '\n';
    Vector3D r2 = v++;
    std::cout << "v++ вернул " << r2 << " (старое), а v = " << v << '\n';
    Vector3D r3 = --v;
    std::cout << "--v вернул " << r3 << " (уже новое), длина v " << v.length() << '\n';
    Vector3D r4 = v--;
    std::cout << "v-- вернул " << r4 << " (старое), а v = " << v << "\n\n";
    std::cout << "===== 3. += -= *= /= =====\n";
    Vector3D c(1, 1, 1);
    c += b;
    std::cout << "c += b -> " << c << '\n';
    c -= a;
    std::cout << "c -= a -> " << c << '\n';
    c *= 2;
    std::cout << "c *= 2 -> " << c << '\n';
    c /= 4;
    std::cout << "c /= 4 -> " << c << '\n';
    try {
        c /= 0;
    } catch (const std::invalid_argument& e) {
        std::cout << "c /= 0 -> ошибка: " << e.what() << '\n';
    }
    std::cout << "c не испортился: " << c << "\n\n";

    std::cout << "\nКонец main, дальше деструкторы оставшихся векторов:\n";
    return 0;
}