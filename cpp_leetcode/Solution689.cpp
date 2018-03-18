#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution689 {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int len = nums.size();
		int maxVal = INT_MIN;
		vector<int> sums;
		vector<int> ret;
		for (auto num : nums)
		{
			if (!sums.empty())
				sums.push_back(sums.back() + num);
			else
				sums.push_back( num );
		}
			
		vector<int> left(len, 0);
		vector<int> right(len, len - k);
		int total = sums[k-1];
		int tmp = 0;
		for (int i = k; i < len; i++)
		{
			tmp = sums[i] - sums[i-k];
			if (tmp > total)
			{
				left[i] = i - k + 1;
				total = tmp;
			}
			else
				left[i] = left[i - 1];
		}

		total = sums[len - 1] - sums[len - 1 - k];
		for (int i = len - k - 1; i > 0; i--)
		{
			tmp = sums[i + k-1] - sums[i-1];
			if ( tmp >= total)
			{
				right[i] = i;
				total = tmp;
			}
			else
			{
				right[i] = right[i+1];
			}
		}

		int l = left[k - 1], r = right[2*k];
		maxVal = (sums[2*k - 1] - sums[k - 1]) + (sums[l + k - 1]) + (sums[r + k - 1] - sums[r - 1]);
		ret = {l, k, r};
		int lsum = 0;
		int rsum = 0;
		for (int i = k+1; i < len + 1 - 2 * k; i++)
		{
			l = left[i - 1], r = right[k+i];
			if (l == 0)
				lsum = sums[l + k - 1];
			else
				lsum = sums[l + k - 1] - sums[l - 1];


			rsum = sums[r + k - 1] - sums[r - 1];
			total = (sums[k + i - 1] - sums[i - 1]) + lsum + rsum;
			if (total > maxVal)
			{
				maxVal = total;
				ret = {l, i, r};
			}
		}

		return ret;
	}
};

int main()
{
	vector<int> nums = { 17, 7, 19, 11, 1, 19, 17, 6, 13, 18, 2, 7, 12, 16, 16, 18, 9, 3, 19, 5 };
	//vector<vector<int>> nums;
	
	Solution689 s;
	auto ret = s.maxSumOfThreeSubarrays(nums, 6);
	cout << endl;
	system("pause");
	return 0;
}