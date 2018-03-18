#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution565 {
public:
	int arrayNesting(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int len = 0;
		int tmp = 0;
		vector<bool> visited(nums.size(), false);
		int slow = 0;
		int fast = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i])
				continue;
			tmp = 0;
			slow = i;
			fast = i;
			while ( nums[slow] != nums[nums[fast]])
			{
				visited[slow] = true;
				slow = nums[slow];
				fast = nums[nums[fast]];
				tmp++;
			}
			tmp++;
			visited[slow] = true;
			len = max( tmp, len );
		}
		return len;
	}
};

int main()
{
	vector<int> nums = { 0,2,1 };
	//vector<int> ret;
	Solution565 s;
	int ret = s.arrayNesting(nums);
	cout << endl;
	system("pause");
	return 0;
}