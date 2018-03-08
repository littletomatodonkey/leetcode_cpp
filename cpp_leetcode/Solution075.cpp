#include <vector>
#include <iostream>
using namespace std;

class Solution075 {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int cnt0=0, cnt1=0, cnt2=0;
		for (int i = 0; i < len ; i++)
		{
			cnt0 += ( nums[i] == 0 );
			cnt1 += (nums[i] == 1);
			cnt2 += (nums[i] == 2);
		}
		for (int i = 0; i < cnt0; i++)
			nums[i] = 0;
		for (int i = cnt0; i < cnt0 + cnt1; i++)
			nums[i] = 1;
		for (int i = cnt0 + cnt1; i < len; i++)
			nums[i] = 2;
	}
};


int main()
{
	vector<int> nums = {0, 2, 2, 2, 1, 1, 0};
	Solution075 s;
	s.sortColors(nums);
	system("pause");
	return 0;
}