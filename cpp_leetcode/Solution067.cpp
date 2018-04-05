#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int lena = a.size();
		int lenb = b.size();
		bool last = 0;
		int index = max(lena, lenb);
		string ret( index+1, 0 );
		lena--;
		lenb--;
		while (lena >= 0 && lenb >= 0)
		{
			ret[index] = (a[lena] & 0x01) + (b[lenb] & 0x01) + last;
			if (ret[index] >= 2)
			{
				last = 1;
				ret[index] = ret[index] & 0x01;
			}
			else
			{
				last = 0;
			}
			ret[index] = ret[index] | 0x30;
			lena--;
			lenb--;
			index--;
		}
		while (lena >= 0)
		{
			ret[index] = (a[lena] & 0x01) + last;
			if (ret[index] >= 2)
			{
				last = 1;
				ret[index] = ret[index] & 0x01;
			}
			else
			{
				last = 0;
			}
			ret[index] = ret[index] | 0x30;
			lena--;
			index--;
		}
		while (lenb >= 0)
		{
			ret[index] = (b[lenb] & 0x01) + last;
			if (ret[index] >= 2)
			{
				last = 1;
				ret[index] = ret[index] & 0x01;
			}
			else
			{
				last = 0;
			}
			ret[index] = ret[index] | 0x30;
			lenb--;
			index--;
		}
		if ( last )
			ret[0] = 0x31;
		if (ret.size() >= 2 && ret[0] == 0)
			return ret.substr(1);
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	auto ret = s.addBinary("1", "110");
	cout << endl;
	system("pause");
	return 0;
}