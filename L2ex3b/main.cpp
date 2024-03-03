#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

unordered_set<string> generateWords(const unordered_map<char, vector<string>>& productions, int maxLength, vector<string> currentWords = { "S" }) {
    if (maxLength == 0) {
        return {};
    }

    vector<string> newWords;
    for (const string& word : currentWords) {
        if (word.length() <= maxLength) {
            for (size_t i = 0; i < word.length(); ++i) {
                char symbol = word[i];
                if (productions.find(symbol) != productions.end()) {
                    for (const string& production : productions.at(symbol)) {
                        string newWord = word;
                        newWord.replace(i, 1, production);
                        newWords.push_back(newWord);
                    }
                }
            }
        }
    }

    unordered_set<string> uniqueWords(newWords.begin(), newWords.end());
    vector<string> terminalWords;
    for (const string& word : uniqueWords) {
        bool isTerminal = true;
        for (char c : word) {
            if (productions.find(c) != productions.end()) {
                isTerminal = false;
                break;
            }
        }
        if (isTerminal) {
            terminalWords.push_back(word);
        }
    }

    unordered_set<string> result(terminalWords.begin(), terminalWords.end());
    unordered_set<string> recursiveWords = generateWords(productions, maxLength - 1, vector<string>(uniqueWords.begin(), uniqueWords.end()));
    result.insert(recursiveWords.begin(), recursiveWords.end());

    return result;
}

int main() {
    unordered_map<char, vector<string>> productions = {
        {'S', {"X"}},
        {'X', {"0Y", "1Z"}},
        {'Y', {"2", "X"}},
        {'Z', {"3", "4", "X"}}
    };

    int maxLength;
    cout << "Enter max length: ";
    cin >> maxLength;

    unordered_set<string> words = generateWords(productions, maxLength);

    cout << "Generated words:" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
