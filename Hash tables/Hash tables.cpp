#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_PRODUCTS = 100; // Максимальна кількість продуктів у файлі

class Product {
private:
    string code;       // Код товару
    string name;       // Найменування товару
    int quantity;      // Кількість штук

public:
    // Конструктор
    Product(string c = "", string n = "", int q = 0) : code(c), name(n), quantity(q) {}

    // Метод для читання продукту з файлу
    void loadFromFile(ifstream& fin) {
        fin >> code >> name >> quantity;
    }

    // Метод для виводу даних у консоль
    void showData() const {
        cout << "|" << setw(10) << code
            << setw(15) << name
            << setw(10) << quantity << "|" << endl;
    }

    string getCode() const { return code; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }

    // Сеттер для збільшення кількості
    void addQuantity(int q) { quantity += q; }

    // Оператор для сортування за кодом товару
    bool operator<(const Product& other) const {
        return code < other.code;
    }
};

// Функція для побудови таблиці результатів роботи
void buildTable(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "\nError opening file: " << filename << endl << endl;
        return;
    }

    unordered_map<string, Product> productMap; // Хеш-таблиця для унікальних кодів
    Product productList[MAX_PRODUCTS];          // Масив для зберігання продуктів
    int productCount = 0;                      // Лічильник продуктів

    // Зчитуємо дані з файлу
    while (!fin.eof() && productCount < MAX_PRODUCTS) {
        Product p;
        p.loadFromFile(fin);

        if (p.getCode().empty()) continue; // Пропуск порожніх рядків

        // Додаємо в карту для унікальних кодів
        if (productMap.find(p.getCode()) != productMap.end()) {
            productMap[p.getCode()].addQuantity(p.getQuantity());
        }
        else {
            productMap[p.getCode()] = p;
        }

        // Додаємо в масив для невпорядкованого виводу
        productList[productCount++] = p;
    }
    fin.close();

    // Невпорядкована таблиця
    cout << "\n--- Unordered table ---" << endl;
    cout << "|" << setw(10) << "Code" << setw(15) << "Name" << setw(10) << "Quantity" << "|" << endl;
    cout << string(37, '-') << endl;
    for (int i = 0; i < productCount; i++) {
        productList[i].showData();
    }
    cout << string(37, '-') << endl;

    // Впорядкована таблиця
    cout << "\n--- Ordered table ---" << endl;
    cout << "|" << setw(10) << "Code" << setw(15) << "Name" << setw(10) << "Quantity" << "|" << endl;
    cout << string(37, '-') << endl;

    // Перетворення хеш-таблиці в масив для сортування
    Product sortedProducts[MAX_PRODUCTS];
    int sortedCount = 0;

    for (const auto& entry : productMap) {
        sortedProducts[sortedCount++] = entry.second;
    }

    // Сортування за кодом
    sort(sortedProducts, sortedProducts + sortedCount);

    for (int i = 0; i < sortedCount; i++) {
        sortedProducts[i].showData();
    }
    cout << string(37, '-') << endl;

    // Таблиця з розрахунковим входом (вже розраховано через хеш-таблицю)
    cout << "\n--- Table with calculated input ---" << endl;
    cout << "|" << setw(10) << "Code" << setw(15) << "Name" << setw(10) << "Quantity" << "|" << endl;
    cout << string(37, '-') << endl; 
    for (const auto& entry : productMap) {
        entry.second.showData();
    }
    cout << string(37, '-') << endl;

    cout << endl;
}

// Основна програма
int main() {
    string filename; // = "workshop_data.txt";  // Назва файлу

    while (true) {  // Безкінечний цикл
        cout << "Enter (full) link to file (or type 'exit' to quit): ";
        cin >> filename;

        if (filename == "exit") {  // Перевірка на вихід
            cout << "\nExiting program..." << endl;
            break;  // Вихід із циклу
        }

        // Побудова таблиці
        buildTable(filename);
    }

    return 0;
}
