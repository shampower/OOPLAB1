#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size]{};

    std::cout << "Массив создан. Размер: " << size << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}