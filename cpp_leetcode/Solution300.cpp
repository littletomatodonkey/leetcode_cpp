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
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> dp( nums.size(), 0 );
		dp[0] = 1;
		int tmpMax;
		int globalMax = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			tmpMax = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] > nums[j])
					tmpMax = max( tmpMax, dp[j] );
			}
			dp[i] = 1 + tmpMax;
			globalMax = max( globalMax, dp[i] );
		}
		return globalMax;
	}
};

int main()
{
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.lengthOfLIS(nums);
	cout << endl;
	system("pause");
	return 0;
}