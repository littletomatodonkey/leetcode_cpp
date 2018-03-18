#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution746 {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size()+1, 0);
		for (int i = 2; i < dp.size(); i++)
		{
			dp[i] = min( dp[i-2]+cost[i-2], dp[i-1]+cost[i-1] );
		}
		return dp.back();
	}
};

int main()
{
	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	//vector<vector<int>> nums;

	Solution746 s;
	auto ret = s.minCostClimbingStairs(nums);
	cout << endl;
	system("pause");
	return 0;
}