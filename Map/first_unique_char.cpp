#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int firstUniqueChar(const string& s) {
	map<char, int> freq;

	for (char c : s) freq[c]++;

	for (int i = 0; i < s.size(); i++) {
		if (freq[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}


int main() {
	string s1 = "leetcode";
	string s2 = "loveleetcode";
	cout << "Result of task 4: " << endl;
	cout << firstUniqueChar(s1) << endl;
	cout << firstUniqueChar(s2) << endl;
}