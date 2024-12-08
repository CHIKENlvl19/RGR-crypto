#ifndef CIPER_HEADER_H
#define CIPER_HEADER_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

// Объявление глобальных переменных
extern const string FULL_ALPHABET;

// Базовые функции
void Password();
unsigned int Hash(const string& password);

// Шифр пар
string encryptPairs(const string& text, const string& key);
string decryptPairs(const string& text, const string& key);

// Шифр ADFGX
string encryptADFGX(const string& text, const string& key);
string decryptADFGX(const string& text, const string& key);

// Квадрат Полибия
string encryptPolybius(const string& text);
string decryptPolybius(const string& text);

#endif
