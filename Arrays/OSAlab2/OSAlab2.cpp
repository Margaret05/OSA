#include "Header.h"
#include "Arrays.h"

// Знайдіть об’єднання (унікальні значення) та перетин (значення, які є в масивах) трьох одновимірних масивів.
// Поміняти місцями рядки матриці, як показано на рис.  
// Скласти програму, що кодує текстовий файл, шляхом зсуву бітів символу вправо на m позицій. Передбачити можливість декодування.  

int main() {

    srand(time(NULL));
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1.Find the union (unique values) and intersection (values ​​that are in the arrays) of three one-dimensional arrays\n";
        cout << "2.Swap the rows of a matrix\n";
        cout << "3.Encoding a text file by shifting the character bits to the right by m positions\n";
        cout << "0. Exit program\n";
        cout << "Your choice: "; cin >> choice;
        switch (choice) {
        case 1:
            Task1();
        case 2:
            Task2();
        case 3:
            Task3();
        default: cout << "Error\n\n";
        }
    } while (choice != 0);
    return 0;
}