#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <regex>
using namespace std;

// Check if a character is a delimiter
bool isDelimiter(char ch) {
    string delimiters = ";,(){}[]";
    return delimiters.find(ch) != string::npos;
}

// Check if a string is a valid integer
bool isInteger(const string& str) {
    regex intRegex("^-?\\d+$");
    return regex_match(str, intRegex);
}

// Check if a string is a valid real number
bool isRealNumber(const string& str) {
    regex realRegex("^-?\\d*\\.\\d+$");
    return regex_match(str, realRegex);
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "File could not be opened.\n";
        return 1;
    }

    string token;
    char ch;

    cout << "Delimiters, Integers, and Real Numbers found:\n\n";

    while (file.get(ch)) {
        if (isDelimiter(ch)) {
            cout << "Delimiter: " << ch << endl;
        } else if (isspace(ch)) {
            continue;
        } else if (isdigit(ch) || ch == '-' || ch == '.') {
            token.clear();
            token += ch;

            // Read the rest of the number
            while (file.peek() != EOF && (isdigit(file.peek()) || file.peek() == '.')) {
                file.get(ch);
                token += ch;
            }

            if (isInteger(token)) {
                cout << "Integer: " << token << endl;
            } else if (isRealNumber(token)) {
                cout << "Real Number: " << token << endl;
            }
        }
    }

    file.close();
    return 0;
}
