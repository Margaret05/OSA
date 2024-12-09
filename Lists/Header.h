#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace std::chrono;

const int SIZE = 100000; // Кількість елементів
const int INSERT_COUNT = 1000; // Кількість елементів для вставки

bool isInitialized = false; // Перевірка, чи були об'єкти заповнені

// Заповнення масиву випадковими значеннями
void fillArray(int arr[]) {
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
    }
    auto end_time = high_resolution_clock::now();
    cout << "Time to fill array: "
        << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()
        << " ms" << endl;
}

// Функція для заповнення контейнера випадковими даними
void fillContainer(vector<int>& vec) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        vec.push_back(rand() % 100000);
    }
    auto end = high_resolution_clock::now();
    cout << "Time to fill vector: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

void fillContainer(list<int>& lst) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        lst.push_back(rand() % 100000);
    }
    auto end = high_resolution_clock::now();
    cout << "Time to fill list: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

// Random Access для масиву
void testRandomAccess(int arr[]) {
    int index = rand() % SIZE;
    auto start_time = high_resolution_clock::now();
    volatile int value = arr[index];
    auto end_time = high_resolution_clock::now();
    cout << "Array Random Access time: "
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count()
        << " ns" << endl;
}

// Random access (тестування швидкості доступу за індексом)
void RandomAccess(vector<int>& vec, list<int>& lst) {
    int index = rand() % SIZE;

    auto start = high_resolution_clock::now();
    volatile int value = vec[index]; // Використовуємо volatile, щоб уникнути оптимізацій
    auto end = high_resolution_clock::now();
    cout << "Vector Random Access time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

    start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, index); // Просуваємо ітератор
    value = *it;
    end = high_resolution_clock::now();
    cout << "List Random Access time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
}

// Sequential Access для масиву
void testSequentialAccess(int arr[]) {
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        volatile int value = arr[i];
    }
    auto end_time = high_resolution_clock::now();
    cout << "Array Sequential Access time: "
        << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()
        << " ms" << endl;
}

// Sequential access
void SequentialAccess(vector<int>& vec, list<int>& lst) {
    auto start = high_resolution_clock::now();
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        volatile int value = *it;
    }
    auto end = high_resolution_clock::now();
    cout << "Vector Sequential Access time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        volatile int value = *it;
    }
    end = high_resolution_clock::now();
    cout << "List Sequential Access time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

// Вставка на початок масиву
void insertAtBeginning(int arr[], int& current_size) {
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        for (int j = current_size; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = rand() % 100000;
        current_size++;
    }
    auto end_time = high_resolution_clock::now();
    cout << "Array Insert at beginning time: "
        << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()
        << " ms" << endl;
}

// Вставка на початок
void InsertAtBeginning(vector<int>& vec, list<int>& lst) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        vec.insert(vec.begin(), rand() % 100000);
    }
    auto end = high_resolution_clock::now();
    cout << "Vector Insert at beginning time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        lst.push_front(rand() % 100000);
    }
    end = high_resolution_clock::now();
    cout << "List Insert at beginning time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

// Вставка в кінець масиву
void insertAtEnd(int arr[], int& current_size) {
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        arr[current_size] = rand() % 100000;
        current_size++;
    }
    auto end_time = high_resolution_clock::now();
    cout << "Array Insert at end time: "
        << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()
        << " ms" << endl;
}

// Вставка в кінець
void InsertAtEnd(vector<int>& vec, list<int>& lst) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        vec.push_back(rand() % 100000);
    }
    auto end = high_resolution_clock::now();
    cout << "Vector Insert at end time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        lst.push_back(rand() % 100000);
    }
    end = high_resolution_clock::now();
    cout << "List Insert at end time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}

// Вставка в середину
void insertAtMiddle(int arr[], int& current_size) {
    int middleIndex = current_size / 2;
    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        for (int j = current_size; j > middleIndex; j--) {
            arr[j] = arr[j - 1];
        }
        arr[middleIndex] = rand() % 100000;
        current_size++;
    }
    auto end_time = high_resolution_clock::now();
    cout << "Array Insert at middle time: "
        << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count()
        << " ms" << endl;
}

void InsertAtMiddle(vector<int>& vec, list<int>& lst) {
    int middleIndex = SIZE / 2;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < INSERT_COUNT; i++) {
        vec.insert(vec.begin() + middleIndex, rand() % 100000);
    }
    auto end = high_resolution_clock::now();
    cout << "Vector Insert at middle time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, middleIndex);
    for (int i = 0; i < INSERT_COUNT; i++) {
        lst.insert(it, rand() % 100000);
    }
    end = high_resolution_clock::now();
    cout << "List Insert at middle time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}
