#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int num = 9, multi = 9;
		n = min(n, 10);
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		if (n >= 1)
			dp[1] = 10;
		for (int i = 2; i <= n; i++)
		{
			num = 11 - i;
			multi *= num;
			dp[i] = dp[i - 1] + multi;
		}
		return dp.back();
	}
};

int main()
{
	vector<int> nums = { 1, 2, 5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.countNumbersWithUniqueDigits(3);
	cout << endl;
	system("pause");
	return 0;
}