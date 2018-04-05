#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		multiset<long long> sums;
		sums.insert( 0 );
		long long tmp = 0;
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			tmp += nums[i];
			result += distance( sums.lower_bound(tmp-upper), sums.upper_bound(tmp-lower) );
			sums.insert( tmp );
		}

		return result;
	}
};


int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	auto ret = s.countRangeSum(nums, -2, 2);
	cout << endl;
	system("pause");
	return 0;
}