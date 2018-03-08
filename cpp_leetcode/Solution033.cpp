#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution033 {
public:
	int binarySearch(vector<int>& nums, int target, int lidx, int ridx)
	{
		if (target < nums[lidx] || target > nums[ridx])
			return -1;
		int l = lidx, r = ridx, middle;
		while (l <= r)
		{
			middle = (l + r) >> 1;
			if (nums[middle] == target)
				return middle;
			if (nums[middle] < target)
				l = middle + 1;
			else if (nums[middle] > target)
				r = middle - 1;
		}
		return -1;
	}

	int search(vector<int>& nums, int target, int lidx, int ridx)
	{
		int ret = -1;
		if (nums.size() == 0 || ridx < lidx)
			return -1;
		int middle = (lidx + ridx) >> 1;
		if (nums[middle] == target)
			return middle;
		if ( nums[lidx] <= nums[ridx] )
			return binarySearch(nums, target, lidx, ridx);

		if (nums[middle] <= nums[ridx])
		{
			ret = binarySearch(nums, target, middle + 1, ridx);
			if (ret != -1)
				return ret;
			else
				return search( nums, target, lidx, middle-1 );
		}
		else if (nums[middle] >= nums[lidx])
		{
			ret = binarySearch(nums, target, lidx, middle-1);
			if (ret != -1)
				return ret;
			else
				return search(nums, target, middle + 1, ridx);
		}
		return -1;

	}

	int search(vector<int>& nums, int target) {
		return search( nums, target, 0, nums.size()-1 );
	}
};

int main()
{
	Solution033 s;
	vector<int> nums = {3,1};
	cout << s.search(nums, 1) << endl;
	system("pause");
	return 0;
}