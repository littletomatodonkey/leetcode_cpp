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
	int integerBreak(int n) {
		if (n <= 3)
			return n - 1;
		int ret = 1;
		while (n - 3 >= 2)
		{
			ret *= 3;
			n -= 3;
		}
		ret *= n;
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.integerBreak(10);
	cout << endl;
	system("pause");
	return 0;
}