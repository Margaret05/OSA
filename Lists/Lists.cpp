#include "Header.h"

int main() {
    srand(time(nullptr));

    int arr[SIZE];
    vector<int> vec;
    list<int> lst;
    int choice;

    do {
        cout << "\nThis program shows the speed of ArrayList and LinkedList\n\n";
        cout << "=== Menu ===\n";
        cout << "1. Fill list and vector\n";
        cout << "2. Random access\n";
        cout << "3. Sequential access\n";
        cout << "4. Insert\n";
        cout << "0. Go back to main menu\n";
        cout << "\nYour choice: ";

        while (!(cin >> choice)) { // Перевірка на коректність вводу
            cin.clear(); // Очищення буфера вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігнорування некоректного вводу
            cout << "\nInvalid input. Please enter a valid integer: ";
        }

        switch (choice) {
        case 1:
            cout << endl;

            // 1. Заповнення
            fillContainer(vec);
            fillContainer(lst);
            fillArray(arr);
            isInitialized = true;
            break;
        case 2:
            cout << endl;

            if (!isInitialized) {
                cout << "Please initialize the containers first by choosing option 1.\n";
            }
            else {// 2. Random Access
                RandomAccess(vec, lst);
                testRandomAccess(arr);
            }
            break;
        case 3:
            cout << endl;

            if (!isInitialized) {
                cout << "Please initialize the containers first by choosing option 1.\n";
            }
            else {// 3. Sequential Access
                SequentialAccess(vec, lst);
                testSequentialAccess(arr);
            }
            break;
        case 4:
            cout << endl;

            if (!isInitialized) {
                cout << "Please initialize the containers first by choosing option 1.\n";
            }
            else {
                // 4. Вставка на початок
                InsertAtBeginning(vec, lst);
                int current_size = SIZE;
                insertAtBeginning(arr, current_size);
                cout << endl;

                // 5. Вставка в середину
                InsertAtMiddle(vec, lst);
                insertAtMiddle(arr, current_size);
                cout << endl;

                // 6. Вставка в кінець
                InsertAtEnd(vec, lst);
                insertAtEnd(arr, current_size);
            }
            break;
        case 0:
            cout << "\nGoing back to the main menu...\n\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}