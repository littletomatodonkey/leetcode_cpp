#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution495 {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int ret = 0;
		int tmp;
		if (timeSeries.empty())
			return ret;
		for (int i = 0; i < timeSeries.size()-1; i++)
			ret += min(timeSeries[i + 1] - timeSeries[i], duration);
		ret += duration;
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,2 };
	//vector<int> ret;
	Solution495 s;
	int ret = s.findPoisonedDuration( nums, 2 );
	cout << endl;
	system("pause");
	return 0;
}