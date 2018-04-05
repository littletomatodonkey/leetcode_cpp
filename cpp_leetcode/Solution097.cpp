#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 使用dfs的方法，有两个case会超时
class Solution {
public:

	bool dfs(string& s1, string& s2, string& s3, int idx1, int idx2)
	{
		if (idx1 == s1.size())
			return s2.substr(idx2) == s3.substr(idx1 + idx2);
		if ( idx2 == s2.size() )
			return s1.substr(idx1) == s3.substr(idx1 + idx2);

		bool ret = false;
		if (s1[idx1] == s3[idx1 + idx2])
			ret = dfs( s1, s2, s3, idx1+1, idx2 );
		if (ret)
			return true;
		if (!ret && s2[idx2] == s3[idx1 + idx2])
			ret = dfs(s1, s2, s3, idx1, idx2+1);
		return ret;
	}

	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<vector<bool>> can(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		can[0][0] = true;
		for (int i = 1; i <= s1.size(); i++)
			can[i][0] = can[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		for (int i = 1; i <= s2.size(); i++)
			can[0][i] = can[0][i - 1] && (s2[i - 1] == s3[i - 1]);
		for (int i = 1; i <= s1.size(); i++)
		{
			for (int j = 1; j <= s2.size(); j++)
			{
				can[i][j] = (can[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (can[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return can.back().back();
	}
};


int main()
{
	vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, { 2, 5 } };
	//vector<vector<char>> nums = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.isInterleave("a", "", "c");
	cout << endl;
	system("pause");
	return 0;
}