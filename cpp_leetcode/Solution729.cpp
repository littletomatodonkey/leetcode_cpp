#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class MyCalendar {
public:
	MyCalendar() {
		
	}
	bool book(int start, int end) {
		if (infos.count(start) == 1)
			return false;
		bool ret = true;
		if (infos.empty())
		{
			ret = true;
		}
		else
		{
			if (infos.begin()->first > start)
			{
				ret = infos.begin()->first >= end;
			}
			else if ((--infos.end())->first < start)
				ret = (--infos.end())->second <= start;
			else
			{
				auto it = infos.begin();
				it++;
				while (it->first < start)
					it++;
				auto tmp = it;
				tmp--;
				ret = tmp->second <= start && it->first >= end;
			}
		}
		
		if (ret)
			infos[start] = end;
		return ret;
	}

private:
	map<int, int> infos;
};

int main()
{
	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	//vector<vector<int>> nums;
	MyCalendar cal;
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