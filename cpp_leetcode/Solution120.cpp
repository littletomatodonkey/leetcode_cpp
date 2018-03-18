#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// �ҵ�˼·����2������洢�����ֵ�����Ĵ������������ϵ��޸�triangle��ֵ������Сֵ�洢�ڵ�һ�еĵ�һ��Ԫ����
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
		bool idxTwo = true; // �жϵ�ǰӦ�ö��ĸ�������и�ֵ
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