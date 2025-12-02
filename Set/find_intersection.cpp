#include <iostream>
#include <vector>
#include <set>
#include <cmath>

vector<int> findIntersection(const vector<int>& v1, const vector<int>& v2) {
    set<int> set1(v1.begin(), v1.end());
    set<int> set2(v2.begin(), v2.end());
    vector<int> result;

    for (int x : set1) {
        if (set2.count(x)) {
            result.push_back(x);
        }
    }

    return result;
}


int main() {
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 3, 4, 5, 6, 7 };
    auto result2 = findIntersection(arr1, arr2);
    cout << "Result of task 2: ";
    for (int x : result2) {
        cout << x << " ";
    }
    cout << endl;
}