#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// 参考链接：https://leetcode.com/problems/task-scheduler/discuss/104496/concise-java-solution-on-time-o26-space
// 依次插入频率从高到低的字母
class Solution621 {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> nums(26, 0);
		for (int i = 0; i < tasks.size(); i++)
			nums[tasks[i] - 'A']++;
		std::sort( nums.begin(), nums.end() );
		int index = 25;
		while (index >= 0 && nums[index] == nums[25])
			index--;
		return max( (int)tasks.size(), (nums[25]-1)*(n+1)+25-index);

	}
};


int main()
{
	//vector<int> nums = { 1, 2, 2, 3, 4 };
	vector<char> tasks =  { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' }; //{'A', 'A', 'B', 'B', 'C', 'C'};
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution621 s;
	auto ret = s.leastInterval(tasks, 2);
	cout << endl;
	system("pause");
	return 0;
}