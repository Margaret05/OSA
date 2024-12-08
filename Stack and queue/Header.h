#pragma once
#include <iostream>
#include <string>
#include <cctype> // Для функцій isdigit та isalpha
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

// завдання для стеку

// Максимальний розмір стеку
#define MAX_SIZE 100

// Клас для створення власного стеку
class MyStack {
private:
    int topIndex;               // Індекс верхнього елементу
    char stack[MAX_SIZE];       // Масив для зберігання елементів

public:
    // Конструктор
    MyStack();

    // Функція push - додавання елемента до стеку
    bool push(char value);

    // Функція pop - вилучення верхнього елемента
    bool pop(char& value);

    // Функція top - отримання верхнього елемента
    bool top(char& value);

    // Пер перевірка, чи стек порожній
    bool isEmpty();

    // Виведення всього стеку
    void display();
};
// завдання 1
void Stack_Task1();

// завдання 2
void Stack_Task2();

// завдання 3
void OutputArray(int n, int* arr);
// Ця функція повертає відсортований стек
stack<int> sortStack(stack<int> input);

void sortArrayUsingStacks(int arr[], int n);

void Stack_Task3();

// функції для черги
// Клас для реалізації базової черги
class Queue {
private:
    int* arr;
    int capacity;
    int head;
    int rear;

public:
    // Конструктор
    Queue(int n);

    // Деструктор
    ~Queue();

    // Метод для додавання елемента до черги
    void insert(int value);

    // Метод для видалення першого елемента
    int remove();

    // Метод для виведення всіх елементів у черзі
    void display();

    // Метод для очищення всіх елементів черги
    void clear();

    // Метод для витягання перших k елементів
    void extractFirstK(int k);
};

void Queue_Task();


// Максимальний розмір стеку
//#define n 100
//
//struct my_char_stack {
//    int topS = 0; // Кількість елементів у стеку
//    int stack[n]; // Масив для збереження елементів стеку
//
//    // Додати до стеку новий елемент
//    bool push(char x);
//
//    // Вилучити зі стеку верхній елемент
//    int pop(bool& kv);
//
//    // Повернути кількість елементів у стеку
//    int size_stack();
//
//    // Очистити стек
//    void clear_stack();
//
//    // Вивести елементи стеку на екран
//    void stack_screen();
//
//    // Перевірити, чи стек порожній
//    bool isEmpty();
//};
//struct my_number_stack {
//    int topS = 0; // Кількість елементів у стеку
//    int stack[n]; // Масив для збереження елементів стеку
//
//    // Додати до стеку новий елемент
//    bool push(int x);
//
//    // Вилучити зі стеку верхній елемент
//    int pop(bool& kv);
//
//    // Повернути кількість елементів у стеку
//    int size_stack();
//
//    // Очистити стек
//    void clear_stack();
//
//    // Вивести елементи стеку на екран
//    void stack_screen();
//
//    // Перевірити, чи стек порожній
//    bool isEmpty();
//};