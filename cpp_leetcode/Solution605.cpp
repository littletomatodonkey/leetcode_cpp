#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution605 {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int index = 0;
		for (int i = 0; i < flowerbed.size();)
		{
			if (flowerbed[i] == 1)
			{
				i += 2;
				continue;
			}
			if (i + 1 < flowerbed.size())
			{
				if (flowerbed[i + 1] == 0)
				{
					n--;
					i += 2;
				}
				else
					i += 3;
			}
			else if (flowerbed[i] == 0)
			{
				n--;
				i++;
			}
				
			if (n <= 0)
				return true;
		}
		return n <= 0;
	}
};

int main()
{
	vector<int> nums = { 0, 0,0,0 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution605 s;
	auto ret = s.canPlaceFlowers(nums, 4);
	cout << endl;
	system("pause");
	return 0;
}