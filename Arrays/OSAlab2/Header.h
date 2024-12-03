#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include <algorithm>  // Для std::find
#include <fstream>
#include <string>

using namespace std;

// завлання 1
void Task1();
// Функція для вводу коректного розміру масиву в діапазоні від 1 до 10
int getValidSize(const string& prompt);
// автоматичне генерування значень в діапазоні від -9 до 19 для масиву
void CreateArray(int size, int* array);
// функція для виводу масиву
void OutputArray(int size1, int* array1);
// Функція для знаходження об'єднання масивів
void findUnion(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3);
// Функція для знаходження перетину масивів
void findIntersection(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3);

// завдання 2
void Task2();
// автоматичне генерування значень в діапазоні від -9 до 19 для матриці
void CreateMatrix(const int rows, const int cols, int** Matrix);
// функція для виводу матриці
void OutputMatrix(const int rows, const int cols, int** Matrix);
// Функція для вводу коректного рядка в діапазоні від 1 до введеної кількості рядків
int getValidRow(const string& prompt, int rows);

// завдання 3
void Task3();
//char encoding(char s);
//
//void encodingLine();

// Функція для кодування вмісту текстового файлу
void encodeFile(string& inputFilename, int& m, string& encodedFilename, bool& retFlag);
// Функція для декодування вмісту текстового файлу
void decodeFile(const string& inputFilename, const string& outputFilename, int m);
// Функція для кодування символу зсувом вправо на m позицій
char encode(char s, int m);
// Функція для декодування символу зсувом вліво на m позицій
char decode(char s, int m);