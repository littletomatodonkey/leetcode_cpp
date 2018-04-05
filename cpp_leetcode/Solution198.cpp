#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution198 {
public:
	int rob(vector<int>& nums) {
		vector<int> ret( nums.size()+2, 0 );
		for (int i = 0; i < nums.size(); i++)
		{
			ret[i + 2] = max( nums[i]+ret[i], ret[i+1] );
		}
		return ret.back();
	}
};

int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution198 s;
	auto ret = s.rob(nums);
	cout << endl;
	system("pause");
	return 0;
}