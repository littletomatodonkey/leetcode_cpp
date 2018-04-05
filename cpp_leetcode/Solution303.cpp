#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		data = vector<int>( nums );
		sums = vector<int>( nums.size()+1, 0 );
		for (int i = 1; i < sums.size(); i++)
			sums[i] = data[i - 1] + sums[i-1];
	}

	int sumRange(int i, int j) {
		return sums[j + 1] - sums[i];
	}

private:
	vector<int> data;
	vector<int> sums;
};


int main()
{
	vector<int> nums = { 2, 1, 3, 1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	NumArray s({ -2, 0, 3, -5, 2, -1 });
	
	auto ret = s.sumRange( 0, 2 );
	cout << endl;
	system("pause");
	return 0;
}