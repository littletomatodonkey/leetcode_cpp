#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution724 {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.empty())
			return -1;
		vector<int> left(nums.size()+1, 0);
		vector<int> right(nums.size()+1, 0);
		for (int i = 1; i <= nums.size(); i++)
			left[i] = left[i-1] + nums[i - 1];
		for (int i = nums.size() - 2; i >= 0; i--)
			right[i] = right[i + 1] + nums[i+1];
		
		for (int i = 0; i < nums.size(); i++)
		{
			if (left[i] == right[i])
				return i;
		}
		return -1;
	}
};

int main()
{
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	//vector<vector<int>> nums;

	Solution724 s;
	auto ret = s.pivotIndex(nums);
	cout << endl;
	system("pause");
	return 0;
}