#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// http://blog.csdn.net/zarlove/article/details/78323469
class Solution714 {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int cash = 0;
		int hold = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			cash = max(cash, hold+prices[i]-fee);
			hold = max( hold, cash-prices[i] );
		}

		return cash;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 5,7,10,3 };
	//vector<vector<int>> nums;

	Solution714 s;
	auto ret = s.maxProfit(nums,3);
	cout << endl;
	system("pause");
	return 0;
}