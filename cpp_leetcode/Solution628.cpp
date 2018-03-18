#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// ²Î¿¼Á´½Ó£ºhttp://bookshadow.com/weblog/2017/06/25/leetcode-maximum-product-of-three-numbers/
class Solution628 {
public:
	int maximumProduct(vector<int>& nums) {
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}
			else if (nums[i] > max2)
			{
				max3 = max2;
				max2 = nums[i];
			}
			else if (nums[i] > max3)
			{
				max3 = nums[i];
			}
			
			if (nums[i] < min1)
			{
				min2 = min1;
				min1 = nums[i];
			}
			else if (nums[i] < min2)
			{
				min2 = nums[i];
			}
		}
		return max(max1*max2*max3, max1*min1*min2);
	}
};

int main()
{
	vector<int> nums = { 1,2,3 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution628 s;
	auto ret = s.maximumProduct(nums);
	cout << endl;
	system("pause");
	return 0;
}