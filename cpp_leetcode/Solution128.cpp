#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution128 {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;
		unordered_map<int, bool> umap;
		for (auto val : nums)
			umap[val] = true;
		int len = 0;
		int ret = 0;
		int tmp;
		for (auto val : nums)
		{
			tmp = val + 1;
			len = 1;
			while (umap.count(tmp))
			{
				umap.erase( tmp );
				tmp++;
				len++;
			}

			tmp = val - 1;
			while (umap.count(tmp))
			{
				umap.erase( tmp );
				tmp--;
				len++;
			}
			ret = max( len, ret );
		}
		return ret;
	}
};

int main()
{

	Solution128 s;
	vector<int> nums = { 1, 3, 2 };
	//vector<vector<int>> ret;
	int ret = s.longestConsecutive( nums );
	cout << endl;
	system("pause");
	return 0;
}