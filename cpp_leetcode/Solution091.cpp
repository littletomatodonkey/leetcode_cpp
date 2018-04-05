#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0)
			return 0;
		if (s.size() == 1)
		{
			return s[0] != '0';
		}
		vector<int> ret(s.size(), 0);
		if (s[0] != '0')
			ret[0] = 1;

		if (s[0] == '0')
			ret[1] = 0;
		else
		{
			if (s[1] == '0')
				ret[1] = (s[0] > '0' && s[0] < '3');
			else
			{
				if (s[1] >= '1')
					ret[1] = 1;
				if ((s[0] == '1') || (s[0] == '2' && s[1] <= '6'))
					ret[1] += 1;
			}
		}
		
		
		for (int i = 2; i < s.size(); i++)
		{
			if (s[i] >= '1')
				ret[i] = ret[i - 1];
			if ( (s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6') )
				ret[i] += ret[i - 2];
		}

		return ret.back();
	}
};


int main()
{
	vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, { 2, 5 } };
	//vector<vector<char>> nums = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.numDecodings("101");
	cout << endl;
	system("pause");
	return 0;
}