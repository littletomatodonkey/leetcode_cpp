#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution152 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		// local 表示的变量都是包含当前迭代的下标对应的元素的
		int localMin = nums[0];
		int localMax = nums[0];
		int globalMax = nums[0];
		int tmpLocalMax;
		for (int i = 1; i < nums.size(); i++)
		{
			tmpLocalMax = localMax;
			localMax = max( max(nums[i]*localMax, nums[i]), nums[i]*localMin );
			localMin = min(min(nums[i] * tmpLocalMax, nums[i]), nums[i] * localMin);
			globalMax = max( globalMax, localMax );
		}
		return globalMax;
	}
};


int main()
{
	Solution152 s;
	vector<int> nums = {2,3,-1,4,-1};
	cout << s.maxProduct(nums) << endl;
	system("pause");
	return 0;
}