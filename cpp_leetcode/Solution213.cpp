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
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		return max( robBtween(nums,0, nums.size()-2), robBtween(nums, 1, nums.size()-1)  );
	}

	int robBtween(vector<int>& nums, int start, int end) 
	{
		int prepre = 0, pre = nums[start], curr;
		for (int i = start+1; i <= end; i++)
		{
			curr = max( prepre+nums[i], pre );
			prepre = pre;
			pre = curr;
		}
		return pre;
	}
};


int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	vector<string> ss = { "a", "b" };
	auto ret = s.rob(nums);
	cout << endl;
	system("pause");
	return 0;
}