#include "ciper_header.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

unsigned int Hash(const string& password) {
    unsigned int hash = 0;
    for (char c : password) {
        hash = hash * 31 + c;
    }
    return hash;
}

void Password() {
    const string DEFAULT_PASSWORD = "0000";
    string password;
    unsigned int correctHash = Hash(DEFAULT_PASSWORD);
    unsigned int attempts = 0;
    const unsigned int MAX_ATTEMPTS = 3;

    do {
        cout << "Введите пароль (осталось попыток: " << MAX_ATTEMPTS - attempts << "): ";
        cin >> password;
        
        if (Hash(password) != correctHash) {
            cout << "Неверный пароль!" << endl;
            attempts++;
            
            if (attempts >= MAX_ATTEMPTS) {
                cout << "Превышено количество попыток. Программа завершается." << endl;
                Sleep(1000);
                exit(1);
            }
        }
    } while (Hash(password) != correctHash);

    cout << "Доступ разрешен!" << endl << endl;
}
