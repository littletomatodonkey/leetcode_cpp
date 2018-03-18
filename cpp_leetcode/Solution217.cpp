#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

class Solution217 {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() <= 1)
			return false;
		unordered_set<int> tmp;
		for (int i = 0; i < nums.size(); i++)
		{
			if (tmp.find(nums[i]) != tmp.end())
				return true;
			else
				tmp.insert( nums[i] );
		}
		return false;
	}
};

int main()
{
	Solution217 s;
	vector<int> nums = { 1, 2,3,5,4};
	//vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	int ret = s.containsDuplicate( nums );
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}