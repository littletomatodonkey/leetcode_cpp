#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution088 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = m + n - 1;
		m--;
		n--;
		while (index >= 0)
		{
			if (m < 0)
			{
				while (index >= 0)
					nums1[index--] = nums2[n--];
			}
			else if (n < 0)
				break;
			else
			{
				if (nums1[m] >= nums2[n])
					nums1[index--] = nums1[m--];
				else
					nums1[index--] = nums2[n--];
			}
		}
	}
};
int main()
{

	Solution088 s;
	vector<int> nums = { 1, 3,5,0,0,0,0,0 };
	vector<int> nums2 = { 2,4,6 };
	//vector<vector<int>> ret;
	s.merge(nums, 3, nums2, 3 );
	cout << endl;
	system("pause");
	return 0;
}
