#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution713 {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int cnt = 0;
		int multi = 1;
		int lastIdx = 0;
		int tmp;
		for (int i = 0; i < nums.size(); i++)
		{
			cnt += (lastIdx - i);
			while (lastIdx < nums.size() && multi*nums[lastIdx] < k)
			{
				multi = multi*nums[lastIdx];
				lastIdx++;
				cnt++;
			}
			if (lastIdx <= i)
			{
				lastIdx++;
			}
			else
			{
				multi /= nums[i];
			}
		}
		return cnt;
	}
};

int main()
{
	vector<int> nums = { 10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3 };
	//vector<vector<int>> nums;

	Solution713 s;
	auto ret = s.numSubarrayProductLessThanK(nums, 19);
	cout << endl;
	system("pause");
	return 0;
}