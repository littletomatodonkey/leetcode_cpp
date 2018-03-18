#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution795 {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int ret = 0, head = 0, tail = 0;
		for (auto &val : A)
		{
			if (val <= R && val >= L)
			{
				head += tail + 1;
				ret += head;
				tail = 0;
			}
			else if (val > R)
			{
				tail = 0;
				head = 0;
			}
			else
			{
				tail++;
				ret += head;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = {2,1,3,1};// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	Solution795 s;
	auto ret = s.numSubarrayBoundedMax(nums, 2, 3);
	cout << endl;
	system("pause");
	return 0;
}