#include <vector>
#include <iostream>
using namespace std;

class Solution066 {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret( digits );
		int tmp = 1;
		int jw;
		for (int i = ret.size() - 1; i >= 0; i--)
		{
			jw = (ret[i] + tmp) / 10; // 进位的数
			ret[i] = (ret[i] + tmp) % 10;
			tmp = jw;
		}
		if (tmp >= 1)
		{
			ret.insert( ret.begin(), tmp);
		}
		return ret;
	}
};

int main()
{
	Solution066 s;
	vector<int> src = { 9,9 };
	vector<int> ret = s.plusOne( src );
	system("pause");
}