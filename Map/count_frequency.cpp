#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> countFrequency(vector<int> nums) {
	map<int, int> freq;

	for (int num : nums) {
		freq[num]++;
	}
	return freq;
}

int main()
{
	vector<int> nums = { 4, 2, 3, 4, 2, 3, 4, 3, 1, 4 };
	auto result1 = countFrequency(nums);
	cout << "Result of task 1: " << endl;
	for (const auto& res : result1) {
		cout << res.first << ": " << res.second << std::endl;
	}
}