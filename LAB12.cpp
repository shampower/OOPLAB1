
#include <iostream>
#include <windows.h>
#include <string>


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
 * @brief Удаляет элементы массива, начиная с первого отрицательного.
 *
 * Находит первый отрицательный элемент, создает новый массив,
 * копирует в него элементы до найденного отрицательного элемента
 * и освобождает старую память.
 *
 * @param arr Ссылка на указатель динамического массива.
 * @param size Размер исходного массива.
 */
void process(int*& arr, int size);

/**
 * @brief Выводит элементы безопасного массива.
 *
 * @param arr Безопасный массив для вывода.
 */
void printSafe(const SafeArray& arr);

/**
 * @brief Изменяет размер безопасного массива.
 *
 * При уменьшении размера выводит удаляемые элементы.
 * При увеличении новые элементы заполняются нулями.
 *
 * @param arr Безопасный массив, размер которого необходимо изменить.
 * @param newSize Новый размер массива.
 */
void reSizeArray(SafeArray& arr, int newSize);

/**
 * @brief Выделяет память под двумерный динамический массив.
 *
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @return Указатель на созданную двумерную матрицу.
 */
int** allocateMatrix(int rows, int cols);

/**
 * @brief Заполняет матрицу значениями, введенными пользователем.
 *
 * @param matrix Двумерная динамическая матрица.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 */
void fillMatrix(int** matrix, int rows, int cols);

/**
 * @brief Освобождает память, выделенную под двумерную матрицу.
 *
 * Сначала освобождает память каждой строки, затем память массива указателей.
 *
 * @param matrix Двумерная динамическая матрица.
 * @param rows Количество строк матрицы.
 */
void freeMatrix(int** matrix, int rows);

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
);

/**
 * @brief Создает безопасный динамический массив.
 *
 * @param size Размер создаваемого массива.
 * @return Структура SafeArray с выделенной памятью.
 */
SafeArray createArray(int size);

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
int& getElement(SafeArray& arr, int index);

void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}

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

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

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

void printMatrix(int** matrix, int rows, int cols, bool showBorders, std::string title)
{
    std::cout << std::endl;
    std::cout << title << std::endl;

    if (showBorders)
    {
        std::cout << "------------------------" << std::endl;
    }

    for (int i = 0; i < rows; i++)
    {
        if (showBorders)
        {
            std::cout << "| ";
        }

        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";

            if (showBorders)
            {
                std::cout << "| ";
            }
        }

        std::cout << std::endl;

        if (showBorders)
        {
            std::cout << "------------------------" << std::endl;
        }
    }
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
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

    int rows = 3;
    int cols = 4;

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