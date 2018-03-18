#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution442 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < nums.size();)
		{
			if (nums[nums[i] - 1] != nums[i])
			{
				swap( nums[i], nums[nums[i]-1] );
			}
			else
			{
				i++;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
				ret.push_back(nums[i]);
		}
		return ret;
		
	}
};

int main()
{
	vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	Solution442 s;
	//int ret;
	vector<int> ret = s.findDuplicates( nums );
	cout << endl;
	system("pause");
	return 0;
}