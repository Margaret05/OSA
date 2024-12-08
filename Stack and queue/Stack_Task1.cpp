#include "Header.h"

void Stack_Task1()
{
    string input; // Рядок, що вводить користувач
    MyStack charStack; // Стек для символів
    MyStack numStack;  // Стек для чисел

    // Зчитування рядка від користувача
    cout << "\nEnter a string containing characters and numbers: ";
    cin.ignore(); // Очищення буфера перед викликом getline
    getline(cin, input);

    // Перебір кожного символу в рядку
    for (char ch : input) {
        if (isdigit(ch)) { // Якщо символ є числом
            numStack.push(ch);
        }
        else if (isalpha(ch)) { // Якщо символ є літерою
            charStack.push(ch);
        }
    }

    // Виведення стека символів
    cout << "\nStack of characters: ";
    charStack.display();

    // Виведення стека чисел
    cout << "\nStack of numbers: ";
    numStack.display();

    cout << endl;
}
