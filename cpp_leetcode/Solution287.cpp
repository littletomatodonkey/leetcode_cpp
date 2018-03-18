#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution287 {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, t = 0;
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		while (true) {
			slow = nums[slow];
			t = nums[t];
			if (slow == t) break;
		}
		return slow;
	}
};

int main()
{
	Solution287 s;
	vector<int> nums = { 1, 3,6,5,4,3 };
	//vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	int ret = s.findDuplicate(nums);
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}