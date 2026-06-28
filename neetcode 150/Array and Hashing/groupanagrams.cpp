#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//FUNCTION

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }

    vector<vector<string>> ans;

    for (auto &it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}


// MAIN SECTION 
int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";

    for (auto &group : result) {
        cout << "[ ";
        for (string &word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}


//SECOND APPROACH


// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <string>

// using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     unordered_map<string, vector<string>> mp;

//     for (string str : strs) {

//         // Frequency of each character
//         vector<int> freq(26, 0);

//         for (char c : str) {
//             freq[c - 'a']++;
//         }

//         // Create a unique key
//         string key = "";

//         for (int i = 0; i < 26; i++) {
//             key += "#";
//             key += to_string(freq[i]);
//         }

//         mp[key].push_back(str);
//     }

//     vector<vector<string>> ans;

//     for (auto &it : mp) {
//         ans.push_back(it.second);
//     }

//     return ans;
// }

// int main() {
//     int n;

//     cout << "Enter number of strings: ";
//     cin >> n;

//     vector<string> strs(n);

//     cout << "Enter the strings:\n";

//     for (int i = 0; i < n; i++) {
//         cin >> strs[i];
//     }

//     vector<vector<string>> result = groupAnagrams(strs);

//     cout << "\nGrouped Anagrams:\n";

//     for (auto &group : result) {
//         cout << "[ ";

//         for (string word : group) {
//             cout << word << " ";
//         }

//         cout << "]\n";
//     }

//     return 0;
// }