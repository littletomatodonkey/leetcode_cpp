#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 三维动态规划问题，但是可以用递归的思路来解决
// 参考链接：http://blog.unieagle.net/2012/10/23/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Ascramble-string%EF%BC%8C%E4%B8%89%E7%BB%B4%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/
class Solution087 {
public:

	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		string ts1 = s1, ts2 = s2;
		std::sort( ts1.begin(), ts1.end() );
		std::sort( ts2.begin(), ts2.end() );
		if (ts1 != ts2)
			return false;
		string s11, s12, s21, s22;
		for (int i = 1; i < s1.size(); i++)
		{
			s11 = s1.substr(0, i);
			s12 = s1.substr(i);

			s21 = s2.substr(0, i);
			s22 = s2.substr(i);
			if (isScramble(s11, s21) && isScramble(s12, s22))
				return true;

			s21 = s2.substr( s1.size()-i );
			s22 = s2.substr(0, s1.size() - i);
			if (isScramble(s11, s21) && isScramble(s12, s22))
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums = { 2, 1, 3, 1, 4, 20 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};

	Solution087 s;
	auto ret = s.isScramble("great", "rgeat");
	cout << endl;
	system("pause");
	return 0;
}