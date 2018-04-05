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
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_map<char, vector<string>> maps;
		string tmp;
		for (auto word : wordDict)
			maps[word[0]].push_back( word );
		int index = 0;
		vector<bool> visit( s.size(), false );
		while (index < s.size())
		{
			if (maps.count(s[index]))
			{
				for (auto word : maps[s[index]])
				{
					if (index + word.size() <= s.size() && s.substr(index, word.size()) == word)
					{
						visit[index + word.size() - 1] = true;
					}
				}
			}
			if (!visit[index])
			{
				while (index < s.size() && !visit[index])
					index++;
			}
			index++;
		}
		return visit.back();
	}
};


int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution s;
	vector<string> ss = { "a", "b"};
	auto ret = s.wordBreak("ab", ss);
	cout << endl;
	system("pause");
	return 0;
}