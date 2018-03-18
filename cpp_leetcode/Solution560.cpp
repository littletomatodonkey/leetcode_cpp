#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 参考链接：http://www.cnblogs.com/grandyang/p/6810361.html
// 建立一个哈希map，便于查找，记录初始到当前index的和，为sum，如果sum-k的子数组存在，则k的子数组一定存在，
// 每次循环中，都将sum压入map中，并让计数值+1
class Solution560 {
public:
	int subarraySum(vector<int>& nums, int k) {
		int ret = 0;
		int sum = 0;
		unordered_map<int, int> maps{ { 0, 1 } };
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			ret += maps[sum-k];
			++maps[sum];
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,1,1,1 };
	//vector<int> ret;
	Solution560 s;
	int ret = s.subarraySum(nums, 2);
	cout << endl;
	system("pause");
	return 0;
}