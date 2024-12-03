#include "Header.h"

void Task1()
{
    int size1 = 10, size2 = 9, size3 = 8;
    int* array1 = new int[size1];
    int* array2 = new int[size2];
    int* array3 = new int[size3];

    // Введення коректних розмірів для трьох масивів
    size1 = getValidSize("Enter size (1-10) for first array: ");
    size2 = getValidSize("Enter size (1-10) for second array: ");
    size3 = getValidSize("Enter size (1-10) for third array: ");

    // створення масивів
    CreateArray(size1, array1);
    CreateArray(size2, array2);
    CreateArray(size3, array3);

    cout << "Array 1:\n";
    OutputArray(size1, array1);

    cout << "\nArray 2:\n";
    OutputArray(size2, array2);

    cout << "\nArray 3:\n";
    OutputArray(size3, array3);

    // знаходження і виведення результатів
    // об'єднання
    findUnion(array1, size1, array2, size2, array3, size3);
    // Перетин всіх трьох масивів
    findIntersection(array1, size1, array2, size2, array3, size3);
}

// Функція для вводу коректного розміру масиву в діапазоні від 1 до 10
int getValidSize(const string& prompt) {
    int size;
    while (true) {
        cout << prompt;
        cin >> size;

        // Перевірка на некоректне введення (не число)
        if (!cin) {
            cout << "Incorrect input. Please enter a number between 1 and 10.\n";
            cin.clear(); // Очищаємо стан потоку вводу
            cin.ignore();
        }
        // Перевірка, чи входить число в допустимий діапазон
        else if (size < 1 || size > 10) {
            cout << "Input must be between 1 and 10. Please enter a valid number.\n";
        }
        else {
            return size; // Повертаємо коректне значення
        }
    }
}
// автоматичне генерування значень в діапазоні від -9 до 19 для масиву
void CreateArray(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 29 - 9;
    }
}

// функція для виводу масиву
void OutputArray(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

// Функція для знаходження об'єднання двох масивів
void findUnion(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
    int result[100]; // Масив для збереження об'єднання
    int resultSize = 0;

    // Додаємо елементи з першого масиву
    for (int i = 0; i < size1; ++i) {
        if (find(result, result + resultSize, arr1[i]) == result + resultSize) {
            result[resultSize++] = arr1[i];
        }
    }

    // Додаємо елементи з другого масиву
    for (int i = 0; i < size2; ++i) {
        if (find(result, result + resultSize, arr2[i]) == result + resultSize) {
            result[resultSize++] = arr2[i];
        }
    }

    // Додаємо елементи з третього масиву
    for (int i = 0; i < size3; ++i) {
        if (find(result, result + resultSize, arr3[i]) == result + resultSize) {
            result[resultSize++] = arr3[i];
        }
    }

    // вивід результату
    cout << "\n\nThe union of arrays: ";
    for (int i = 0; i < resultSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Функція для знаходження перетину двох масивів
void findIntersection(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
    int result[100]; // Масив для збереження перетину
    int resultSize = 0;

    // Перевіряємо кожен елемент з першого масиву
    for (int i = 0; i < size1; ++i) {
        if (find(arr2, arr2 + size2, arr1[i]) != arr2 + size2 && find(arr3, arr3 + size3, arr1[i]) != arr3 + size3) {
            // Перевірка на унікальність елемента в масиві результату
            bool isUnique = true;
            for (int j = 0; j < resultSize; ++j) {
                if (result[j] == arr1[i]) {
                    isUnique = false;
                    break;
                }
            }

            // Якщо елемент унікальний, додаємо його в результат
            if (isUnique) {
                result[resultSize++] = arr1[i];
            }
        }
    }

    // вивід результату
    cout << "\nIntersect of arrays: ";
    if (resultSize == 0) {
        cout << "The intersect of all three arrays wasn`t found.";
    }
    else {
        for (int i = 0; i < resultSize; ++i) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}