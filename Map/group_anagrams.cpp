#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& words) {
	map<string, vector<string>> groups;

	for (const auto& word : words) {
		string key = word;
		sort(key.begin(), key.end());
		groups[key].push_back(word);
	}

	vector<vector<string>> result;
	for (auto& elem : groups) {
		result.push_back(elem.second);
	}

	return result;
}


int main() {
    vector<string> words2 = { "eat", "tea", "tan", "ate", "nat", "bat" };
	auto result4 = groupAnagrams(words2);
	cout << "Result of task 5: " << endl;
	for (const auto& group : result4) {
		cout << "[ ";
		for (const auto& word : group) {
			cout << word << " ";
		}
		cout << "]" << endl;
	}
}