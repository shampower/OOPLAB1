#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void fillArray(int (&arr)[10]);
void printArray(const int (&arr)[10]);
void swapElements(int (&arr)[10], int i, int j);
void multiplyByTwo(int (&arr)[10]);

void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
    {
        x = rand() % 100;
    }
}

void printArray(const int (&arr)[10])
{
    for (const auto& x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;
}

void swapElements(int (&arr)[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}

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