#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution674 {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int globalLen = 1;
		int localLen = 1;
		int index = 1;
		while (index < nums.size())
		{
			if (nums[index] > nums[index - 1])
				localLen++;
			else
			{
				globalLen = max( globalLen, localLen );
				localLen = 1;
			}
			index++;
		}
		return max(localLen, globalLen);
	}
};

int main()
{
	vector<int> nums = { 2, 2, 3 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution674 s;
	auto ret = s.findLengthOfLCIS(nums);
	cout << endl;
	system("pause");
	return 0;
}