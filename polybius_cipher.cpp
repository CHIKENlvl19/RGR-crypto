#include "ciper_header.h"
#include <iostream>
#include <vector>
#include <cmath>

extern const string FULL_ALPHABET;

vector<vector<char>> createPolybiusSquare() {
    int size = ceil(sqrt(FULL_ALPHABET.length()));
    vector<vector<char>> square(size, vector<char>(size, ' '));
    
    int idx = 0;
    for (int i = 0; i < size && idx < FULL_ALPHABET.length(); i++) {
        for (int j = 0; j < size && idx < FULL_ALPHABET.length(); j++) {
            square[i][j] = FULL_ALPHABET[idx++];
        }
    }
    return square;
}

pair<int, int> findPositionInPolybius(char c, const vector<vector<char>>& square) {
    for (int i = 0; i < square.size(); i++) {
        for (int j = 0; j < square[i].size(); j++) {
            if (square[i][j] == c) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

string encryptPolybius(const string& text) {
    auto square = createPolybiusSquare();
    string result;
    
    for (char c : text) {
        auto [row, col] = findPositionInPolybius(c, square);
        if (row != -1 && col != -1) {
            // Используем буквы вместо чисел для большей криптостойкости
            result += char('A' + row);
            result += char('A' + col);
        } else {
            result += c;
        }
    }
    return result;
}

string decryptPolybius(const string& text) {
    auto square = createPolybiusSquare();
    string result;
    
    for (size_t i = 0; i < text.length(); i += 2) {
        if (i + 1 < text.length()) {
            int row = text[i] - 'A';
            int col = text[i + 1] - 'A';
            
            if (row >= 0 && row < square.size() && 
                col >= 0 && col < square[0].size()) {
                result += square[row][col];
            } else {
                result += text[i];
                result += text[i + 1];
            }
        }
    }
    return result;
} 