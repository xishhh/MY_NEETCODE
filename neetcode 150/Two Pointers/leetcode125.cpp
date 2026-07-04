// # VALID PALLIDNROME 

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {

            while (l < r && !isalnum(s[l])) {
                l++;
            }

            while (l < r && !isalnum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if (obj.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}