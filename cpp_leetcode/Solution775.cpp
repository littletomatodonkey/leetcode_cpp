#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution775 {
public:
	bool isIdealPermutation(vector<int>& A) {
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == i)
				continue;
			if (A[i] != i)
			{
				if (A[i] == i + 1 && A[i + 1] == i)
					i++;
				else
					return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<int> nums = { 1, 2,0};
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	Solution775 s;
	auto ret = s.isIdealPermutation(nums);
	cout << endl;
	system("pause");
	return 0;
}