#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution216 {
public:
	void dfs(int k, int n, vector<vector<int>>& ret, vector<int>& now, int nowSum)
	{
		if (nowSum > n)
			return;
		if (now.size() == k)
		{
			if (nowSum == n)
				ret.push_back(now);
			return;
		}
		int start = 0;
		if (now.size() != 0)
			start = now[now.size() - 1];
		for (int i = start + 1; i < 10; i++)
		{
			now.push_back( i );
			dfs( k, n, ret, now, nowSum+i);
			now.pop_back();
		}
		
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		if (n < k*(k + 1) / 2)
			return ret;
		vector<int> now;
		dfs( k, n, ret, now, 0 );
		return ret;
	}
};

int main()
{
	Solution216 s;
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<vector<int>> ret = s.combinationSum3(3, 9);
	cout << endl;
	system("pause");
	return 0;
}