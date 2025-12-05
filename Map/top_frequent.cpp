#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
	map<int, int> freq;
	for (int n : nums) {
		freq[n]++;
	}
	vector<pair<int, int>> items;
	for (const auto& p : freq) {
		items.push_back(p);
	}
	sort(items.begin(), items.end(),
		[](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
		}
	);
	vector<int> result;
	for (int i = 0; i < k && i < (int)items.size(); i++) {
		result.push_back(items[i].first);
	}

	return result;
}

int main() {
	vector<int> nums2 = { 1,1,1,2,2,3 };
	auto result5 = topKFrequent(nums2, 2);
	cout << "Result of task 6: " << endl;
	for (int res : result5) {
		cout << res << " ";
	}
	cout << endl;
}