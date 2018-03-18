#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution665 {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() <= 1)
			return true;
		bool used = false;
		int lmin = 0;
		for (int i = 0; i < nums.size()-1; i++)
		{
			if (nums[i] <= nums[i + 1])
				continue;
			if (!used)
			{
				used = true;
				if (i == 0 || nums[i - 1] <= nums[i + 1])
					continue;
				else
				{
					nums[i + 1] = nums[i];
					continue;
				}
				return false;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<int> nums = { 4,2,3};
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution665 s;
	auto ret = s.checkPossibility(nums);
	cout << endl;
	system("pause");
	return 0;
}