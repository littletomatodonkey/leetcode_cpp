#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution769 {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int ret = 0;
		int localMax = INT_MIN;
		for (int i = 0; i < arr.size(); i++)
		{
			localMax = max( localMax, arr[i] );
			if (localMax == i)
				ret++;
		}
		return ret;
	}
};


int main()
{
	vector<int> nums = { 1,0,2,4,3 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	Solution769 s;
	auto ret = s.maxChunksToSorted(nums);
	cout << endl;
	system("pause");
	return 0;
}