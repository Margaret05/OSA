#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;
#define RUN 32

// Функція для вимірювання часу сортування
template<typename SortFunction>
double measure_time(SortFunction sort_function, int arr[], int size) {
    auto start = high_resolution_clock::now();
    sort_function(arr, size);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

// 1. Insertion Sort
void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 2. Bubble Sort
void bubble_sort(int arr[], int size) {
    bool isUnsorted;
    do {
        isUnsorted = false;            // прапорець для перевірки, чи був обмін
        for (int i = 0; i < (size - 1); i++) {
            if (arr[i] > arr[i + 1]) {
                isUnsorted = true;
                for (int i = 0; i < (size - 1); i++) {
                    if (arr[i] > arr[i + 1]) {
                        swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    } while (isUnsorted);
}

// 3. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int size) {
    quick_sort_helper(arr, 0, size - 1);
}

// 4. Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort_helper(int arr[], int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort_helper(arr, left, mid);
    merge_sort_helper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge_sort(int arr[], int size) {
    merge_sort_helper(arr, 0, size - 1);
}

// 5. Count Sort
void count_sort(int arr[], int size) {
    int max_val = *max_element(arr, arr + size);
    int min_val = *min_element(arr, arr + size);
    int range = max_val - min_val + 1;
    int* count = new int[range]();

    // Підрахунок кількості кожного елемента
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min_val]++;
    }

    // Перезаписуємо елементи масиву згідно з підрахунками
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + min_val;
            count[i]--;
        }
    }

    // Очищаємо пам'ять
    delete[] count;
}

// 6. Timsort (використовує стандартне сортування)

void insertion_for_timsort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void timsort(int arr[], int size) {
    // Спочатку сортуємо кожен підмасив за допомогою сортування вставками
    for (int i = 0; i < size; i += RUN) {
        insertion_for_timsort(arr, i, min(i + RUN - 1, size - 1));
    }

    // Тепер зливаємо відсортовані підмасиви
    for (int n = RUN; n < size; n = 2 * n) {
        for (int left = 0; left < size; left += 2 * n) {
            int mid = min(size - 1, left + n - 1);
            int right = min((left + 2 * n - 1), (size - 1));
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Функція для генерації випадкового масиву
void generate_random_array(int arr[], int size, int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < size; ++i)
        arr[i] = dis(gen);
}

// Функція для сортування масиву за спаданням
void bubble_sort_desc(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Якщо поточний елемент менший за наступний, міняємо їх місцями
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}