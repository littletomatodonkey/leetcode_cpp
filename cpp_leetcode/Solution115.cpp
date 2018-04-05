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
	int numDistinct(string s, string t) {
		int slen = s.size();
		int tlen = t.size();
		if (slen < tlen)
			return 0;
		if (tlen == 1)
			return 1;
		vector<vector<int>> dp( slen+1, vector<int>(tlen+1,0) );
		for (int i = 0; i <= slen; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= slen; i++)
		{
			for (int j = 1; j <= tlen; j++)
			{
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp.back().back();
	}
};

int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	vector<string> ss = { "a", "b" };
	auto ret = s.numDistinct("rabbbit", "rabbit");
	cout << endl;
	system("pause");
	return 0;
}