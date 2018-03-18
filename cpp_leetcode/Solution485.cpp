#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution485 {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int globalMax = 0;
		int localMax = 0;
		int index = 0;
		while (true)
		{
			while (index < nums.size() && nums[index] == 1)
			{
				index++;
				localMax++;
			}
			if (index == nums.size())
				break;
			else
			{
				globalMax = max( globalMax, localMax );
				localMax = 0;
				index++;
			}
		}
		globalMax = max(globalMax, localMax);
		return globalMax;
	}
};

int main()
{
	vector<int> nums = { 1,1,0,0,0,1,1,1,1 };
	Solution485 s;
	int ret = s.findMaxConsecutiveOnes(nums);
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}