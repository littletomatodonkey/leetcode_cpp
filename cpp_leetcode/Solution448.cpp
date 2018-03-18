#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution448 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < nums.size();)
		{
			if (nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;
		}
		int index = nums.size() - 1;
		//while (nums[index] < index + 1)
		//{
		//	if (index == 0)
		//		break;
		//	index--;
		//}
		for (; index >= 0; index--)
		{
			if (nums[index] != index + 1)
				ret.push_back( index+1 );
		}
		return ret;
	}
};



int main()
{
	vector<int> nums = { 1,1,1,1 };
	Solution448 s;
	//int ret;
	vector<int> ret = s.findDisappearedNumbers( nums );
	cout << endl;
	system("pause");
	return 0;
}