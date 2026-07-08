#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> TopKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Min Heap: (frequency, element)
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Optional: reverse to print highest frequency first
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    vector<int> ans = obj.TopKFrequent(nums, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}