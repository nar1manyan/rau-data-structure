#include <iostream>
#include <vector>
#include <set>
#include <cmath>

bool isSubset(const vector<int>& subset, const vector<int>& superset) {
    set<int> superSetSet(superset.begin(), superset.end());
    for (int x : subset) {
        if (!superSetSet.count(x)) {
            return false;
        }
    }
    return true;
}



int main() {
    vector<int> subset = { 1,3,5 };
    vector<int> superset = { 1,2,3,4,5 };

    cout << "Result of task 3: "; 
    cout << isSubset(subset, superset) << endl;
    vector<int> subset2 = { 1,6 };
    cout << isSubset(subset2, superset) << endl;
}