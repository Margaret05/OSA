#include "Header.h"
#include <limits> // Для numeric_limits
#include <cstdlib> // Для rand()

void Queue_Task()
{
    int n = 0, k, choice;
    Queue* q = nullptr; // Використовуємо покажчик на об'єкт черги

    do {
        cout << "\nMenu:\n";
        cout << "1. Create the queue\n";
        cout << "2. Extract elements from the queue\n";
        cout << "3. Display queue\n";
        cout << "4. Clear queue\n";
        cout << "0. Go back to main menu\n";
        cout << "\nYour choice: ";

        while (!(cin >> choice) || choice < 0) { // Перевірка на коректність вводу
            cin.clear(); // Очищення буфера вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
            cout << "\nInvalid input. Please enter a positive integer: ";
        }

        switch (choice) {
        case 1:
            // Зчитування кількості елементів
            cout << "\nEnter the number of elements to initialize the queue: ";
            while (!(cin >> n) || n <= 0) { // Перевірка на коректність вводу
                cin.clear(); // Очищення буфера вводу
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
                cout << "\nInvalid input. Please enter a positive integer: ";
            }

            // Очищення старої черги, якщо вже була створена
            if (q) {
                delete q;
            }

            q = new Queue(n);

            // Ініціалізація черги випадковими значеннями
            for (int i = 0; i < n; i++) {
                q->insert(rand() % 100);
            }

            cout << "\nQueue created and initialized with random values.\n";
            break;
        case 2:
            if (q) {
                cout << "\nEnter the number of elements to extract from the queue: ";
                cin >> k;
                cout << endl;

                // Перевірка, чи k коректне
                if (k > 0) {
                    q->extractFirstK(k);
                }
                else {
                    cout << "\nInvalid number to extract.\n";
                }
            }
            else {
                cout << "\nQueue has not been created yet. Please select option 1 first.\n";
            }
            break;
        case 3:
            if (q) {
                q->display();
            }
            else {
                cout << "\nQueue has not been created yet. Please select option 1 first.\n";
            }
            break;
        case 4:
            if (q) {
                q->clear();
            }
            else {
                cout << "\nQueue has not been created yet. Please select option 1 first.\n";
            }
            break;
        case 0:
            cout << "\nGoing back to the main menu...\n\n";
            break;
        default:
            cout << "\nError\n\n";
            break;
        }

    } while (choice != 0);

    // Очищення пам'яті
    if (q) {
        delete q;
    }
}
