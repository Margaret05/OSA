#include "Header.h"

// Конструктор
Queue::Queue(int n) {
    capacity = n;
    arr = new int[capacity];
    head = -1; // Порожня черга
    rear = -1;
    srand(time(nullptr)); // Ініціалізація генератора випадкових чисел
}

// Деструктор
Queue::~Queue() {
    delete[] arr;
}

// Метод для додавання елемента до черги
void Queue::insert(int value) {
    if ((rear + 1) % capacity == head) { // Перевірка на переповнення
        cout << "\nQueue is full, cannot insert element.\n";
        return;
    }
    if (rear == -1) { // Перший елемент
        head = rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }
    arr[rear] = value;
}

// Метод для видалення першого елемента
int Queue::remove() {
    if (head == -1) {
        cout << "\nQueue is empty.\n";
        return -1;
    }

    int value = arr[head];
    if (head == rear) { // Останній елемент
       head = rear = -1;
    }
    else {
        head = (head + 1) % capacity;
    }
    return value;
}

// Метод для виведення всіх елементів у черзі
void Queue::display() {
    if (head == -1) {
        cout << "\nQueue is empty.\n";
        return;
    }

    int i = head;
    cout << "\nQueue elements: ";
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break; // Дійшли до кінця черги
        i = (i + 1) % capacity;
    }
    cout << endl;
}

// Метод для очищення всіх елементів черги
void Queue::clear() {
    head = rear = -1; // Скидаємо індекси
    cout << "\nQueue cleared.\n";
}

// Метод для витягання перших k елементів
void Queue::extractFirstK(int k) {
    for (int i = 0; i < k; i++) {
        if (head == -1) {
            cout << "\nNo more elements to extract.\n";
            return;
        }
        cout << remove() << " ";
    }
    cout << endl << endl;
}