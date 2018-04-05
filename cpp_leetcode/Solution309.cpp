#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 参考链接：http://bookshadow.com/weblog/2015/11/24/leetcode-best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		vector<int> sell( prices.size(), 0); // 第i天卖出，此时最大的收益
		vector<int> buy(prices.size(), 0);   // 第i天买入，此时最大的收益
		int delta = 0;  // price[i]-prices[i-1]
		buy[0] = -prices[0];
		buy[1] = -prices[1];
		sell[1] = prices[1]-prices[0];
		for (int i = 2; i < prices.size(); i++)
		{
			delta = prices[i] - prices[i - 1];
			buy[i] = max( sell[i-2]-prices[i], buy[i-1]-delta );
			sell[i] = max( buy[i-1]+prices[i], sell[i-1]+delta );
		}
		int ret = sell[0];
		for (auto val : sell)
			ret = max( ret, val );

		return ret;
		
	}
};


int main()
{
	vector<int> nums = { 1,4,2,7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, { 2, 5 } };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.maxProfit(nums);
	cout << endl;
	system("pause");
	return 0;
}