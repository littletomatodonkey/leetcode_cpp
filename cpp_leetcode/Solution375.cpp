#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// ��άdp������ȷ�����Ϊ1ʱ������Ҫ������money��Ȼ�����жϲ��Ϊ2�ģ����Խ����Ϊ2�����д�ɺܶ����������⡣
// �ο����ӣ�https://blog.csdn.net/yeqiuzs/article/details/52008544
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int k = 1; k < n; k++)
		{
			for (int s = 1; s + k <= n; s++)
			{
				dp[s][s + k] = INT_MAX;
				for (int i = s; i < s + k; i++)
				{
					dp[s][s + k] = min(dp[s][s + k], i + max(dp[s][i - 1], dp[i + 1][s + k]));
				}
			}
		}
		return dp[1][n];
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.getMoneyAmount(4);
	cout << endl;
	system("pause");
	return 0;
}