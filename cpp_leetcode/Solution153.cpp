#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution153 {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int middle;
		while (left < right)
		{
			middle = (left+right) >> 1 ;
			if (nums[right] > nums[left])
				return nums[left];
			if (nums[middle] >= nums[left])
				left = middle + 1;
			else
				right = middle;
		}
		return nums[left];
	}
};

int main()
{
	Solution153 s;
	vector<int> nums = { 2,1 };
	cout << s.findMin( nums ) << endl;
	system("pause");
	return 0;
}