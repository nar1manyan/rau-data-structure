#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int rangeCount(const set<int>& s, int low, int high) {
    auto itLow = s.lower_bound(low);
    auto itHigh = s.upper_bound(high);
    return distance(itLow, itHigh);
}

int main() {
    set<int> s2 = { 1,3,5,7,9,11,13,15 };
    cout << "Result of task 6: Range is: ";
    cout << rangeCount(s2, 5, 11) << endl;
}