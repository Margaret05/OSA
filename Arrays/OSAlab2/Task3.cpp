#include "Header.h"

void Task3()
{
    //encodingLine();

    int m = 4; // Кількість бітів для зсуву
    string inputFilename;       //input.txt
    string encodedFilename = "encoded.txt";
    string decodedFilename = "decoded.txt";

    cout << "Enter filename to read: "; cin >> inputFilename;
    cout << "Enter number of bits to shift: "; cin >> m;
    if (!cin) {
        cout << "Incorrect input. Please enter a number: "; cin >> m;
    }
    // Кодуємо текстовий файл
    encodeFile(inputFilename, encodedFilename, m);

    // Декодуємо текстовий файл
    decodeFile(encodedFilename, decodedFilename, m);

    cout << "Encoding and decoding complete.\n" << endl;
}

//char encoding(char s) {
//    // Отримуємо ASCII код символу
//    int temps = int(s);
//
//    // Масив для збереження бітів
//    int code[8];
//
//    // Розбиваємо символ на біти (від старшого до молодшого)
//    for (int bit = 7, i = 0; bit >= 0; bit--, i++) {
//        code[i] = (temps >> bit) & 1;
//    }
//
//    // Міняємо місцями перші чотири біти з останніми чотирма
//    for (int i = 0; i < 4; i++) {
//        swap(code[i], code[i + 4]);
//    }
//
//    // Перераховуємо біти назад у ціле число
//    int sum = 0;
//    for (int i = 0, koef = 1; i < 8; i++) {
//        sum += code[i] * koef;
//        koef *= 2;  // Додаємо вагу для наступного біта
//    }
//
//    // Повертаємо новий символ
//    return char(sum);
//}
//void encodingLine()
//{
//    const int N = 51;
//    char line[N];
//    char line2[N];
//    char line3[N];
//    cout << "Enter something: ";
//    cin.getline(line, N);
//    // Кодуємо рядок
//    for (int i = 0; line[i] != '\0'; i++) {
//        line2[i] = encoding(line[i]);
//    }
//    cout << "Encoded line: " << line2 << endl;
//    for (int i = 0; line2[i] != '\0'; i++) {
//        line3[i] = encoding(line2[i]);
//    }
//    cout << "Decoded line: " << line3 << endl;
//}

// Функція для кодування символу зсувом вправо на m позицій
char encode(char s, int m) {
    // Отримуємо ASCII код символу
    int temps = int(s);

    // Зсуваємо біти вправо на m позицій
    temps >>= m;

    // Повертаємо новий символ
    return char(temps);
}

// Функція для кодування вмісту текстового файлу
void encodeFile(const string& inputFilename, const string& outputFilename, int m) {
    ifstream infile(inputFilename, ios::in); // Відкриваємо вхідний файл для читання
    if (!infile) {
        cerr << "Could not open file for reading!" << endl;
        return;
    }

    ofstream outfile(outputFilename, ios::out); // Відкриваємо вихідний файл для запису
    if (!outfile) {
        cerr << "Could not open file for writing!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) { // Читаємо кожен рядок з вхідного файлу
        for (char& c : line) { // Для кожного символу в рядку
            c = encode(c, m); // Зсуваємо біти вправо
        }
        outfile << line << endl; // Записуємо зсунутий рядок у вихідний файл
    }
}

// Функція для декодування символу зсувом вліво на m позицій
char decode(char s, int m) {
    // Отримуємо ASCII код символу
    int temps = int(s);

    // Зсуваємо біти вліво на m позицій
    temps <<= m;

    // Повертаємо декодований символ
    return char(temps);
}

// Функція для декодування вмісту текстового файлу
void decodeFile(const string& inputFilename, const string& outputFilename, int m) {
    ifstream infile(inputFilename, ios::in); // Відкриваємо вхідний файл для читання
    if (!infile) {
        cerr << "Could not open file for reading!" << endl;
        return;
    }

    ofstream outfile(outputFilename, ios::out); // Відкриваємо вихідний файл для запису
    if (!outfile) {
        cerr << "Could not open file for writing!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) { // Читаємо кожен рядок з вхідного файлу
        for (char& c : line) { // Для кожного символу в рядку
            c = decode(c, m); // Зсуваємо біти вправо
        }
        outfile << line << endl; // Записуємо зсунутий рядок у вихідний файл
    }
}