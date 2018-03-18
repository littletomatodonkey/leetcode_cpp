#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution661 {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<int> tmp(M[0].size(), 0 );
		vector<vector<int>> ret( M.size(), tmp );
		int dirs[8][2] = {1,1,1,0,1,-1,0,1,0,-1,-1,1,-1,0,-1,-1 };
		int nr, nc;
		int cnt = 0;
		int tmpSum = 0;
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = 0; j < M[0].size(); j++)
			{
				tmpSum = M[i][j];
				cnt = 1;
				for (int m = 0; m < 8; m++)
				{
					nr = i + dirs[m][0];
					nc = j + dirs[m][1];
					if (nr <0 || nc <0 || nr>=M.size() || nc>=M[0].size())
						continue;
					cnt++;
					tmpSum += M[nr][nc];
				}
				ret[i][j] = tmpSum / cnt;
			}
		}

		return ret;
	}
};

int main()
{
	//vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution661 s;
	auto ret = s.imageSmoother(nums);
	cout << endl;
	system("pause");
	return 0;
}