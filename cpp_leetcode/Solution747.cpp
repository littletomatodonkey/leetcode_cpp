#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution747 {
public:
	int dominantIndex(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;
		if (nums.size() == 1)
			return 0;
		int idx1 = 0, idx2 = 1;
		if (nums[0] <= nums[1])
			swap( idx1, idx2 );
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] >= nums[idx1])
			{
				idx2 = idx1;
				idx1 = i;
			}
			else if (nums[i] > nums[idx2])
			{
				idx2 = i;
			}
		}
		if (nums[idx1] >= nums[idx2] * 2)
			return idx1;
		return -1;
	}
};

int main()
{
	vector<int> nums = { 1,2,3,4 };
	//vector<vector<int>> nums;
	Solution747 s;
	auto ret = s.dominantIndex(nums);
	cout << endl;
	system("pause");
	return 0;
}