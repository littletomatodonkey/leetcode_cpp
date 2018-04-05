#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		int idx = 0;
		for (int i = 1; i <= amount;i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				idx = i - coins[j];
				if (idx >= 0 && dp[idx]!=INT_MAX)
					dp[i] = min( dp[i], dp[idx]+1 );
			}
		}
		return dp.back() == INT_MAX ? -1 : dp.back();
	}
};

int main()
{
	vector<int> nums = { 1,2,5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.coinChange(nums, 11);
	cout << endl;
	system("pause");
	return 0;
}