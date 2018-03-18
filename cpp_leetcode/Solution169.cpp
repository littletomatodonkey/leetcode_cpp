#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

class Solution169 {
public:
	int majorityElement(vector<int>& nums) {
		int cnt = 1;
		int now = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (cnt == 0)
			{
				now = nums[i];
				cnt = 1;
			}
			else
			{
				if (nums[i] == now)
					cnt++;
				else
				{
					cnt--;
				}
			}
		}
		return now;
	}
};

int main()
{
	Solution169 s;
	vector<int> nums = { 1,2,1,2,1,2,1};
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	int ret = s.majorityElement( nums );
	//vector<int> ret;
	cout << endl;
	system("pause");
	return 0;
}