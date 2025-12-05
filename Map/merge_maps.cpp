#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> mergeMaps(const map<string, int>& map1, const map<string, int>& map2) {
	map<string, int> result = map1;

	for (const auto& elem : map2) {
		const string& key = elem.first;
		int value = elem.second;
		result[key] += value;
	}

	return result;
}


int main() {
    
    map<string, int> map1 = { {"a", 1}, {"b", 2}, {"c", 3} };
	map<string, int> map2 = { {"b", 3}, {"c", 4}, {"d", 5} };

	auto result3 = mergeMaps(map1, map2);
	cout << "Result of task 3: " << endl;
	for (const auto& elem : result3) {
		cout << elem.first << ": " << elem.second << endl;
	}
}