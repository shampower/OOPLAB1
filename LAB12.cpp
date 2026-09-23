#include <iostream>
#include <windows.h>


void process(int*& arr, int size);

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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size]{};

    std::cout << "Массив создан. Размер: " << size << std::endl;

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