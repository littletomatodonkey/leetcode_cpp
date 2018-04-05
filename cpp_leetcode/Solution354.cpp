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
	static bool cmpPair(pair<int, int> a, pair<int, int> b)
	{
		if (a.first != b.first)
			return a.first < b.first;
		else
			return a.second > b.second;
	}
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int ret = 0;

		std::sort( envelopes.begin(), envelopes.end(), cmpPair);
		vector<int> dp;
		for (auto val : envelopes)
		{
			if (dp.empty() || val.second > dp.back())
				dp.push_back( val.second );
			else
			{
				int left = 0, right = dp.size() - 1, mid;
				while (left <= right)
				{
					mid = (left + right) >> 1;
					if (dp[mid] < val.second)
						left = mid + 1;
					else
						right = mid - 1;
				}
				dp[left] = val.second;
			}
		}

		return dp.size();
	}
};

int main()
{
	//vector<int> nums = { 1, 2, 5 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	vector<pair<int, int>> nums = { { 1, 2 }, { 1, 1 }, { 2, 4 }, { 0, 1 }, {2,5} };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.maxEnvelopes(nums);
	cout << endl;
	system("pause");
	return 0;
}