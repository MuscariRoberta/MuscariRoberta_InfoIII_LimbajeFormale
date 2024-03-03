#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateStrings(const vector<char>& S, int iterations) {
    if (iterations == 0) {
        return { "" };
    }

    vector<string> strings;
    for (char symbol : S) {
        if (symbol == 'S') {
            for (char terminal : {'a', 'b'}) {
                vector<string> generated = generateStrings(S, iterations - 1);
                for (const string& x : generated) {
                    strings.push_back(terminal + x + terminal);
                }
                strings.push_back(string(1, terminal));
            }
        }
        else if (symbol == 'A') {
            for (char terminal : {'a', 'b'}) {
                vector<string> generated = generateStrings(S, iterations - 1);
                for (const string& x : generated) {
                    strings.push_back(terminal + x + terminal);
                }
                strings.push_back(string(iterations, 'a'));
                strings.push_back(string(iterations, 'b'));
            }
        }
        else if (symbol == 'B') {
            strings.push_back(string(iterations, 'a'));
            strings.push_back(string(iterations, 'b'));
        }
    }

    return strings;
}

int main() {
    vector<char> V = { 'S', 'A', 'B' };
    vector<char> T = { 'a', 'b' };
    int iterations = 3;
    vector<string> generatedStrings = generateStrings(V, iterations);

    cout << "Generated strings:" << endl;
    for (const string& str : generatedStrings) {
        cout << str << endl;
    }

    return 0;
}
