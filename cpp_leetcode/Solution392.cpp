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
	bool isSubsequence(string s, string t) {
		if (s.empty() || s == t)
			return true;
		vector<bool> pre( t.size()+1, true );
		vector<bool> now(t.size() + 1, false);
		pre[0] = true;
		bool last = false;
		for (int i = 1; i <= s.size(); i++)
		{
			now[i - 1] = false;
			for (int j = i; j <= t.size(); j++)
			{
				now[j] = now[j - 1] || (pre[j - 1] && s[i - 1] == t[j - 1]);
			}
			pre = now;
		}
		return now.back();
	}
};

int main()
{
	vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.isSubsequence("abc", "ahbgdc");
	cout << endl;
	system("pause");
	return 0;
}