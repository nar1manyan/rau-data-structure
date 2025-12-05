#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, vector<string>> groupByFirstChar(const vector<string>& words) {
	map<char, vector<string>> groups;

	for (const auto& word : words) {
		if (!word.empty()) {
			char first = word[0];
			groups[first].push_back(word);
		}
	}
	return groups;
}

int main() {
	vector<string> words1 = { "apple", "banana", "apricot", "cherry", "avocado" };
	auto result2 = groupByFirstChar(words1);
	cout << "Result of task 2: " << endl;
	for (const auto& elem : result2) {
		cout << elem.first << ": ";
		for (const auto& s : elem.second) {
			cout << s << " ";
		}
		cout << endl;
	}
}