#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;


class Solution670 {
public:
	int maximumSwap(int num) {
		vector<int> ret;
		int index = 0;
		while (num != 0)
		{
			ret.push_back(num % 10);
			num /= 10;
		}
		vector<int> sret( ret.begin(), ret.end());
		std::sort( sret.begin(), sret.end() );
		int len = ret.size() - 1;
		int tmp = 0;
		while (len >= 0)
		{
			if (ret[len] == sret[len])
				len--;
			else
			{
				tmp = 0;
				while (tmp < ret.size())
				{
					if (ret[tmp] == sret[len])
					{
						swap( ret[tmp], ret[len] );
						break;
					}
					tmp++;
				}
				break;
			}
		}
		int val = 0;
		for (int i = ret.size() - 1; i >= 0; i--)
			val = val * 10 + ret[i];
		return val;
	}
};

int main()
{
	vector<int> nums = { 4, 2, 3 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution670 s;
	auto ret = s.maximumSwap(991331);
	cout << endl;
	system("pause");
	return 0;
}