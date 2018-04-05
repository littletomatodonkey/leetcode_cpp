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

// DP的参考链接：http://www.cnblogs.com/grandyang/p/5951422.html
class Solution {
public:
	// 使用DFS会超时
	bool dfs(vector<int>& nums, vector<bool>& visit, int nowSum, int sum)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (!visit[i])
			{
				if (nums[i] + nowSum == sum)
					return true;
				if (nums[i] + nowSum < sum)
				{
					visit[i] = true;
					bool ret = dfs( nums, visit, nowSum+nums[i], sum );
					if (ret)
						return true;
					visit[i] = false;
				}
				else
					break;
			}
		}
		return false;
	}

	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto num : nums)
			sum += num;
		if (sum % 2 != 0)
			return false;
		std::sort(nums.begin(), nums.end());
		int half = sum >> 1;
		vector<bool> dp( half+1, false );
		dp[0] = true;
		for (auto num : nums)
		{
			for (int i = half; i >= num; i--)
				dp[i] = dp[i] || dp[i - num];
		}

		return dp.back();


		// 下面是DFS的代码
		//int sum = 0;
		//for (auto num : nums)
		//	sum += num;
		//if (sum % 2 != 0)
		//	return false;
		//int half = sum >> 1;
		//std::sort( nums.begin(), nums.end());
		//vector<bool> visit( nums.size(), false );
		//return dfs( nums, visit, 0, half );
	}
};

int main()
{
	vector<int> nums = { 1, 3,4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.canPartition(nums);
	cout << endl;
	system("pause");
	return 0;
}