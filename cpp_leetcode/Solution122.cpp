#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// 使用2个下标的flag记录局部极大值和局部极小值的index，然后遇到局部极大值的时候做计算
class Solution122 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int ret = 0;
		int minIdx = 0;
		int maxIdx = 0;
		int index = 1;
		while (index < prices.size()-1)
		{
			if (prices[index] <= prices[index - 1] && prices[index] <= prices[index + 1])
				minIdx = index;
			else if (prices[index] >= prices[index - 1] && prices[index] >= prices[index + 1])
			{
				maxIdx = index;
				if (maxIdx > minIdx)
				{
					ret += (prices[maxIdx] - prices[minIdx]);
					minIdx = index + 1;
					maxIdx = index + 1;
				}
			}
			index++;
		}
		if (prices[prices.size() - 1] > prices[prices.size() - 2] && minIdx != prices.size()-1)
		{
			ret += (prices[prices.size() - 1] - prices[minIdx]);
		}
		return ret;
	}
};




int main()
{
	Solution122 s;
	vector<int> nums = { 7, 1};
	//vector<vector<int>> ret;
	int ret = s.maxProfit( nums );
	cout << endl;
	system("pause");
	return 0;
}