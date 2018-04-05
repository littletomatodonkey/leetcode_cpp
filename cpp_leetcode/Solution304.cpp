#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty())
			return;
		sum = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1,0));
		for (int i = 1; i < sum.size(); i++)
		{
			for (int j = 1; j < sum[0].size(); j++)
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i-1][j-1];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (sum.empty() || sum[0].empty())
			return 0;
		return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
	}

private:
	vector<vector<int>> sum;
};

int main()
{
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	//vector<string> ss = { "a", "b" };
	//auto ret = s.lengthOfLIS(nums);
	cout << endl;
	system("pause");
	return 0;
}