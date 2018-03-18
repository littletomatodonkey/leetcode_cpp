#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class MyCalendarTwo {
public:
	MyCalendarTwo() {

	}

	bool book(int start, int end) {
		for (auto v : info2)
		{
			if (start >= v.second || end <= v.first)
				continue;
			return false;
		}
		for (auto v : info1)
		{
			if (start >= v.second || end <= v.first)
				continue;
			info2.insert({ max(start, v.first), min(end, v.second) });
		}
		info1.insert({ start, end });
		return true;
	}

private:
	set<pair<int, int>> info1, info2;
};

int main()
{
	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	//vector<vector<int>> nums;
	MyCalendarTwo cal;
	cal.book(10, 20);
	cal.book(15, 25);
	cal.book(25, 30);
	cal.book(21, 25);
	//Solution746 s;
	//auto ret = s.minCostClimbingStairs(nums);
	cout << endl;
	system("pause");
	return 0;
}