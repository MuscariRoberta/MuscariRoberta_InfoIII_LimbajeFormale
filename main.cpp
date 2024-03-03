#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void generateAllPalindromes(const vector<int>& nums) {
    for (int length = 1; length <= 5; ++length) {
        cout << "Palindroame de " << length << " cifre:" << endl;
        for (int num : nums) {
            string current = to_string(num);
            if (length == 1 && isPalindrome(current))
                cout << current << endl;
            else if (length > 1) {
                for (int i = 0; i < nums.size(); ++i) {
                    string next = to_string(num) + current + to_string(nums[i]);
                    if (isPalindrome(next))
                        cout << next << endl;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums = { 0, 1, 2 };
    generateAllPalindromes(nums);
    return 0;
}
