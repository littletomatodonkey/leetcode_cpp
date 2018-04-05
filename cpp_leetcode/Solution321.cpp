#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 从第一个数组中取i个数字，从第二个数组中取k-i个数字，然后拼凑成最大的数字并保存
// 参考链接：https://www.hrwhisper.me/leetcode-create-maximum-number/
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ret(k, 0);
		for (int i = max((int)(k-nums2.size()),0); i <= min((int)nums1.size(), k); i++)
		{
			vector<int> ret1 = getMaxSubArray( nums1, i );
			vector<int> ret2 = getMaxSubArray(nums2, k-i);
			vector<int> ans( k, 0 );
			int pos1 = 0, pos2 = 0, tpos = 0;
			int idx1 = 0, idx2 = 0;
			while (pos1 < ret1.size() && pos2 < ret2.size())
			{
				if (ret1[pos1] > ret2[pos2])
					ans[tpos++] = ret1[pos1++];
				else if ( ret1[pos1] < ret2[pos2] )
					ans[tpos++] = ret2[pos2++];
				else
				{
					idx1 = pos1;
					idx2 = pos2;
					while (idx1 < ret1.size() && idx2 < ret2.size())
					{
						if (ret1[idx1] > ret2[idx2])
						{
							ans[tpos++] = ret1[pos1++];
							break;
						}
						if (ret1[idx1] < ret2[idx2])
						{
							ans[tpos++] = ret2[pos2++];
							break;
						}
						idx1++;
						idx2++;
					}
					if (idx1 == ret1.size())
						ans[tpos++] = ret2[pos2++];
					else if ( idx2 == ret2.size() )
						ans[tpos++] = ret1[pos1++];
				}
			}
			while ( pos1 < ret1.size() )
				ans[tpos++] = ret1[pos1++];
			while (pos2 < ret2.size())
				ans[tpos++] = ret2[pos2++];

			if (!greaterOrEqual(ret, ans))
				ret = ans;

		}
		return ret;
	}

	bool greaterOrEqual(vector<int> &nums1, vector<int> &nums2)
	{
		for (int i = 0; i < nums1.size(); i++)
		{
			if (nums1[i] > nums2[i])
				return true;
			if (nums1[i] < nums2[i])
				return false;
		}
		return true;
	}

	vector<int> getMaxSubArray(vector<int> &nums, int k)
	{
		vector<int> ret(k);
		int len = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			while (len > 0 && len + nums.size() - i > k && ret[len - 1] < nums[i])
				len--;
			if (len < k)
				ret[len++] = nums[i];
		}
		return ret;
	}
};



int main()
{
	vector<int> nums = { 3,4,8,9,3,0 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	vector<int> nums2 = { 6,1,9,1,1,2};
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.maxNumber(nums, nums2, 6);
	cout << endl;
	system("pause");
	return 0;
}