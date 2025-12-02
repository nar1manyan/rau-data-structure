#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int findClosest(const set<int>& s, int target) {
    if (s.empty()) return -1;
    auto it = s.lower_bound(target);
    if (it == s.begin()) return *it;
    if (it == s.end()) return *prev(it);
    int higher = *it;
    int lower = *prev(it);
    if (abs(higher - target) < (target - lower)) return higher;
    else return lower;
    return lower;
}

int main() {
    set<int>s1 = { 1,5,10,15,20 };
    cout << "Result of task 5: ";
    cout << findClosest(s1, 12) << " ";
    cout << findClosest(s1, 13) << endl;
}