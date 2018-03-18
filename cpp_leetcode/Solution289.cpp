#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution289 {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int dir[8][2] = { 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1 };
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		if (n == 0)
			return;
		int nr, nc;
		int tmp = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp = 0;
				for (int k = 0; k < 8; k++)
				{
					nr = i + dir[k][0];
					nc = j + dir[k][1];
					if (nr < 0 || nc < 0 || nr >= m || nc >= n)
						continue;
					tmp += (board[nr][nc] &0x01);
				}

				board[i][j] = (board[i][j] & 0x01) + (tmp << 1);
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp = board[i][j] >> 1;
				if (board[i][j] & 0x01 == 1)
				{
					board[i][j] = (tmp == 2 || tmp == 3);
				}
				else
				{
					board[i][j] = (tmp == 3);
				}
			}
		}
	}
};

int main()
{
	Solution289 s;
	vector<int> nums = { 1, 3, 6, 5, 4, 3 };
	vector<vector<int>> board = { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 1, 1, 0 }, { 0, 1, 1, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } };
	//vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	s.gameOfLife( board );
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}