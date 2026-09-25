/**
 * @file LAB3.cpp
 * @brief Лабораторная работа №3. Безопасный динамический массив.
 *
 * Программа демонстрирует работу со структурой SafeArray,
 * проверку границ массива и изменение его размера.
 */

#include <iostream>
#include <windows.h>

/**
 * @brief Структура для хранения динамического массива.
 *
 * Содержит указатель на массив и его текущий размер.
 */
struct SafeArray
{
    /** @brief Указатель на динамический массив. */
    int* data;

    /** @brief Текущий размер массива. */
    int size;
};

/**
 * @brief Создает безопасный динамический массив.
 *
 * @param size Размер создаваемого массива.
 * @return Структура SafeArray с выделенной памятью.
 */
SafeArray createArray(int size)
{
    SafeArray arr;

    arr.size = size;
    arr.data = new int[size]{};

    return arr;
}

/**
 * @brief Возвращает ссылку на элемент безопасного массива.
 *
 * Проверяет выход индекса за границы массива.
 * При некорректном индексе возвращает ссылку на безопасную переменную.
 *
 * @param arr Безопасный массив.
 * @param index Индекс требуемого элемента.
 * @return Ссылка на элемент массива или безопасную переменную при ошибке.
 */
int& getElement(SafeArray& arr, int index)
{
    static int errorValue = 0;

    if (index < 0 || index >= arr.size)
    {
        std::cout << "Ошибка: индекс выходит за границы массива." << std::endl;
        return errorValue;
    }

    return arr.data[index];
}

/**
 * @brief Выводит элементы безопасного массива.
 *
 * @param arr Безопасный массив для вывода.
 */
void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}

/**
 * @brief Изменяет размер безопасного массива.
 *
 * При уменьшении размера выводит удаляемые элементы.
 * При увеличении новые элементы заполняются нулями.
 *
 * @param arr Безопасный массив, размер которого необходимо изменить.
 * @param newSize Новый размер массива.
 */
void reSizeArray(SafeArray& arr, int newSize)
{
    int* newData = new int[newSize]{};

    int elementsToCopy;

    if (arr.size < newSize)
    {
        elementsToCopy = arr.size;
    }
    else
    {
        elementsToCopy = newSize;
    }

    for (int i = 0; i < elementsToCopy; i++)
    {
        newData[i] = arr.data[i];
    }

    if (newSize < arr.size)
    {
        std::cout << "Удаленные элементы: ";

        for (int i = newSize; i < arr.size; i++)
        {
            std::cout << arr.data[i] << " ";
        }

        std::cout << std::endl;
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
}

/**
 * @brief Точка входа в программу.
 *
 * Выполняет задание №3 с безопасным динамическим массивом.
 *
 * @return Код завершения программы.
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SafeArray myArr = createArray(5);

    for (int i = 0; i < myArr.size; i++)
    {
        myArr.data[i] = i * 10;
    }

    getElement(myArr, 2) = 999;

    std::cout << "SafeArray: ";
    printSafe(myArr);

    std::cout << "Уменьшаем массив до 3 элементов:" << std::endl;
    reSizeArray(myArr, 3);

    std::cout << "После уменьшения: ";
    printSafe(myArr);

    std::cout << "Увеличиваем массив до 5 элементов:" << std::endl;
    reSizeArray(myArr, 5);

    std::cout << "После увеличения: ";
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}