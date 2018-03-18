#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution643 {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		if (nums.size() < k)
			return 0;
		
		int tmp = 0;
		double wnd = 0;
		for (int i = 0; i < k; i++)
			wnd += ((double)nums[i]) / k;
		double maxAvg = wnd;
		for (int i = k; i < nums.size(); i++)
		{
			wnd += ((double)(nums[i] - nums[i - k])) / k;
			maxAvg = max( wnd, maxAvg );
		}

		return maxAvg;
	}
};


int main()
{
	vector<int> nums = { 1, 12, -5, -6, 50, 3};
	//vector<char> tasks = {};
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution643 s;
	auto ret = s.findMaxAverage(nums, 4);
	cout << endl;
	system("pause");
	return 0;
}