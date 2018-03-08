#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution081 {
public:
	
	bool binarySearch(vector<int>& nums, int target, int lidx, int ridx)
	{
		if (target < nums[lidx] || target > nums[ridx])
			return false;
		int l = lidx, r = ridx, middle;
		while (l <= r)
		{
			middle = (l + r) >> 1;
			if (nums[middle] == target)
				return true;
			if (nums[middle] < target)
				l = middle + 1;
			else if (nums[middle] > target)
				r = middle - 1;
		}
		return false;
	}

	bool search(vector<int>& nums, int target, int lidx, int ridx)
	{
		bool ret = false;
		if (nums.size() == 0 || ridx < lidx)
			return -1;
		int middle = (lidx + ridx) >> 1;
		if (nums[middle] == target)
			return true;
		if (nums[lidx] < nums[ridx])
			return binarySearch(nums, target, lidx, ridx);

		if (nums[middle] <= nums[ridx])
		{
			ret = binarySearch(nums, target, middle + 1, ridx);
			if (!ret)
				ret = search(nums, target, lidx, middle - 1);
			if (ret)
				return true;
		}
		if (nums[middle] >= nums[lidx])
		{
			ret = binarySearch(nums, target, lidx, middle - 1);
			if ( !ret )
				ret = search(nums, target, middle + 1, ridx);;
			if (ret)
				return true;
		}
		return false;

	}

	bool search(vector<int>& nums, int target) {
		return search(nums, target, 0, nums.size() - 1);
	}
	
};

int main()
{
	Solution081 s;
	vector<int> nums = { 1 };
	cout << s.search(nums,1) << endl;
	system("pause");
	return 0;
}