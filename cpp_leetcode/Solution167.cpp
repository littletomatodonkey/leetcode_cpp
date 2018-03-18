#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution167 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1;
		int res = numbers[left] + numbers[right];
		while (res != target)
		{
			if (res < target)
				left++;
			else
				right--;
			res = numbers[left] + numbers[right];
		}
		vector<int> ret = {left+1, right+1};
		return ret;
	}
};


int main()
{
	Solution167 s;
	vector<int> nums = { 1,2,3,5 };
	vector<int> ret = s.twoSum(nums, 5);
	cout << endl;
	system("pause");
	return 0;
}