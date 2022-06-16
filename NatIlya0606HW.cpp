//Задание.
//В ранее созданный класс String добавьте перегрузку[], (),
//преобразования типа к int:
//•[] — возвращает элемент по указанному индексу;
//•() — ищет символ в строке, если символ есть возвращает индекс, если нет –1.

#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

// Класс "MyString".
class MyString
{
private: 
    string data; // Данные типа <string>.
    int size; // Длина строки.
public:
    // Конструктор класса.
    MyString(string settingData) : data{ settingData }{ size = data.size(); } 

    // Возвращение длины строки.
    int returnSize() 
    {
        return size;
    }
    
    // Перегрузка операторов.
    char operator[](const int index) // Возвращает элемент по индексу.
    {
        char* line = new char[size];
        data.copy(line, size);
        return line[index - 1];
    }

    int operator()(const char& element) // Возвращает индекс элемента.
    {
        return data.find(element) + 1;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Привет, мир!\n";
    cout << "Строка занесена в класс \"MyString\".\n";
    MyString data("Привет, мир!");
    int size = data.returnSize();
    int choice;
    do {
        cout << "Введите команду(1 - найти и вывести элемент по индексу; 2 - найти элемент и вывести его индекс в строке; 3 - выход из программы): ";
        cin >> choice;
        switch (choice)
        {
        case 1: 
        {
            cout << "Введите индекс: \n";
            int index;
            cin >> index;
            if (index > size || index < 1)
            {
                cout << "Неправильно введён индекс.\n";
            }
            else
            {
                cout << "Элементом по индексу " << index << " является: " << data[index] << ".\n";
            }
            break;
        }
        case 2: 
        {
            cout << "Введите элемент для поиска: ";
            char element;
            cin >> element;
            int elementIndex = data(element);
            if (elementIndex != -1)
                cout << "Индекс элемента \"" << element << "\": " << elementIndex << ".\n";
            else
                cout << "Элемент не найден.\n";
            break;
        }
        case 3: 
        {
            cout << "Выход из программы.\n";
            break;
        }
        default: 
        {
            cout << "Такой команды нет.\n";
        }
        
        }
    } while (choice != 3);

}
