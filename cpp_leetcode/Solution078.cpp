#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution078 {
public:
	void dfs(vector<vector<int>>& ret, vector<int>& nums, int index, vector<int>& now)
	{
		if (index >= nums.size())
			return;
		now.push_back( nums[index] );
		ret.push_back(now);
		dfs( ret, nums, index+1, now );
		now.pop_back();
		dfs( ret, nums, index+1, now );
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret(0);
		vector<int> now(0);
		dfs( ret, nums, 0, now );
		ret.push_back( vector<int>(0) );
		return ret;
	}
};

int main()
{
	vector<int> nums = { };
	Solution078 s;
	vector<vector<int>> ret = s.subsets(nums);

	system("pause");
	return 0;
}