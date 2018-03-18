#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

// �ο����ӣ�http://www.cnblogs.com/grandyang/p/6810361.html
// ����һ����ϣmap�����ڲ��ң���¼��ʼ����ǰindex�ĺͣ�Ϊsum�����sum-k����������ڣ���k��������һ�����ڣ�
// ÿ��ѭ���У�����sumѹ��map�У����ü���ֵ+1
class Solution560 {
public:
	int subarraySum(vector<int>& nums, int k) {
		int ret = 0;
		int sum = 0;
		unordered_map<int, int> maps{ { 0, 1 } };
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			ret += maps[sum-k];
			++maps[sum];
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,1,1,1 };
	//vector<int> ret;
	Solution560 s;
	int ret = s.subarraySum(nums, 2);
	cout << endl;
	system("pause");
	return 0;
}