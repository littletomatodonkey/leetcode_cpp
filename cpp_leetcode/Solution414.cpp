#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution414 {
public:
	int thirdMax(vector<int>& nums) {
		set<int> ret;
		int index = 0;
		while (ret.size() < 3 && index < nums.size())
		{
			ret.insert( nums[index++] );
		}
		vector<int> res(ret.begin(), ret.end());
		reverse(res.begin(), res.end());
		if (ret.size() <= 2)
			return res[0];

		for (; index < nums.size(); index++)
		{
			if (nums[index] > res[0])
			{
				res[2] = res[1];
				res[1] = res[0];
				res[0] = nums[index];
			}
			else if (nums[index] < res[0] && nums[index] > res[1])
			{
				res[2] = res[1];
				res[1] = nums[index];
			}
			else if (nums[index] < res[1] && nums[index] > res[2])
			{
				res[2] = nums[index];
			}
		}
		return res.back();
	}
};

int main()
{
	vector<int> nums = { 1,2,2,5,3,5 };
	Solution414 s;
	int ret = s.thirdMax( nums );
	cout << endl;
	system("pause");
	return 0;
}