#include "Header.h"

// Функція для обчислення суми значень у діапазоні [low, high]
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return 0;  // Базовий випадок: порожній вузол

    double sum = 0;
    // Перевіряємо поточний вузол
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }
    // Рекурсивно обходимо лівого нащадка, якщо потрібно
    if (root->val > low) {
        sum += rangeSumBST(root->left, low, high);
    }
    // Рекурсивно обходимо правого нащадка, якщо потрібно
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    return sum;
}

// Функція для створення дерева з введених даних
TreeNode* createTree() {
    double value;
    cout << "Enter the value of the tree root (-1 to complete): ";
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Please enter an integer: ";
    }

    if (value == -1) return nullptr;

    TreeNode* root = new TreeNode(value);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        double leftVal, rightVal;
        cout << "\nEnter the left child for " << current->val << " (-1 for empty): ";
        while (!(cin >> leftVal)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter an integer: ";
        }
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter the right child for " << current->val << " (-1 for empty): ";
        while (!(cin >> rightVal)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter an integer: ";
        }
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}