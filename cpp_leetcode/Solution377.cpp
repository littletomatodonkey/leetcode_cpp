#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp( target+1, 0 );
		dp[0] = 1;
		std::sort( nums.begin(), nums.end() );
		for (int i = 1; i <= target; i++)
		{
			for (auto num : nums)
			{
				if (i < num)
					break;
				dp[i] += dp[i - num];
			}
		}
		return dp.back();
	}
};

int main()
{
	vector<int> nums = { 1,2,3 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.combinationSum4(nums, 2);
	cout << endl;
	system("pause");
	return 0;
}