#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.count(num))
                return true;
            s.insert(num);
        }

        return false;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (obj.containsDuplicate(nums))
        cout << "Duplicate exists" << endl;
    else
        cout << "No duplicate found" << endl;

    return 0;
}