#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 在每次dp的时候，需要维护他的前驱下标
// 参考链接：https://leetcode.com/problems/largest-divisible-subset/discuss/83998/C++-Solution-with-Explanations
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		
		std::sort( nums.begin(), nums.end() );
		vector<int> len(nums.size(), 0);
		vector<int> son(nums.size(), 0);
		int currIdx = 0, maxLen = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (nums[i] % nums[j] == 0 && len[j] + 1 > len[i])
				{
					len[i] = len[j] + 1;
					son[i] = j;
				}
			}
			if (len[i] > maxLen)
			{
				maxLen = len[i];
				currIdx = i;
			}
		}

		vector<int> ret(maxLen,0);
		for (int i = 0; i < maxLen; i++)
		{
			ret[i] = nums[currIdx];
			currIdx = son[currIdx];
		}

		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,2,5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.largestDivisibleSubset(nums);
	cout << endl;
	system("pause");
	return 0;
}