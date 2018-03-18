#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution766 {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return true;
		int row = matrix.size(), col = matrix[0].size();
		int nowR = 0, nowC = 0;
		int tmp = 0;
		for (int i = -col + 1; i < row; i++)
		{
			nowR = max( 0, i );
			nowC = max(0, -i);
			if (nowC >= col)
				continue;
			tmp = matrix[nowR][nowC];
			for (int j = 1; j + nowR < row && j + nowC < col; j++)
			{
				if (tmp != matrix[nowR + j][nowC + j])
					return false;
			}
		}
		return true;
	}
};

int main()
{
	//vector<int> nums ;
	vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	Solution766 s;
	auto ret = s.isToeplitzMatrix(nums);
	cout << endl;
	system("pause");
	return 0;
}
