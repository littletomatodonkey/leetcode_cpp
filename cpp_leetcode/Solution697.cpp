#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution697 {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> ret;
		for (int i = 0; i < nums.size();i++)
			ret[nums[i]].push_back( i );
		if (ret.empty())
			return 0;
		int len = 0;
		int most = 0;
		for (auto it = ret.begin(); it != ret.end(); it++)
		{
			if ((*it).second.size() > most)
			{
				most = (*it).second.size();
				len = (*it).second.back() - (*it).second[0] + 1;
			}
			else if ((*it).second.size() == most)
				len = min(len, (*it).second.back() - (*it).second[0] + 1);
		}
		return len;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 2, 3, 1, 4, 2 };
	//vector<vector<int>> nums;
	Solution697 s;
	auto ret = s.findShortestSubArray(nums);
	cout << endl;
	system("pause");
	return 0;
}