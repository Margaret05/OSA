#include "Header.h"

int main()
{
    int sizes[] = {100, 1000, 10000, 100000};  // Розмір масиву 100 мільйонів
    int* arr = new int;
    void (*sort_functions[])(int[], int) = {
            insertion_sort, bubble_sort, quick_sort, 
            merge_sort, count_sort, timsort
    };
    cout << "\nTable for sorting time of an array with a small interval\n\n";

    // Заголовок таблиці
    cout << "Array Size\t|Insertion Sort\t|Bubble Sort\t|Merge Sort\t|Count Sort\t|Timsort\t|Quick Sort\t|\n";

    // Для кожного розміру масиву
    for (int size : sizes) {
        cout << size << "\t\t|";
        // Для кожного алгоритму сортування
        for (auto sort_func : sort_functions) {
            int* arr = new int[size];
            generate_random_array(arr, size, 1, 100);
            double time_taken = measure_time(sort_func, arr, size);
            cout << time_taken << "\t|";
            delete[] arr;
        }
        cout << "\n";
    }

    cout << "\nTable for sorting time of an array with a big interval\n\n";

    // Заголовок таблиці
    cout << "Array Size\t|Insertion Sort\t|Bubble Sort\t|Merge Sort\t|Count Sort\t|Timsort\t|Quick Sort\t|\n";

    // Для кожного розміру масиву
    for (int size : sizes) {
        cout << size << "\t\t|";
        // Для кожного алгоритму сортування
        for (auto sort_func : sort_functions) {
            int* arr = new int[size];
            generate_random_array(arr, size, 1, 10000);
            double time_taken = measure_time(sort_func, arr, size);
            cout << time_taken << "\t|";
            delete[] arr;
        }
        cout << "\n";
    }

    cout << "\nTable for sorting time of an array with a small interval sorted in descending order\n\n";

    // Заголовок таблиці
    cout << "Array Size\t|Insertion Sort\t|Bubble Sort\t|Merge Sort\t|Count Sort\t|Timsort\t|Quick Sort\t|\n";

    // Для кожного розміру масиву
    for (int size : sizes) {
        cout << size << "\t\t|";
        // Для кожного алгоритму сортування
        for (auto sort_func : sort_functions) {
            int* arr = new int[size];
            generate_random_array(arr, size, 1, 100);
            double time_taken = measure_time(sort_func, arr, size);
            cout << time_taken << "\t|";
            delete[] arr;
        }
        cout << "\n";
    }

    cout << "\nTable for sorting time of an array with a big interval sorted in descending order\n\n";

    // Заголовок таблиці
    cout << "Array Size\t|Insertion Sort\t|Bubble Sort\t|Merge Sort\t|Count Sort\t|Timsort\t|Quick Sort\t|\n";

    // Для кожного розміру масиву
    for (int size : sizes) {
        cout << size << "\t\t|";
        // Для кожного алгоритму сортування
        for (auto sort_func : sort_functions) {
            int* arr = new int[size];
            generate_random_array(arr, size, 1, 10000);
            double time_taken = measure_time(sort_func, arr, size);
            cout << time_taken << "\t|";
            delete[] arr;
        }
        cout << "\n";
    }

}