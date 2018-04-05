#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

// C++11中，unordered_set是按照插入顺序存储的，但是在测试的时候1/6一直不对，因此使用hashmap，value为对应数所在的index
// 这样就可以直接处理了
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string result;
		long long num = (long long)numerator;
		long long den = (long long)denominator;
		if ((num > 0 && den < 0) || (num < 0 && den > 0))
		{
			result.append("-");
		}
		num = abs(num);
		den = abs(den);
		long long now =  num / den;
		result.append(to_string(now));
		now = num % den;
		if (now == 0)
			return result;
		result.push_back( '.' );
		unordered_map<long long, long long> nums;
		while (true)
		{
			if (nums.count(now) == 1)
			{
				long long dist = nums.size() - nums.find(now)->second;
				result.insert(result.size() - dist, "(");
				result.push_back( ')' );
				break;
			}
			nums.insert({ now, nums.size() });
			long long zcnt = 0;
			now = now * 10;
			while (now <= den)
			{
				nums.insert({ now, nums.size() });
				now = now * 10;
				result.append("0");
			}
			result.append( to_string(now / den) );
			now = now % den;
			if (now == 0)
				break;
		}

		return result;
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	int num = 1;// -2147483648LL;
	int den = 6; // -1;
	auto ret = s.fractionToDecimal(num, den);
	cout << endl;
	system("pause");
	return 0;
}