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

// ²Î¿¼Á´½Ó£ºhttp://www.cnblogs.com/grandyang/p/6103525.html
class Solution {
public:
	bool dfs( int len, int total, int used, unordered_map<int,bool>& m )
	{
		if (m.count(used) == 1)
			return m[used];
		for (int i = 0; i < len; i++)
		{
			int curr = (1 << i);
			if ((curr & used) == 0)
			{
				if (total <= i + 1 || !dfs(len, total - (i + 1), curr | used, m))
				{
					m[used] = true;
					return true;
				}
			}

		}
		m[used] = false;
		return false;
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal)
			return true;
		if (maxChoosableInteger*(maxChoosableInteger + 1) / 2 < desiredTotal)
			return false;
		unordered_map<int, bool> m;
		return dfs( maxChoosableInteger, desiredTotal, 0, m );
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.canIWin(10, 11);
	cout << endl;
	system("pause");
	return 0;
}