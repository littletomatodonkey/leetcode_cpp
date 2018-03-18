#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;


class Solution695 {
public:
	int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int m, int n)
	{
		int dirs[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
		if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] == 0 || visit[m][n])
			return 0;
		visit[m][n] = true;
		int ret = 1;
		for (int i = 0; i < 4; i++)
		{
			ret += dfs( grid, visit, m+dirs[i][0], n+dirs[i][1] );
		}
		return ret;
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<bool> tmp(grid[0].size(), false);
		vector<vector<bool>> visit(grid.size(), tmp);
		int globlaMax = 0;
		int thisMax = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if ( grid[i][j] == 1 && !visit[i][j] )
				{
					globlaMax = max(globlaMax, dfs(grid, visit, i, j));
				}
			}
		}
		return globlaMax;
	}
};

int main()
{
	//vector<int> nums = { 2, 2, 3 };
	vector<vector<int>> nums = {{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
								{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
								{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
								{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
								{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }};
	Solution695 s;
	auto ret = s.maxAreaOfIsland(nums);
	cout << endl;
	system("pause");
	return 0;
}