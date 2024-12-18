#include "Header.h"
// завдання 2

// Функція для побудови оберненого обходу
void buildPostOrder(string preOrder, string inOrder, string& postOrder) {
    if (preOrder.empty()) return;  // Базовий випадок: порожнє дерево

    // Корінь - перший елемент у прямому обході
    char root = preOrder[0];

    // Знаходимо позицію кореня в центрованому обході
    int rootPos = inOrder.find(root);

    // Ліва та права частини центрованого обходу
    string leftInOrder = inOrder.substr(0, rootPos);
    string rightInOrder = inOrder.substr(rootPos + 1);

    // Ліва та права частини прямого обходу
    string leftPreOrder = preOrder.substr(1, leftInOrder.size());
    string rightPreOrder = preOrder.substr(1 + leftInOrder.size());

    // Вивід для користувача
    cout << "Subtree root: " << root << endl;
    cout << "Left subtree (centered): " << leftInOrder << ", (straight): " << leftPreOrder << endl;
    cout << "Right subtree (centered): " << rightInOrder << ", (straight): " << rightPreOrder << endl << endl;

    // Рекурсивно обробляємо ліве та праве піддерева
    buildPostOrder(leftPreOrder, leftInOrder, postOrder);
    buildPostOrder(rightPreOrder, rightInOrder, postOrder);

    // Додаємо корінь до оберненого обходу
    postOrder += root;
    cout << "Adding the root to the inverse traversal: " << root << endl;
}

// Основна функція
int main() {
    int choice, c, n, low, high, result; // Кількість тестів, кількість вершин
    TreeNode* root;
    
        do {
            cout << "=== Menu ===\n";
            cout << "1. Binary search tree\n";
            cout << "2. Calculate the inverse traversal of a binary tree\n";
            cout << "0. Exit program\n";
            cout << "Your choice: ";
    
            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter an integer: ";
            }
    
            switch (choice) {
            case 1:
                cout << "\nLet's create a binary search tree!\n\n";
                root = createTree();

                cout << "\nEnter the range value [low, high]: ";
                while (!(cin >> low) || !(cin >> high)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input. Please enter an integer: ";
                }
                cout << endl;

                // Обчислення суми вузлів у діапазоні
                result = rangeSumBST(root, low, high);
                cout << "The sum of the node values ​​in the range [" << low << ", " << high << "] is equal to: " << result << endl << endl;
                break;
            case 2:

                cout << "\nThis program calculates the inverse traversal of a binary tree." << endl;
                cout << "\nEnter the number of tests (c): ";
                while (!(cin >> c)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input. Please enter an integer: ";
                }

                while (c--) {
                    string preOrder, inOrder;

                    // Ввід даних
                    cout << "\nEnter the number of vertices in the tree (n): ";
                    while (!(cin >> n)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nInvalid input. Please enter an integer: ";
                    }

                    cout << "\nEnter a direct bypass (for example, ABCDEF): ";
                    cin >> preOrder;

                    cout << "Enter a centered bypass (for example, CBAEDF): ";
                    cin >> inOrder;

                    // Валідація вводу
                    if (preOrder.size() != n || inOrder.size() != n) {
                        cout << "\nError: Number of characters in traversals does not match value n!\n\n";
                        continue;
                    }

                    cout << "\nWe start calculating the inverse traversal...\n" << endl;

                    string postOrder = "";  // Результат оберненого обходу
                    buildPostOrder(preOrder, inOrder, postOrder);

                    // Вивід результату
                    cout << "\nReverse traversal for a given tree: " << postOrder << endl;
                    cout << "----------------------------------------" << endl << endl;
                }
                break;
            case 0:
                cout << "\nExiting program..." << endl << endl;
                break;
            default:
                cout << "\nWrong choice! Try again." << endl << endl;
            }
        } while (choice != 0);

    return 0;
}