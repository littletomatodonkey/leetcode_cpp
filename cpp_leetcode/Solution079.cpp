#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 注意：这一题看别人求解里，不使用visit，直接修改board，之后再修改回来，使得运行速度快很多
class Solution079 {
public:
	vector<vector<int>> dir;//;
	vector<vector<bool>> visit;
	bool dfs(vector<vector<char>>& board, string word, int index, int r, int c)
	{
		if (index >= word.length() || index >= board.size()*board[0].size())
			return false;
		if (index == word.length() - 1)
			return board[r][c] == word[index];
		bool ret = false;
		int nr, nc;
		if (board[r][c] == word[index])
		{
			for (int i = 0; i < 4; i++)
			{
				nr = r + dir[i][0];
				nc = c + dir[i][1];
				if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size())
					continue;
				if (!visit[nr][nc])
				{
					visit[nr][nc] = true;
					if (dfs(board, word, index + 1, nr, nc))
						return true;
					visit[nr][nc] = false;
				}
			}
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		if (board.size() == 0 || board[0].size() == 0 || word.length() == 0 )
			return false;
		vector<bool> v( board[0].size() );
		
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				visit.clear();
				for (int i = 0; i < board.size(); i++)
					visit.push_back(v);
				visit[i][j] = true;
				if (dfs(board, word, 0, i, j))
					return true;
			}
		}
		return false;
	}
};


int main()
{
	//vector<vector<char>> board = {
	//						  {'A','B','C','E'},
	//						  {'S','F','C','S'},
	//						  {'A','D','E','E'}
	//							};
	Solution079 s;
	vector<vector<char>> board = { {'a', 'a'}, {'a', 'b'} };
	cout << s.exist( board, "aaba" ) << endl;
	system("pause");
	return 0;
}