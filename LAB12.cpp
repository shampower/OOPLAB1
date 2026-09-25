/**
 * @file LAB12.cpp
 * @brief Лабораторная работа №2. Работа с динамическим массивом.
 *
 * Программа создает динамический массив, удаляет элементы,
 * начиная с первого отрицательного, и освобождает память.
 */

#include <iostream>
#include <windows.h>

/**
 * @brief Удаляет элементы массива, начиная с первого отрицательного.
 *
 * Находит первый отрицательный элемент, создает новый массив,
 * копирует в него элементы до найденного отрицательного элемента
 * и освобождает старую память.
 *
 * @param arr Ссылка на указатель динамического массива.
 * @param size Размер исходного массива.
 */
void process(int*& arr, int size)
{
    int negativeIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            negativeIndex = i;
            break;
        }
    }

    if (negativeIndex == -1)
    {
        std::cout << "Отрицательных элементов нет." << std::endl;
        return;
    }

    int newSize = negativeIndex;
    int* newArr = new int[newSize];

    for (int i = 0; i < newSize; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;

    std::cout << "Первый отрицательный элемент находится под индексом: "
              << negativeIndex << std::endl;

    std::cout << "Новый массив: ";

    for (int i = 0; i < newSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

/**
 * @brief Точка входа в программу.
 *
 * Выполняет задание №2 с динамическим массивом.
 *
 * @return Код завершения программы.
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;

    std::cout << "Введите размер динамического массива: ";
    std::cin >> size;

    int* arr = new int[size]{};

    std::cout << "Введите элементы массива:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Исходный массив: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    process(arr, size);

    delete[] arr;
    arr = nullptr;

    if (arr == nullptr)
    {
        std::cout << "Память освобождена. Указатель равен nullptr." << std::endl;
    }

    return 0;
}