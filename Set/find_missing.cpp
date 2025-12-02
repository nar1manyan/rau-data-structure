#include <iostream>
#include <vector>
#include <set>
#include <cmath>

vector<int> findMissingNumbers(const vector<int>& nums, int N) {
    set<int> present(nums.begin(), nums.end());
    vector<int> missing_nums;

    for (int i = 1; i <= N; ++i) {
        if (present.find(i) == present.end()) {
            missing_nums.push_back(i);
        }
    }
    return missing_nums;
}

int main() {
    vector<int> nums2 = { 1,3,5,6 };
    auto result3 = findMissingNumbers(nums2, 6);
    cout << "Result of task 4: Missing Numbers: ";
    for (int missing_number : result3) {
        cout << missing_number << " ";
    }
    cout << endl;
}