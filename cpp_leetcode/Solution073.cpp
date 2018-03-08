#include <vector>
#include <iostream>
using namespace std;

class Solution073 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> zero_r, zero_c;
		vector<bool> vr(row), vc(col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (matrix[i][j] == 0)
				{
					zero_r.insert( zero_r.end(), i );
					zero_c.insert(zero_c.end(), j);
				}
		for (int i = 0; i < zero_r.size(); i++)
		{
			if (matrix[zero_r[i]][zero_c[i]] == 0)
			{
				if (!vr[zero_r[i]])
				{
					vr[zero_r[i]] = true;
					for (int k = 0; k < col; k++)
						matrix[zero_r[i]][k] = 0;
				}
				if (!vc[zero_c[i]])
				{
					vc[zero_c[i]] = true;
					for (int k = 0; k < row; k++)
						matrix[k][zero_c[i]] = 0;
				}
			}
		}
	}
};

int main()
{

	vector<int> v1 = { 5, 2, 0, 3, 6, 7,2 };
	vector<int> v2 = { 0, 1 };
	vector<vector<int>> matrix = { { 1 }, { 2 }, { 3 }, {0} }; // [[5], [2], [0], [3], [6], [7], [2]]; // {v1, v2};
	Solution073 s;
	s.setZeroes( matrix );


	system("pause");
	return 0;
}