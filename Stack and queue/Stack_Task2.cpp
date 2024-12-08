#include "Header.h"

void Stack_Task2()
{
    string input; // Рядок, що вводить користувач
    MyStack vowels; // Стек для голосних
    MyStack consonants; // Стек для приголосних

    // Зчитування вводу від користувача
    cout << "\nEnter a string: ";
    cin.ignore(); // Очищення буфера перед викликом getline
    getline(cin, input);

    // Перебір кожного символу в рядку
    for (char ch : input) {
        if (isalpha(ch)) { // Перевірка, чи символ є літерою
            char lower_ch = tolower(ch); // Перетворюємо символ на нижній регістр
            if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u' || lower_ch == 'y') {
                vowels.push(ch); // Якщо символ голосний
            }
            else {
                consonants.push(ch); // Інакше він приголосний
            }
        }
    }

    // Виведення стека голосних
    cout << "\nStack of vowels: ";
    vowels.display();
    cout << endl;

    // Виведення стека приголосних
    cout << "Stack of consonants: ";
    consonants.display();
    cout << endl;
}