#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// 使用了Boyer-Moore Majority Vote algorithm算法的变形
// 找出数目最多的元素，使用2次轮询即可完成
class Solution229 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> ret;
		if (nums.empty())
			return ret;
		int cnt1 = 0, cnt2 = 0;
		int num1 = nums[0], num2 = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == num1)
				cnt1++;
			else if (nums[i] == num2)
				cnt2++;
			else if (cnt1 == 0)
			{
				num1 = nums[i];
				cnt1 = 1;
			}
			else if (cnt2 == 0)
			{
				num2 = nums[i];
				cnt2 = 1;
			}
			else
			{
				cnt1--;
				cnt2--;
			}
		}

		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == num1)
				cnt1++;
			if (nums[i] == num2)
				cnt2++;
		}
		if (cnt1 > nums.size() / 3)
			ret.push_back( num1 );
		if (cnt2 > nums.size() / 3 && num2 !=  num1)
			ret.push_back( num2 );
		return ret;
	}
};

int main()
{
	Solution229 s;
	vector<int> nums = { 1,1 };
	vector<int> ret = s.majorityElement( nums );
	cout << endl;
	system("pause");
	return 0;
}