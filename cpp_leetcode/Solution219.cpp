#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

class Solution219 {
public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_map<int, int> tmp;
			//cout << tmp.count(1);
			for (int i = 0; i < nums.size(); i++)
			{
				if (tmp.count(nums[i]) == 0)
					tmp[nums[i]] = i;
				else
				{
					if (i - tmp[nums[i]] > k)
					{
						tmp[nums[i]] = i;
					}
					else
						return true;
				}
			}
			return false;
		}
};

int main()
{
	Solution219 s;
	vector<int> nums = { 1, 2,1, 3, 5, 4 };
	//vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	int ret = s.containsNearbyDuplicate(nums, 2);
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}