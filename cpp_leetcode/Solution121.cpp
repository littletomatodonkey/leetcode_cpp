#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution121 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int localMax = 0;
		int globalMax = 0;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size();i++)
		{
			localMax = prices[i] - minPrice;
			globalMax = max( localMax, globalMax );
			minPrice = min( minPrice, prices[i] );
		}
		return globalMax;
	}
};

int main()
{
	Solution121 s;
	vector<int> nums = { 7, 1, 5, 3, 6, 4 };
	//vector<vector<int>> ret;
	int re = s.maxProfit( nums );
	cout << endl;
	system("pause");
	return 0;
}