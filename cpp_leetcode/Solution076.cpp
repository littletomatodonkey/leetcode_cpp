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

// ²Î¿¼Á´½Ó£ºhttps://segmentfault.com/a/1190000003707313
class Solution {
public:
	string minWindow(string s, string t) {
		int start = 0;
		int begin = 0;
		int end = 0;
		vector<int> tmap(256, 0);
		vector<int> smap(256, 0);
		int length = INT_MAX;
		for (int i = 0; i < t.size(); i++)
			tmap[t[i]]++;;
		int found = 0;
		for (int i = 0; i < s.size(); i++)
		{
			smap[s[i]]++;
			if (smap[s[i]] <= tmap[s[i]])
				found++;
			if (found == t.size())
			{
				while (start < i && smap[s[start]] > tmap[s[start]])
				{
					smap[s[start]]--;
					start++;
				}

				if (i - start < length)
				{
					begin = start;
					end = i;
					length = i - start;
				}

				smap[s[start]]--;
				found--;
				start++;
			}
			
			
		}
		return length == INT_MAX ? "" : s.substr(begin, length+1);
	}
};


int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	auto ret = s.minWindow("aaflslflsldkalskaaa", "aaa");
	cout << endl;
	system("pause");
	return 0;
}