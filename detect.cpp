#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", "void"};
int keywordCount = 9;

bool isKeyword(string word) {
    for (int i = 0; i < keywordCount; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isValidIdentifier(string word) {
    if (!isalpha(word[0]) && word[0] != '_')
        return false;

    for (int i = 1; i < word.length(); i++) {
        if (!isalnum(word[i]) && word[i] != '_')
            return false;
    }
    return true;
}

int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cout << "Unable to open the file." << endl;
        return 1;
    }

    char ch;
    string word = "";

    cout << "\nDetected Tokens:\n";

    while (file.get(ch)) {

        if (isalnum(ch) || ch == '_') {
            word += ch;
        }
        else {
            if (!word.empty()) {
                if (isKeyword(word))
                    cout << word << " -> Keyword" << endl;
                else if (isValidIdentifier(word))
                    cout << word << " -> Valid Identifier" << endl;
                else
                    cout << word << " -> Invalid Identifier" << endl;
                word = "";
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
                cout << ch << " -> Operator" << endl;
            else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}')
                cout << ch << " -> Separator" << endl;
        }
    }

    file.close();
    return 0;
}
