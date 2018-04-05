#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 相当于找到一个节点，然后构建左右的子树的可能性
// 参考链接：http://blog.csdn.net/linhuanmars/article/details/24761459
class Solution096 {
public:
	int numTrees(int n) {
		vector<int> dp( n+1, 0 );
		if (n == 0)
			return 1;
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				dp[i] += dp[j] * dp[i - j - 1];
		}

		return dp[n];
	}
};

int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution096 s;
	auto ret = s.numTrees(3);
	cout << endl;
	system("pause");
	return 0;
}