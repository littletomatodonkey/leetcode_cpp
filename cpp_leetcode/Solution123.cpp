#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution123 {
public:
	// 这种方法虽然可以求解，但是时间复杂度太大，参考
	// http://blog.csdn.net/fightforyourdream/article/details/14503469
	// 使用dp进行求解，可以在O(N)的复杂度内进行求解。
	int dfs(vector<int>& prices, int status, int currIndex)
	{
		int currProfit = 0;
		if (status > 4 || currIndex >= prices.size())
			return 0;

		if (status == 1 || status == 3)
			currProfit = -prices[currIndex];
		else if (status == 2 || status == 4)
			currProfit = prices[currIndex];
		
		int maxV = dfs(prices, status, currIndex + 1);
		int tmp;
		for (int i = currIndex; i < prices.size(); i++)
		{
			tmp = currProfit + dfs(prices, status + 1, i);
			if (tmp > maxV)
				maxV = tmp;
		}
		return maxV;
	}

	void process(vector<int>& prices, vector<int>& left, vector<int>& right)
	{
		left[0] = 0;
		int minV = prices[0];
		// 首先求出从开始到第k天交易的最大值
		for (int i = 1; i < prices.size(); i++)
		{
			left[i] = max( left[i-1], prices[i] - minV );
			minV = min( minV, prices[i] );
		}

		right[right.size() - 1] = 0;
		int maxV = prices[prices.size() - 1];
		for (int i = prices.size() - 2; i >= 0; i--)
		{
			right[i] = max( right[i+1], maxV - prices[i] );
			maxV = max( maxV, prices[i] );
		}
	}

	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		//return dfs( prices, 0, 0 );
		vector<int> left( prices.size() );
		vector<int> right(prices.size());

		process( prices, left, right );

		int ret = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			ret = max( ret, left[i]+right[i] );
		}
		return ret;
	}
};

int main()
{
	Solution123 s;
	vector<int> prices = {2,1,2,0,1};
	cout << s.maxProfit( prices ) << endl;
	system("pause");
	return 0;
}