#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution268 {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		nums.push_back( -1 );
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == -1)
				continue;
			while (nums[i] != i && nums[i] != -1)
			{
				swap(nums[i], nums[nums[i]]);
			}
		}
		int ret = 0;
		for (int i = 0; i < n+1; i++)
		{
			if (nums[i] == -1)
			{
				ret = i;
				break;
			}
		}
		return ret;
	}
};


int main()
{

	Solution268 s;
	vector<int> nums = {  };
	//vector<vector<int>> ret;
	int ret = s.missingNumber( nums );
	cout << endl;
	system("pause");
	return 0;
}