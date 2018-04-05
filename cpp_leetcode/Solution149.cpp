#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
	int maxPoints(vector<Point>& points) {
		if (points.size() <= 2)
			return points.size();
		
		int result = 2;
		int ch = 0;
		for (int i = 0; i < points.size(); i++)
		{
			ch = 0;
			map<pair<int, int>, int> pmaps;
			for (int j = 0; j < points.size(); j++)
			{
				if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					++ch;
					if (pmaps.empty())
						pmaps[{0, 0}] = 0;
					continue;
				}
				int dx = points[j].x - points[i].x;
				int dy = points[j].y - points[i].y;
				if (dx == 0)
				{
					pmaps[{0, 1}]++;
					continue;
				}
				int fhx = dx > 0 ? 1 : -1;
				int fhy = dy > 0 ? 1 : -1;
				dx = abs(dx);
				dy = abs(dy);
				int d = dx > dy ? gcd(dx, dy) : gcd(dy, dx);
				pmaps[{dx / d, fhx*fhy*dy / d}]++;
			}
			for (auto it = pmaps.begin(); it != pmaps.end(); it++)
			{
				result = max(result, (*it).second + ch);
			}
		}
		
		return result;
	}

	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	vector<Point> points;
	points.push_back( Point(0,0) );
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));
	auto ret = s.maxPoints(points);
	cout << endl;
	system("pause");
	return 0;
}