#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 我的思路是用2个数组存储计算的值，最快的答案中是自下向上的修改triangle的值，将最小值存储在第一行的第一个元素中
class Solution120 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int rows = triangle.size();
		if (rows == 0)
			return 0;
		vector<int> tmp(rows);
		vector<vector<int>> minRes;
		for (int i = 0; i < 2; i++)
			minRes.push_back( tmp );
		bool idxTwo = true; // 判断当前应该对哪个数组进行赋值
		minRes[0][0] = triangle[0][0];
		int lastIdx = 0;
		for (int i = 1; i < rows; i++)
		{
			lastIdx = !idxTwo;
			minRes[idxTwo][0] = minRes[lastIdx][0] + triangle[i][0];
			minRes[idxTwo][i] = minRes[lastIdx][i-1] + triangle[i][i];
			for (int j = 1; j < i; j++)
			{
				minRes[idxTwo][j] = triangle[i][j] + min(minRes[lastIdx][j - 1], minRes[lastIdx][j]);
			}
			idxTwo = !idxTwo;
		}
		idxTwo = !idxTwo;
		int ret = minRes[idxTwo][0];
		for (int i = 1; i < rows; i++)
		{
			if (minRes[idxTwo][i] < ret)
				ret = minRes[idxTwo][i];
		}
		return ret;
	}
};

int main()
{
	Solution120 s;
	vector<vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	cout << s.minimumTotal( triangle ) << endl;
	system("pause");
	return 0;
}