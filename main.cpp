#include "ciper_header.h"
#include <iostream>
#include <string>
#include <fstream>

// Определение глобальных переменных
const string ALPHABET_r = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const string ALPHABET_e = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string SYMBOLS = ".,!?()+-=@#$%^&*_:;0123456789 ";
const string FULL_ALPHABET = ALPHABET_r + ALPHABET_e + SYMBOLS;

int main() {
    setlocale(LC_ALL, "Russian");
    string text, key, encryptedText, decryptedText;
    int choice;
    
    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Ввести текст с клавиатуры\n";
        cout << "2. Загрузить текст из файла\n";
        cout << "3. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        if (choice == 3) break;

        if (choice == 1) {
            cout << "Введите текст: ";
            getline(cin, text);
        }
        else if (choice == 2) {
            string filename;
            cout << "Введите имя файла: ";
            getline(cin, filename);
            
            ifstream file(filename);
            if (file.is_open()) {
                getline(file, text);
                file.close();
            }
            else {
                cout << "Ошибка открытия файла!\n";
                continue;
            }
        }

        cout << "\nВыберите метод шифрования:\n";
        cout << "1. Шифр пар\n";
        cout << "2. Шифр ADFGX\n";
        cout << "3. Квадрат Полибия\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите ключ: ";
                getline(cin, key);
                encryptedText = encryptPairs(text, key);
                decryptedText = decryptPairs(encryptedText, key);
                break;
            case 2:
                cout << "Введите ключ: ";
                getline(cin, key);
                encryptedText = encryptADFGX(text, key);
                decryptedText = decryptADFGX(encryptedText, key);
                break;
            case 3:
                encryptedText = encryptPolybius(text);
                decryptedText = decryptPolybius(encryptedText);
                break;
            default:
                cout << "Неверный выбор!\n";
                continue;
        }

        Password();
        cout << "\nЗашифрованный текст: " << encryptedText << endl;
        cout << "Дешифрованный текст: " << decryptedText << endl;

        cout << "\nСохранить результат в файл? (y/n): ";
        char saveChoice;
        cin >> saveChoice;
        if (saveChoice == 'y' || saveChoice == 'Y') {
            ofstream outFile("result.txt");
            outFile << "Исходный текст: " << text << endl;
            outFile << "Зашифрованный текст: " << encryptedText << endl;
            outFile << "Дешифрованный текст: " << decryptedText << endl;
            outFile.close();
            cout << "Результат сохранен в файл 'result.txt'\n";
        }
    }

    return 0;
}