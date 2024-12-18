#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// завдання 1

// Оголошення структури вузла бінарного дерева
struct TreeNode {
    int val;             // Значення вузла
    TreeNode* left;      // Вказівник на лівого нащадка
    TreeNode* right;     // Вказівник на правого нащадка
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  // Конструктор вузла
};

// Функція для обчислення суми значень у діапазоні [low, high]
int rangeSumBST(TreeNode* root, int low, int high);

// Функція для створення дерева з введених даних
TreeNode* createTree();

