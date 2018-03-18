#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution162 {
public:
	int binary(vector<int>& nums, int left, int right)
	{
		int middle = (left + right) >> 1;
		int ret = -1;
		if (right - left + 1 < 3)
			return ret;
		if (right - left + 1 == 3)
		{
			if (nums[middle] > nums[left] && nums[middle] > nums[right])
				return middle;
			else
				return -1;
		}
		
		int flag;
		ret = binary(nums, left, middle+1);
		if (ret == -1)
		{
			if (middle - left <= 1)
				flag = middle;
			else
				flag = middle - 1;
			ret = binary(nums, flag, right);
		}
		return ret;
	}


	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		if (nums.size() == 2)
			return nums[1] > nums[0];
		if (nums[0] > nums[1])
			return 0;
		if (nums[nums.size() - 1] > nums[nums.size() - 2])
			return nums.size() - 1;
		return binary( nums, 0, nums.size()-1 );
	}
};


int main()
{
	Solution162 s;
	vector<int> nums = {1,3,2,1 };
	//vector<vector<int>> ret;
	int ret = s.findPeakElement( nums );
	cout << endl;
	system("pause");
	return 0;
}