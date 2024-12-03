#include "Header.h"

void Task2()
{
    int rows = 5, cols = 5, first_row = 2, second_row = 4;
    rows = getValidSize("Enter size (1-10) for the rows of matrix: ");
    cols = getValidSize("Enter size (1-10) for the collumns of matrix: ");

    // Оголошуємо і ініціалізуємо матрицю
    int** Matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        Matrix[i] = new int[rows];

    // створення матриці
    CreateMatrix(rows, cols, Matrix);
    // Виводимо початкову матрицю
    cout << "Initial matrix:" << endl;
    OutputMatrix(rows, cols, Matrix);

    // ввід коректного рядка в діапазоні від 1 до введеної кількості рядків
    first_row = getValidRow("\n\nEnter the line number (1-10) you want to replace: ", rows);
    second_row = getValidRow("And another: ", rows);
    while (second_row == first_row) {
        second_row = getValidRow("We cannot swap one and the same row. Enter another one again: ", rows);
    }

    // Обмінюємо обрані рядки
    for (int i = 0; i < cols; ++i) {
        // Тимчасово зберігаємо перший введений рядок
        int temp = Matrix[first_row - 1][i];
        Matrix[first_row - 1][i] = Matrix[second_row - 1][i];
        Matrix[second_row - 1][i] = temp;
    }

    // Виводимо матрицю після обміну
    cout << "\nMatrix after swapping " << first_row << " and " << second_row << " rows:" << endl;
    OutputMatrix(rows, cols, Matrix);
    cout << endl;
}

// автоматичне генерування значень в діапазоні від -9 до 19 для матриці
void CreateMatrix(const int rows, const int cols, int** Matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Matrix[i][j] = rand() % 29 - 9;
        }
    }
}

// функція для виводу матриці
void OutputMatrix(const int rows, const int cols, int** Matrix)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для вводу коректного рядка в діапазоні від 1 до введеної кількості рядків
int getValidRow(const string& prompt, int rows) {
    int row;
    while (true) {
        cout << prompt;
        cin >> row;

        // Перевірка на некоректне введення (не число)
        if (!cin) {
            cout << "Incorrect input. Please enter a number between 1 and " << rows << endl;
            cin.clear(); // Очищаємо стан потоку вводу
            cin.ignore();
        }
        // Перевірка, чи входить число в допустимий діапазон
        else if (row < 1 || row > rows) {
            cout << "Input must be between 1 and " << rows << ".Please enter a valid number.\n";
        }
        else {
            return row; // Повертаємо коректне значення
        }
    }
}
