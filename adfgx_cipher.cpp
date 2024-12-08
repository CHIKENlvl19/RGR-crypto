#include "ciper_header.h"
#include <iostream>

extern const string FULL_ALPHABET;

string encryptADFGX(const string& text, const string& key) {
    if (text.empty() || key.empty()) return "";
    
    string result;
    string adfgx = "ADFGX";
    
    // Создаем матрицу шифрования
    vector<vector<char>> matrix(5, vector<char>(5));
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = FULL_ALPHABET[idx % FULL_ALPHABET.length()];
            idx++;
        }
    }
    
    // Шифруем текст
    for (char c : text) {
        bool found = false;
        for (int i = 0; i < 5 && !found; i++) {
            for (int j = 0; j < 5; j++) {
                if (matrix[i][j] == c) {
                    result += adfgx[i];
                    result += adfgx[j];
                    found = true;
                    break;
                }
            }
        }
        if (!found) result += c;
    }
    
    return result;
}

string decryptADFGX(const string& text, const string& key) {
    if (text.empty() || key.empty()) return "";
    
    string result;
    string adfgx = "ADFGX";
    
    // Создаем матрицу дешифрования
    vector<vector<char>> matrix(5, vector<char>(5));
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = FULL_ALPHABET[idx % FULL_ALPHABET.length()];
            idx++;
        }
    }
    
    // Дешифруем текст
    for (size_t i = 0; i < text.length(); i += 2) {
        if (i + 1 < text.length()) {
            int row = adfgx.find(text[i]);
            int col = adfgx.find(text[i + 1]);
            if (row != string::npos && col != string::npos) {
                result += matrix[row][col];
            }
        }
    }
    
    return result;
} 