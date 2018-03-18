#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution090 {
public:

	void dfs(vector<int>& nums, vector<vector<int>>& ret, int nowIdx, vector<int>& now, vector<int>& vcnt)
	{
		if (nowIdx >= nums.size())
			return;
		for (int i = nowIdx; i < nowIdx + vcnt[nowIdx]; i++)
		{
			now.push_back( nums[i] );
			ret.push_back( now );
			dfs(nums, ret, nowIdx + vcnt[nowIdx], now, vcnt );
		}
		for (int i = nowIdx; i < nowIdx + vcnt[nowIdx]; i++)
			now.pop_back();
		dfs(nums, ret, nowIdx + vcnt[nowIdx], now, vcnt);
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() == 0)
			return ret;
		vector<int> now;
		vector<int> vcnt(nums.size(), 1);

		sort(nums.begin(), nums.end());

		int tmp = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] == tmp)
				vcnt[i] = vcnt[i + 1] + 1;
			else
				tmp = nums[i];

		}
		dfs( nums, ret, 0, now, vcnt  );
		now.clear();
		ret.push_back( now );
		return ret;
		
	}
};

int main()
{
	Solution090 s;
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> ret = s.subsetsWithDup( nums );
	cout << endl;
	system("pause");
	return 0;
}