/**
 * @file LAB4.cpp
 * @brief Лабораторная работа №4. Динамическая матрица.
 *
 * Программа создает, заполняет, выводит и освобождает
 * двумерный динамический массив.
 */

#include <iostream>
#include <windows.h>
#include <string>

/**
 * @brief Выделяет память под двумерный динамический массив.
 *
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @return Указатель на созданную двумерную матрицу.
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

/**
 * @brief Заполняет матрицу значениями, введенными пользователем.
 *
 * @param matrix Двумерная динамическая матрица.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Введите оценку [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Выводит матрицу на экран.
 *
 * Может выводить матрицу с рамкой или без нее.
 * Также позволяет задать заголовок.
 *
 * @param matrix Двумерная динамическая матрица.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @param showBorders Показывать ли рамку вокруг матрицы.
 * @param title Заголовок матрицы.
 */
void printMatrix(
    int** matrix,
    int rows,
    int cols,
    bool showBorders = true,
    std::string title = "Matrix"
)
{
    std::cout << std::endl;
    std::cout << title << std:endl;
    if (showBorders)
    {
        std::cout << "********************" << std::endl;
    }
    for (int i = 0; i < rows; i++)
    {
        if (showBorders)
        {
            std::cout << "* "
        }

        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        if (showBorders)
        {
            std::cout << "*" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
    if (showBorders)
    {
        std::cout << "********************" << std::endl;
    }
}

/**
 * @brief Освобождает память, выделенную под двумерную матрицу.
 *
 * Сначала освобождает память каждой строки,
 * затем память массива указателей.
 *
 * @param matrix Двумерная динамическая матрица.
 * @param rows Количество строк матрицы.
 */
void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

/**
 * @brief Точка входа в программу.
 *
 * Выполняет задание №4 с двумерным динамическим массивом.
 *
 * @return Код завершения программы.
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int rows;
    int cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** matrix = allocateMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    std::cout << std::endl << "Вызов 1:" << std::endl;
    printMatrix(matrix, rows, cols);

    std::cout << std::endl << "Вызов 2:" << std::endl;
    printMatrix(matrix, rows, cols, true, "Оценки студентов");

    std::cout << std::endl << "Вызов 3:" << std::endl;
    printMatrix(matrix, rows, cols, false, "Без рамки");

    freeMatrix(matrix, rows);
    matrix = nullptr;

    return 0;
}