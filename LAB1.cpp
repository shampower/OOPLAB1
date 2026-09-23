#include <iostream>
#include <cstdlib>

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

int main()
{
    return 0;
}