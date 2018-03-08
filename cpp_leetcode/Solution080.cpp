#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution080 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();
		int tmp = nums[0];
		int idx = 1;
		int cnt = 1;
		int swap_idx = 1;
		while ( swap_idx < nums.size())
		{
			if (tmp != nums[swap_idx])
			{
				cnt = 1;
				tmp = nums[swap_idx];
			}
			else if (cnt < 2)
			{
				cnt++;
			}
			else
			{
				while ( swap_idx<nums.size() && nums[swap_idx++] == tmp);
				if ( nums[swap_idx-1] == tmp )
					break;
				swap_idx--;
				tmp = nums[swap_idx];
				cnt = 1;
			}
			nums[idx++] = nums[swap_idx++];
		}
		return idx;
	}
};

int main()
{
	Solution080 s;
	vector<int> nums = {1,1,1,2};
	cout << s.removeDuplicates(nums) << endl;;
	system("pause");
	return 0;
}