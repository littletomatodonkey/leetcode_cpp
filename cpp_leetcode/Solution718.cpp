#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution718 {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int ret = 0;
		vector<vector<int>> dp( A.size()+1, vector<int>(B.size()+1, 0) );
		for (int i = 1; i <= A.size(); i++)
		{
			for (int j = 1; j <= B.size(); j++)
			{
				dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
				ret = max( ret, dp[i][j] );
			}
		}
		return ret;
	}
};


int main()
{
	vector<int> nums = { 1, 1, 0 };
	//vector<vector<int>> nums;

	Solution718 s;
	auto ret = s.findLength(nums, nums);
	cout << endl;
	system("pause");
	return 0;
}