#include <iostream>
#include <vector>
#include <set>
#include <cmath>

vector<int> symmetricDifference(vector<int>&arr1, vector<int>&arr2) {
    set<int>setArr1(arr1.begin(), arr1.end());
    set<int>setArr2(arr2.begin(), arr2.end());
    vector<int> result;

    for (int set : setArr1) {
        if (setArr2.count(set) == 0) result.push_back(set);
    }

    for (int set : setArr2) {
        if (setArr1.count(set) == 0) result.push_back(set);
    }
    return result;
}




int main() {
    vector<int> arr_1 = { 1,2,3,4 };
    vector<int> arr_2 = { 3,4,5,6 };

    auto result4 = symmetricDifference(arr_1, arr_2);
    cout << "Result of task 7: ";
    for (int set : result4) {
        cout << set << " ";
    }
    cout << endl;
}