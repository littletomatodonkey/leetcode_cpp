#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 分偶数和奇数进行讨论
// 偶数等于他除以2的1的个数，奇数等于他除以2的1个个数+1
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; i++)
		{
			if ((i >> 1) << 1 == i)
				ret[i] = ret[i >> 1];
			else
				ret[i] = ret[i >> 1] + 1;
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1, 2, 5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.countBits(5);
	cout << endl;
	system("pause");
	return 0;
}