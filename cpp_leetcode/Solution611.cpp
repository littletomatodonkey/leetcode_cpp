#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// ������ñ������ķ����Ļ�������һ��test case����TLE������
// �����������ٽ������
class Solution611 {
public:
	int triangleNumber(vector<int>& nums) {
		int ret = 0;
		int len = nums.size();
		std::sort(nums.begin(), nums.end());
		int tmp;
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				tmp = nums[i] + nums[j];
				for (int k = j + 1; k < len; k++)
				{
					if (tmp > nums[k])
						ret++;
					else
						break;
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,2,2,3,4 };
	//vector<vector<int>> nums = { { 1, 2, 3 }, { 4, 5, 6 } };
	Solution611 s;
	auto ret = s.triangleNumber(nums);
	cout << endl;
	system("pause");
	return 0;
}