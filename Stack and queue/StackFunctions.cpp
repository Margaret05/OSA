#include "Header.h"

// Конструктор
MyStack::MyStack() {
    topIndex = -1; // Стек порожній
}

// Функція push - додавання елемента до стеку
bool MyStack::push(char value) {
    if (topIndex >= MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
        return false; // Стек переповнений
    }
    stack[++topIndex] = value;
    return true;
}

// Функція pop - вилучення верхнього елемента
bool MyStack::pop(char& value) {
    if (topIndex < 0) {
        cout << "Stack underflow" << endl;
        return false; // Стек порожній
    }
    value = stack[topIndex--];
    return true;
}

// Функція top - отримання верхнього елемента
bool MyStack::top(char& value) {
    if (topIndex < 0) {
        cout << "Stack is empty" << endl;
        return false;
    }
    value = stack[topIndex];
    return true;
}

// Пер перевірка, чи стек порожній
bool MyStack::isEmpty() {
    return topIndex < 0;
}

// Виведення всього стеку
void MyStack::display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    //cout << "Stack elements: ";
    for (int i = topIndex; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}