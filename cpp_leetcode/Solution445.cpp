#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> addTwoNums(vector<int>& nums1, vector<int>& nums2)
	{
		int len1 = nums1.size(), len2 = nums2.size();
		vector<int> ret(len2 + 1, 0);
		int last = 0;
		for (len1--, len2--; len1 >= 0; len1--, len2--)
		{
			ret[len2 + 1] = nums1[len1] + nums2[len2] + last;
			if (ret[len2 + 1] >= 10)
			{
				ret[len2 + 1] -= 10;
				last = 1;
			}
			else
				last = 0;
		}
		for (; len2 >= 0; len2--)
		{
			ret[len2 + 1] = nums2[len2] + last;
			if (ret[len2 + 1] >= 10)
			{
				ret[len2 + 1] -= 10;
				last = 1;
			}
			else
				last = 0;
		}
		if (last == 1)
			ret[0] = 1;
		else
		{
			if (ret.size() >= 2)
				ret.erase(ret.begin());
		}
		return ret;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		vector<int> nums1, nums2;
		while (l1 != NULL)
		{
			nums1.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			nums2.push_back(l2->val);
			l2 = l2->next;
		}
		vector<int> nums;
		if (nums1.size() <= nums2.size())
			nums = addTwoNums(nums1, nums2);
		else
			nums = addTwoNums(nums2, nums1);

		ListNode *ret = new ListNode(nums[0]);
		ListNode *tmp = ret;
		for (int i = 1; i < nums.size(); i++)
		{
			tmp->next = new ListNode(nums[i]);
			tmp = tmp->next;
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	ListNode l1(3);
	l1.next = new ListNode(4);
	ListNode l2(5);
	//l2.next = new ListNode(6);
	auto ret = s.addTwoNumbers(&l1, &l2);
	cout << endl;
	system("pause");
	return 0;
}