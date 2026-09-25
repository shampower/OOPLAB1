/**
 * @file LAB1.cpp
 * @brief Лабораторная работа №1. Работа со статическим массивом.
 *
 * Программа выполняет заполнение, вывод и обработку
 * статического массива из 10 целых чисел.
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

/**
 * @brief Заполняет массив случайными числами.
 *
 * @param arr Массив из 10 элементов, который необходимо заполнить.
 */
void fillArray(int (&arr)[10]);

/**
 * @brief Выводит элементы массива на экран.
 *
 * @param arr Массив из 10 элементов для вывода.
 */
void printArray(const int (&arr)[10]);

/**
 * @brief Меняет местами два элемента массива.
 *
 * @param arr Массив из 10 элементов.
 * @param i Индекс первого элемента.
 * @param j Индекс второго элемента.
 */
void swapElements(int (&arr)[10], int i, int j);

/**
 * @brief Умножает каждый элемент массива на 2.
 *
 * @param arr Массив из 10 элементов.
 */
void multiplyByTwo(int (&arr)[10]);

/**
 * @brief Заполняет массив случайными числами.
 *
 * @param arr Массив из 10 элементов, который необходимо заполнить.
 */
void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
    {
        x = rand() % 100;
    }
}

/**
 * @brief Выводит элементы массива на экран.
 *
 * @param arr Массив из 10 элементов для вывода.
 */
void printArray(const int (&arr)[10])
{
    for (const auto& x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;
}

/**
 * @brief Меняет местами два элемента массива.
 *
 * @param arr Массив из 10 элементов.
 * @param i Индекс первого элемента.
 * @param j Индекс второго элемента.
 */
void swapElements(int (&arr)[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * @brief Умножает каждый элемент массива на 2.
 *
 * @param arr Массив из 10 элементов.
 */
void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}

/**
 * @brief Точка входа в программу.
 *
 * @return Код завершения программы.
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));

    int arr[10];

    fillArray(arr);

    std::cout << "Исходный массив:" << std::endl;
    printArray(arr);

    swapElements(arr, 0, 9);

    std::cout << "swapElements:" << std::endl;
    printArray(arr);

    multiplyByTwo(arr);

    std::cout << "multiplyByTwo" << std::endl;
    printArray(arr);

    return 0;
}