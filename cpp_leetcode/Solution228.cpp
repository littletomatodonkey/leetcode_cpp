#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution228 {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		if (nums.empty())
			return ret;
		int startIdx = 0;
		int endIdx = 0;
		int index = 0;
		string s;
		stringstream ss;
		while (index < nums.size()-1)
		{
			if (nums[index + 1] - nums[index] == 1)
				endIdx = index + 1;
			else
			{
				ss.clear();
				ss << nums[startIdx];
				if (endIdx != startIdx)
				{
					ss << "->" << nums[endIdx];
				}
				ss >> s;
				ret.push_back( s );
				startIdx = index + 1;
				endIdx = index + 1;
			}
			index++;
		}
		ss.clear();
		ss << nums[startIdx];
		if (endIdx != startIdx)
		{
			ss << "->" << nums[endIdx];
		}
		ss >> s;
		ret.push_back(s);
		return ret;
	}
};

int main()
{
	Solution228 s;
	vector<int> nums = { 0,4,6,8,10,11,12 };
	vector<string> ret = s.summaryRanges( nums );
	cout << endl;
	system("pause");
	return 0;
}