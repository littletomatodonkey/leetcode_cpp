#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution717 {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int len = bits.size();
		int index = 0;
		while (index < len)
		{
			while (index < len && bits[index] == 0)
				index++;
			if (index == len)
				return true;
			if (bits[index] == 1)
				index += 2;
		}
		return false;
	}
};

int main()
{
	vector<int> nums = { 1, 1,0 };
	//vector<vector<int>> nums;

	Solution717 s;
	auto ret = s.isOneBitCharacter(nums);
	cout << endl;
	system("pause");
	return 0;
}