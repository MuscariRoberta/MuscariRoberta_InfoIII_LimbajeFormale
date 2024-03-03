#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

unordered_set<string> generateWords(const unordered_map<char, string>& productions, int maxLength) {
    unordered_set<string> words = { "S" }; 

    for (int i = 0; i < maxLength; ++i) {
        unordered_set<string> newWords; 
        for (const string& word : words) {
            for (size_t j = 0; j < word.size(); ++j) {
                char symbol = word[j];
                if (productions.find(symbol) != productions.end()) {
                    for (char replacement : productions.at(symbol)) {
                        string newWord = word;
                        newWord[j] = replacement;
                        newWords.insert(newWord);
                    }
                }
            }
        }
        words.insert(newWords.begin(), newWords.end());
    }
    return words;
}

int main() {
    unordered_map<char, string> productions = {
        {'S', "AB"},
        {'A', "aA"},
        {'B', "bB"}
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
