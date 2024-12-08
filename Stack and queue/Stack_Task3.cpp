#include "Header.h"
#include "Stack_and_Queue.h"

// Ця функція повертає відсортований стек
stack<int> sortStack(stack<int> input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        // беремо елемент
        int tmp = input.top();
        input.pop();

        // поки тимчасовий стек не порожній
        // і верхня частина стека менша за temp
        while (!tmpStack.empty() &&
            tmpStack.top() < tmp)
        {
            // з тимчасового стека до вхідного стеку
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in temporary of stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

void sortArrayUsingStacks(int arr[], int size)
{
    // Записуємо елементи масиву у стек
    stack<int> input;
    for (int i = 0; i < size; i++)
        input.push(arr[i]);

    // Сортування стеку
    stack<int> tmpStack = sortStack(input);

    // Зворотне вилучення значень із стеку до масиву
    for (int i = 0; i < size; i++)
    {
        arr[i] = tmpStack.top();
        tmpStack.pop();
    }
}

void OutputArray(int size, int* arr)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void Stack_Task3()
{
    int size = 17;
    int* arr = new int[size];

    cout << "\nEnter the number of elements in the array: ";
    while (!(cin >> size) || size <= 0) { // Перевірка на коректність вводу
        cin.clear(); // Очищення буфера вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
        cout << "\nInvalid input. Please enter a positive integer: ";
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 29 - 9;
    }
    cout << "\nArray unsorted: ";
    OutputArray(size, arr);
    cout << endl;

    // Сортування
    sortArrayUsingStacks(arr, size);

    // Виведення відсортованого масиву
    cout << "\nSorted array: ";
    OutputArray(size, arr);
    cout << endl << endl;
}