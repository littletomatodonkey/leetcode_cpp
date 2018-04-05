#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<long long> bst;
		for (int i = 0; i < nums.size(); i++)
		{
			if (bst.size() >= k + 1)
				bst.erase( bst.find(nums[i-k-1]) );
			auto lb = bst.lower_bound( nums[i] );
			if (lb != bst.end() && abs(*lb - nums[i]) <= t)
				return true;
			auto ub = bst.upper_bound(nums[i]);
			if (ub != bst.begin() && abs(*(--ub) - nums[i]) <= t)
				return true;
			bst.insert( nums[i] );
		}

		return false;
	}
};

int main()
{
	vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, { 2, 5 } };
	//vector<vector<char>> nums = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.containsNearbyAlmostDuplicate(nums, 1, 2);
	cout << endl;
	system("pause");
	return 0;
}