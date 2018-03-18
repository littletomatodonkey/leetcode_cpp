#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution561 {
public:
	int arrayPairSum(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int ret = 0;
		bool tmp[40010] = {false};
		int offset = 10000;
		int nowidx;
		for (int i = 0; i < nums.size(); i++)
		{
			nowidx = nums[i] + offset;
			if (tmp[nowidx])
			{
				ret += nums[i];
				tmp[nowidx] = false;
			}
			else
			{
				tmp[nowidx] = true;
			}
		}

		nowidx = 0;
		while (true)
		{
			while (nowidx < 40010 && !tmp[nowidx])
				nowidx++;
			if (nowidx >= 40010)
				break;
			
			ret += (nowidx - offset);
			nowidx++;
			while (!tmp[nowidx])
				nowidx++;
			nowidx++;
		}

		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,3,5,7};
	//vector<int> ret;
	Solution561 s;
	int ret = s.arrayPairSum(nums);
	cout << endl;
	system("pause");
	return 0;
}