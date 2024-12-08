#include "Header.h"
#include "Stack_and_Queue.h"

int main() {
    
    int choice1, choice2;
    do {
        cout << "Menu:\n";
        cout << "1. Work with stack\n";
        cout << "2. Work with queue\n";
        cout << "0. Exit program\n";
        cout << "\nYour choice: ";
        while (!(cin >> choice1) || choice1 < 0) { // Перевірка на коректність вводу
            cin.clear(); // Очищення буфера вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
            cout << "\nInvalid input. Please enter a positive integer: ";
        }
        switch (choice1) {
        case 1:
            cout << "\nMenu:\n";
            cout << "1. Splitting into stacks with symbols and numbers\n";
            cout << "2. Splitting into stacks with vowels and consonants\n";
            cout << "3. Sort an array using stacks\n";
            cout << "0. Go back to main menu\n";
            cout << "\nYour choice: ";
            while (!(cin >> choice2) || choice2 < 0) { // Перевірка на коректність вводу
                cin.clear(); // Очищення буфера вводу
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
                cout << "\nInvalid input. Please enter a positive integer: ";
            }
            switch (choice2) {
            case 1:
                Stack_Task1();
                break;
            case 2:
                Stack_Task2();
                break;
            case 3:
                Stack_Task3();
                break;
            case 0:
                cout << "\nGoing back to the main menu...\n\n";
                break;
            default:
                cout << "\nError\n\n";
                break;
            }
            break;
        case 2:
            Queue_Task(); 
            break;
        case 0: 
            cout << "\nExiting the program...\n";
            break;
        default:
            cout << "\nError\n\n";
            break;
        }
    } while (choice1 != 0);

    return 0;
}