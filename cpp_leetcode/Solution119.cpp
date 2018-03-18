#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution119 {
public:
	vector<int> getRow(int rowIndex) {
		rowIndex++;
		if (rowIndex == 1)
			return { 1 };
		if (rowIndex == 2)
			return { 1, 1 };
		vector<int> ret(rowIndex);
		ret[0] = 1;
		ret[1] = 1;
		for (int i = 2; i < rowIndex;i++)
		{
			for (int j = i / 2; j >= 1; j--)
				ret[j] += ret[j - 1];
			for (int j = i/2+1; j <= i; j++)
				ret[j] = ret[i - j];
		}
		return ret;
	}

};

int main()
{
	Solution119 s;
	vector<int> ret = s.getRow( 3 );
	cout << endl;
	system("pause");
	return 0;
}