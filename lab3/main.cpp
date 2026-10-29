#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Vector3D.h"

void printLength(const Vector3D& v) {
    std::cout << "Длина " << v << " = " << v.length() << '\n';
}

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
    std::cout << "===== 4. + - * / (через += -= *= /=) =====\n";
    Vector3D sum = a + b;
    Vector3D diff = a - b;
    Vector3D doubled = a * 2;
    Vector3D halfB = 0.5 * b;
    Vector3D divided = a / 2;
    std::cout << "a + b   = " << sum << '\n';
    std::cout << "a - b   = " << diff << '\n';
    std::cout << "a * 2   = " << doubled << '\n';
    std::cout << "0.5 * b = " << halfB << '\n';
    std::cout << "a / 2   = " << divided << '\n';
    std::cout << "a и b не изменились: a = " << a << ", b = " << b << '\n';
    std::cout << "Скалярное произведение a и b = " << a.dot(b) << '\n';
    try {
        Vector3D bad = a / 0;
        std::cout << bad << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "a / 0 -> ошибка: " << e.what() << '\n';
    }
    std::cout << '\n';
    std::cout << "===== 5. Сравнения (по длине) =====\n";
    Vector3D d(0, 0, 5);
    std::cout << "|a| = " << a.length() << ", |b| = " << b.length()
              << ", |d| = " << d.length() << '\n';
    std::cout << "a <  b     : " << (a < b) << '\n';
    std::cout << "a >  b     : " << (a > b) << '\n';
    std::cout << "b <= a     : " << (b <= a) << '\n';
    std::cout << "a >= aCopy : " << (a >= aCopy) << '\n';
    std::cout << "a == aCopy : " << (a == aCopy) << '\n';
    std::cout << "a != b     : " << (a != b) << '\n';
    std::cout << "a == d     : " << (a == d) << " (сравниваются длины, а не координаты)\n\n";

    std::cout << "===== 6. Преобразования и explicit =====\n";
    double lenA = static_cast<double>(a);
    Vector3D fromNumber = static_cast<Vector3D>(2.0);
    std::cout << "static_cast<double>(a)     = " << lenA << '\n';
    std::cout << "static_cast<Vector3D>(2.0) = " << fromNumber << '\n';
    printLength(Vector3D(7.0));
    std::cout << "Без explicit эти строки скомпилировались бы, а с explicit - ошибка:\n"
                 "  Vector3D w = 5.0;   // число стало бы вектором (5, 5, 5)\n"
                 "  a += 1.0;           // к a прибавился бы (1, 1, 1)\n"
                 "  printLength(3.0);   // в функцию вместо вектора ушло бы число\n"
                 "  double l = a;       // неявно получили бы длину\n"
                 "  if (a > 4.0) {}     // сравнение вектора с числом\n\n";
    // Vector3D w = 5.0;
    // a += 1.0;
    // printLength(3.0);
    // double l = a;
    // if (a > 4.0) {}

    std::cout << "===== 7. const-объект и mutable =====\n";
    const Vector3D fixedVec(2, 3, 6);
    std::cout << "Подсчётов длины у fixedVec: " << fixedVec.getLengthCalls() << '\n';
    double l1 = fixedVec.length();
    double l2 = fixedVec.length();
    bool longer = fixedVec > a;
    std::cout << "Длина " << l1 << " и " << l2 << ", длиннее a: " << longer << '\n';
    std::cout << "Подсчётов длины у fixedVec: " << fixedVec.getLengthCalls()
              << " (объект const, но mutable-поле изменилось)\n\n";
    // fixedVec += a;
    // ++fixedVec;

    std::cout << "===== 8. Счётчик созданных векторов =====\n";
    std::cout << "Создано с запуска программы: " << Vector3D::getCreatedCount()
              << " (считаются и копии, в том числе временные)\n";
    {
        Vector3D temp(1, 0, 0);
        std::cout << "Внутри блока создан temp, всего создано: "
                  << Vector3D::getCreatedCount() << '\n';
    }
    std::cout << "temp уничтожен, а счётчик созданных не уменьшился: "
              << Vector3D::getCreatedCount() << '\n';

    std::cout << "\nКонец main, дальше деструкторы оставшихся векторов:\n";
    return 0;
}