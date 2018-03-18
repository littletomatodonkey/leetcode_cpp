#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution189 {
public:
	void reverse(vector<int>& nums, int left, int right)
	{
		int tmp;
		while (left < right)
		{
			tmp = nums[left];
			nums[left] = nums[right];
			nums[right] = tmp;
			left++;
			right--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		if (k == 0)
			return;
		int tmp = nums[0];
		reverse( nums, 0, nums.size()-k-1 );
		reverse( nums, nums.size()-k, nums.size()-1 );
		reverse( nums, 0, nums.size()-1 );
	}
};

int main()
{
	Solution189 s;
	vector<int> nums = { 1,2,3,4,5,6,7,8 };
	s.rotate( nums, 7 );
	cout << endl;
	system("pause");
	return 0;
}