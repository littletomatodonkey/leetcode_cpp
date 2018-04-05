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

// 参考链接：http://www.cnblogs.com/grandyang/p/4576240.html
class Solution {
public:
	// 简单的dfs会超过时间限制
	void dfs(string& s, map<char, vector<string>>& maps, vector<string>& curr, vector<vector<string>>& res, int idx)
	{
		if (idx == s.size())
		{
			res.push_back( curr );
			return;
		}
		if (maps.count(s[idx]) == 1)
		{
			for (auto word : maps[s[idx]])
			{
				if (idx+word.size()<= s.size() && s.substr(idx, word.size()) == word)
				{
					curr.push_back( word );
					dfs( s, maps, curr, res, idx+word.size() );
					curr.pop_back();
				}
			}
			
		}
	}

	void dfs2( string& s, unordered_set<string>& dicts, int start, vector<bool>& possible, string& out, vector<string>& res )
	{
		if (start == s.size())
		{
			res.push_back( out.substr(0, out.size()-1) );
			return;
		}
		for (int i = start; i < s.size(); i++)
		{
			auto word = s.substr( start, i-start+1 );
			if (dicts.count(word) == 1 && possible[i + 1])
			{
				out.append(word).append(" ");
				int oldSize = res.size();
				dfs2(s, dicts, i + 1, possible, out, res);
				if (res.size() == oldSize)
					possible[i + 1] = false;
				out.resize(out.size() - word.size() - 1);
			}
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dicts(wordDict.begin(), wordDict.end());

		vector<string> res;
		string out;
		vector<bool> possible(s.size() + 1, true);
		dfs2(s, dicts, 0, possible, out, res);
		return res;

		// 第一种DFS的求解方法
		/*map<char, vector<string>> maps;
		for (auto word : wordDict)
			maps[word[0]].push_back( word );
		vector<vector<string>> res;
		vector<string> curr;
		int index = 0;
		dfs( s, maps, curr, res, 0 );
		vector<string> ret;

		for (int i = 0; i < res.size(); i++)
		{
			string tmp;
			for (int j = 0; j < res[i].size(); j++)
			{
				tmp.insert( tmp.end(), res[i][j].begin(), res[i][j].end() );
				tmp.push_back(' ');
			}
			tmp.pop_back();
			ret.push_back( tmp );
		}
		return ret;*/
	}
};

int main()
{
	vector<int> nums = { 1, 4, 2, 7 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.wordBreak("s", strs);
	cout << endl;
	system("pause");
	return 0;
}