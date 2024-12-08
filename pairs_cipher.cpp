#include "ciper_header.h"
#include <iostream>
#include <string>
#include <algorithm>

extern const string FULL_ALPHABET;
    
string encryptPairs(const string& text, const string& key) {
    if (text.empty() || key.empty()) return "";
    
    string result;
    for (size_t i = 0; i < text.length(); i += 2) {
        char first = text[i];
        char second = (i + 1 < text.length()) ? text[i + 1] : ' ';
        
        // Находим позиции символов в расширенном алфавите
        size_t pos1 = FULL_ALPHABET.find(first);
        size_t pos2 = FULL_ALPHABET.find(second);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            // Сдвигаем позиции на длину ключа
            pos1 = (pos1 + key.length()) % FULL_ALPHABET.length();
            pos2 = (pos2 + key.length()) % FULL_ALPHABET.length();
            
            result += FULL_ALPHABET[pos1];
            result += FULL_ALPHABET[pos2];
        } else {
            result += first;
            result += second;
        }
    }
    return result;
}

string decryptPairs(const string& text, const string& key) {
    if (text.empty() || key.empty()) return "";
    
    string result;
    for (size_t i = 0; i < text.length(); i += 2) {
        char first = text[i];
        char second = (i + 1 < text.length()) ? text[i + 1] : ' ';
        
        // Находим позиции символов в расширенном алфавите
        size_t pos1 = FULL_ALPHABET.find(first);
        size_t pos2 = FULL_ALPHABET.find(second);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            // Сдвигаем позиции назад на длину ключа
            pos1 = (pos1 + FULL_ALPHABET.length() - (key.length() % FULL_ALPHABET.length())) % FULL_ALPHABET.length();
            pos2 = (pos2 + FULL_ALPHABET.length() - (key.length() % FULL_ALPHABET.length())) % FULL_ALPHABET.length();
            
            result += FULL_ALPHABET[pos1];
            result += FULL_ALPHABET[pos2];
        } else {
            result += first;
            result += second;
        }
    }
    return result;
} 