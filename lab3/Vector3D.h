/**
 * @file Vector3D.h
 * @brief Объявление класса Vector3D — трёхмерного вектора с перегрузкой операторов.
 */
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

/**
 * @brief Трёхмерный вектор (x, y, z).
 *
 * Поддерживает изменение длины на ±1% (++ / --), сложение и вычитание векторов,
 * умножение и деление на число, сравнение векторов по длине.
 * Ведёт подсчёт всех векторов, созданных с запуска программы.
 */
class Vector3D {
private:
    double x; ///< Координата X
    double y; ///< Координата Y
    double z; ///< Координата Z
    mutable int lengthCalls; ///< Сколько раз у объекта считали длину; mutable — меняется даже у const-объекта

    static int createdCount; ///< Сколько векторов создано с запуска программы (включая копии)

public:
    /// @brief Конструктор по умолчанию: нулевой вектор (0, 0, 0).
    Vector3D();

    /**
     * @brief Создаёт вектор (value, value, value).
     * @param value Значение всех трёх координат.
     * @note explicit запрещает неявное преобразование числа в вектор.
     */
    explicit Vector3D(double value);

    /**
     * @brief Создаёт вектор по трём координатам.
     * @param x Координата X.
     * @param y Координата Y.
     * @param z Координата Z.
     */
    Vector3D(double x, double y, double z);

    /**
     * @brief Копирующий конструктор.
     * @param other Копируемый вектор.
     * @note Копия тоже увеличивает счётчик созданных векторов.
     */
    Vector3D(const Vector3D& other);

    /// @brief Копирующее присваивание (стандартное поведение).
    Vector3D& operator=(const Vector3D& other) = default;

    /// @brief Деструктор: выводит сообщение об уничтожении вектора.
    ~Vector3D();

    /// @brief Префиксный инкремент: увеличивает длину на 1%.
    /// @return Ссылка на изменённый вектор.
    Vector3D& operator++();
    /// @brief Постфиксный инкремент: увеличивает длину на 1%.
    /// @return Копия вектора до изменения.
    Vector3D operator++(int);
    /// @brief Префиксный декремент: уменьшает длину на 1%.
    /// @return Ссылка на изменённый вектор.
    Vector3D& operator--();
    /// @brief Постфиксный декремент: уменьшает длину на 1%.
    /// @return Копия вектора до изменения.
    Vector3D operator--(int);

    /// @brief Прибавляет другой вектор.
    Vector3D& operator+=(const Vector3D& other);
    /// @brief Вычитает другой вектор.
    Vector3D& operator-=(const Vector3D& other);
    /// @brief Умножает вектор на число.
    Vector3D& operator*=(double k);
    /**
     * @brief Делит вектор на число.
     * @throw std::invalid_argument При k == 0 (вектор не изменяется).
     */
    Vector3D& operator/=(double k);

    /// @brief Сумма векторов (реализована через +=).
    friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs);
    /// @brief Разность векторов (реализована через -=).
    friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs);
    /// @brief Вектор, умноженный на число (реализовано через *=).
    friend Vector3D operator*(Vector3D lhs, double k);
    /// @brief Число, умноженное на вектор (реализовано через *=).
    friend Vector3D operator*(double k, Vector3D rhs);
    /// @brief Вектор, делённый на число (реализовано через /=).
    friend Vector3D operator/(Vector3D lhs, double k);

    /// @brief Длина a меньше длины b.
    friend bool operator<(const Vector3D& a, const Vector3D& b);
    /// @brief Длина a больше длины b.
    friend bool operator>(const Vector3D& a, const Vector3D& b);
    /// @brief Длина a не больше длины b.
    friend bool operator<=(const Vector3D& a, const Vector3D& b);
    /// @brief Длина a не меньше длины b.
    friend bool operator>=(const Vector3D& a, const Vector3D& b);
    /// @brief Длины равны (с точностью EPS).
    friend bool operator==(const Vector3D& a, const Vector3D& b);
    /// @brief Длины не равны.
    friend bool operator!=(const Vector3D& a, const Vector3D& b);

    /// @brief Вывод вектора в поток в виде (x, y, z).
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& v);

    /// @brief Явное преобразование в double — длина вектора.
    explicit operator double() const;

    /// @brief Длина вектора. Увеличивает счётчик lengthCalls.
    double length() const;
    /// @brief Скалярное произведение с другим вектором.
    double dot(const Vector3D& other) const;
    /// @brief Координата X.
    double getX() const;
    /// @brief Координата Y.
    double getY() const;
    /// @brief Координата Z.
    double getZ() const;
    /// @brief Сколько раз у объекта считали длину.
    int getLengthCalls() const;
    /// @brief Сколько векторов создано с запуска программы.
    static int getCreatedCount();
};

#endif
