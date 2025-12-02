#include <iostream>
#include <vector>
#include <set>
#include <cmath>

vector<int> removeDuplicates(const vector<int>& nums) {
    set<int> uniqueSet(nums.begin(), nums.end());
    vector<int> result(uniqueSet.begin(), uniqueSet.end());
    return result;
}

int main() {
    vector<int> nums1 = { 4, 2, 5, 2, 3, 4, 1 };
    auto result1 = removeDuplicates(nums1);
    cout << "Result of task 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
}