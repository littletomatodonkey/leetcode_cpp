#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution566 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() == 0 || nums[0].size() == 0 || r*c != nums.size()*nums[0].size())
			return nums;
		vector<int> tmp(c);
		vector<vector<int>> ret(r, tmp);
		int m = nums.size(), n = nums[0].size();
		int index = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				ret[i][j] = nums[index / n][index%n];
				index++;
			}
		}
		return ret;

	}
};

int main()
{
	//vector<int> nums = { 0, 2, 1 };
	vector<vector<int>> nums = { { 1, 2, 3 }, {4,5,6} };
	Solution566 s;
	auto ret = s.matrixReshape(nums, 3, 2);
	cout << endl;
	system("pause");
	return 0;
}
