#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution581 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		int maxV = nums[0];
		int minV = nums.back();
		int start = -1;
		int end = -2;
		for (int i = 1; i < nums.size(); i++)
		{
			maxV = max( nums[i], maxV );
			minV = min( nums[nums.size()-i-1], minV );
			if (maxV > nums[i])
				end = i;
			if (minV < nums[nums.size() - i - 1])
				start = nums.size() - i - 1;
		}
		return end - start + 1;
	}
};

int main()
{
	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution581 s;
	auto ret = s.findUnsortedSubarray(nums);
	cout << endl;
	system("pause");
	return 0;
}