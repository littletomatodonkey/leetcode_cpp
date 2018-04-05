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

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		
		int last = 0;
		int num = l1->val + l2->val;
		if (num >= 10)
		{
			num -= 10;
			last = 1;
		}
		ListNode *ret = new ListNode(num);
		ListNode *tmp = ret;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL && l2 != NULL)
		{
			num = l1->val + l2->val + last;
			if (num >= 10)
			{
				num -= 10;
				last = 1;
			}
			else
				last = 0;
			tmp->next = new ListNode(num);
			tmp = tmp->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			num = l1->val + last;
			if (num >= 10)
			{
				num -= 10;
				last = 1;
			}
			else
				last = 0;
			tmp->next = new ListNode(num);
			tmp = tmp->next;
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			num = l2->val + last;
			if (num >= 10)
			{
				num -= 10;
				last = 1;
			}
			else
				last = 0;
			tmp->next = new ListNode(num);
			tmp = tmp->next;
			l2 = l2->next;
		}
		if (last == 1)
		{
			tmp->next = new ListNode(last);
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
	ListNode l1(5);
	//l1.next = new ListNode(4);
	ListNode l2(5);
	//l2.next = new ListNode(6);
	auto ret = s.addTwoNumbers(&l1, &l2);
	cout << endl;
	system("pause");
	return 0;
}