#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution154 {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int middle;
		while (left < right)
		{
			if (nums[right] > nums[left])
				return nums[left];
			middle = (left + right) >> 1;
			if (nums[middle] < nums[left])
				right = middle;
			else if (nums[middle] > nums[right])
				left = middle+1;
			// 消除相等元素对寻找最小值的影响
			if (nums[middle] == nums[left])
			{
				while (left < nums.size() && nums[middle] == nums[left])
					left++;
				left--;
			}
			if (nums[middle] == nums[right])
			{
				while (right >= 0 && nums[middle] == nums[right])
					right--;
				right++;
			}
		}
		return nums[left];
	}
};

int main()
{
	Solution154 s;
	vector<int> nums = { 4,5,6,6,1 };
	cout << s.findMin(nums) << endl;
	system("pause");
	return 0;
}