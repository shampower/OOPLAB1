#include <iostream>
#include <windows.h>

struct SafeArray
{
    int* data;
    int size;
};

void process(int*& arr, int size);
void printSafe(const SafeArray& arr);
SafeArray createArray(int size);
int& getElement(SafeArray& arr, int index);
void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}

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

SafeArray createArray(int size)
{
    SafeArray arr;

    arr.size = size;
    arr.data = new int[size]{};

    return arr;
}

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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Задание 2

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

    SafeArray myArr = createArray(5);

    for (int i = 0; i < myArr.size; i++)
    {
        myArr.data[i] = i * 10;
    }

    getElement(myArr, 2) = 999;

    std::cout << "SafeArray: ";
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}