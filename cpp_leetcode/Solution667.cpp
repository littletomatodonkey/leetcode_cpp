#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution667 {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> ret;
		int i = 1;
		int len = n;
		while (i <= len)
		{
			if (k > 0)
				ret.push_back(k-- % 2 ? i++ : len--);
			else ret.push_back(i++);
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 4, 2, 3 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution667 s;
	auto ret = s.constructArray(5,2);
	cout << endl;
	system("pause");
	return 0;
}