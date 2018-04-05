#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> nums1(26, 0), nums2(26, 0);
		for (int i = 0; i < s.size(); i++)
			nums1[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++)
			nums2[t[i] - 'a']++;

		for (int i = 0; i < nums1.size(); i++)
		{
			if (nums1[i] != nums2[i])
				return false;
		}
		return true;
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	auto ret = s.isAnagram("ab", "ba");
	cout << endl;
	system("pause");
	return 0;
}