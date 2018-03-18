#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 参考链接：http://www.cnblogs.com/grandyang/p/4501934.html
// 对这种求最小长度的，可以使用滑动窗口的方法来做，在左右设置两个边界，向右滑动即可。
class Solution209 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;
		int left = 0, right = 0, len = nums.size(), res = len + 1;
		int sum = 0;
		while (right < len)
		{
			while (sum < s && right < len)
			{
				sum += nums[right];
				right++;
			}
			while (sum >= s)
			{
				res = min( res, right-left );
				sum -= nums[left];
				left++;
			}
		}
		return res == len + 1 ? 0 : res;
	}
};

int main()
{
	Solution209 s;
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	cout << s.minSubArrayLen(6, nums) << endl;
	system("pause");
	return 0;
}