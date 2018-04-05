#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// ²Î¿¼Á´½Ó£ºhttps://segmentfault.com/a/1190000003709497
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		int maxLen = 0;
		
		for (int i = 0; i < rows; i++)
		{
			dp[i][0] = matrix[i][0] - '0';
			maxLen = max(maxLen, dp[i][0]);
		}
		for (int i = 0; i < cols; i++)
		{
			dp[0][i] = matrix[0][i] - '0';
			maxLen = max(maxLen, dp[0][i]);
		}

		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < cols; j++)
			{
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else
				{
					dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
					maxLen = max( maxLen, dp[i][j] );
				}
					
			}
		}
		return maxLen*maxLen;

	}
};

int main()
{
	//vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, { 2, 5 } };
	vector<vector<char>> nums = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.maximalSquare(nums);
	cout << endl;
	system("pause");
	return 0;
}