#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution532 {
public:
	int findPairs(vector<int>& nums, int k) {
		int ret = 0;
		if (nums.size() <= 1)
			return ret;
		std::sort(nums.begin(), nums.end());
		int minIdx = 0;
		int maxIdx = 1;
		int now = nums[0];
		while (true)
		{
			if (nums[maxIdx] - nums[minIdx] == k)
			{
				ret++;
				now = nums[minIdx];
				while (minIdx < nums.size() && nums[minIdx] == now)
				{
					minIdx++;
				}
				maxIdx = minIdx+1;
			}
			else if (nums[maxIdx] - nums[minIdx] > k)
			{
				minIdx++;
				if (minIdx == maxIdx)
				{
					maxIdx++;
				}
			}
			else
			{
				maxIdx++;
			}
			if (minIdx >= nums.size() || maxIdx >= nums.size())
				break;
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,3,1,5,4,4 };
	//vector<int> ret;
	Solution532 s;
	int ret = s.findPairs(nums, 1);
	cout << endl;
	system("pause");
	return 0;
}