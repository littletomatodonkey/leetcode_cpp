#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution118 {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		if (numRows <= 0)
			return ret;
		vector<int> now = {1};
		ret.push_back( now );
		for (int i = 1; i < numRows; i++)
		{
			now.push_back( now[0] );
			for (int j = 1; j < i; j++)
				now[j] = ret[i - 1][j - 1] + ret[i - 1][j];
			ret.push_back( now );
		}
		return ret;
	}
};


int main()
{
	Solution118 s;
	vector<int> nums = { 1, 2, 2 };
	vector<vector<int>> ret = s.generate(3);
	cout << endl;
	system("pause");
	return 0;
}