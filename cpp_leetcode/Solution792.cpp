#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 参考链接：http://bookshadow.com/weblog/2018/03/04/leetcode-number-of-matching-subsequences/
// 直接包里搜索TLE，上述链接会出现MLE的问题(内存溢出)
// 最终代码来自于：https://github.com/kamyu104/LeetCode/blob/master/C++/number-of-matching-subsequences.cpp
class Solution792 {
public:
	int numMatchingSubseq(string S, vector<string>& words) {
		unordered_map<char, vector<pair<int, int>>> waiting;
		for (int i = 0; i < words.size(); i++)
			waiting[words[i][0]].emplace_back(i,1);

		for (auto& c : S)
		{
			auto advance = move( waiting[c] );
			waiting.erase(c);
			for (const auto& kvp : advance) {
				int i = kvp.first, j = kvp.second;
				int next = (j != words[i].length()) ? words[i][j] : 0;
				waiting[next].emplace_back(i, j + 1);
			}
		}
		return waiting[0].size();
	}

};

int main()
{
	//vector<int> nums = { 1, 2, 0 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	Solution792 s;
	string S("abcde");
	vector<string> words = { "a", "bb", "acd", "ace" };
	auto ret = s.numMatchingSubseq(S, words);
	cout << endl;
	system("pause");
	return 0;
}