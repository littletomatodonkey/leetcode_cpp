#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> left( nums.size() );
		vector<int> right(nums.size());
		vector<int> ret( nums.size() );
		left[0] = nums[0];
		right[right.size() - 1] = nums[right.size() - 1];
		for (int i = 1; i < nums.size(); i++)
			left[i] = left[i - 1] * nums[i];
		for (int i = nums.size() - 2; i >= 0; i--)
			right[i] = right[i + 1] * nums[i];
		ret[0] = right[1];
		ret[nums.size() - 1] = left[ nums.size()-2 ];
		for (int i = 1; i < nums.size() - 1; i++)
		{
			ret[i] = left[i - 1] * right[i + 1];
		}
		return ret;
	}
};

int main()
{

	Solution238 s;
	vector<int> nums = {1,2,3,4};
	//vector<vector<int>> ret;
	vector<int> ret = s.productExceptSelf( nums );
	cout << endl;
	system("pause");
	return 0;
}