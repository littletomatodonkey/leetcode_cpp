#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 还有一种解法，记录所有的val，排序之后重新赋值，但是这样需要额外的空间
class Solution {
public:
	void mergeSort( ListNode* &head )
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *pre = NULL;
		while (fast != NULL && fast->next != NULL)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow;
		pre->next = NULL;
		mergeSort( head );
		mergeSort( fast );
		if (head == NULL)
		{
			head = fast;
			return;
		}
		if (fast == NULL)
			return;
		ListNode *node = head;
		ListNode *prev = NULL;
		ListNode *tmp = NULL;
		while (fast != NULL)
		{
			while (node != NULL && node->val <= fast->val)
			{
				prev = node;
				node = node->next;
			}
			if (node == NULL)
				break;
			tmp = fast->next;
			if (prev == NULL)
			{
				fast->next = node;
				head = fast;
			}
			else
			{
				fast->next = node;
				prev->next = fast;
			}
			prev = fast;
			node = prev->next;
			fast = tmp;
		}
		if (fast != NULL)
			prev->next = fast;
	}

	ListNode* sortList(ListNode* head) {
		mergeSort( head );
		return head;
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	ListNode *node = new ListNode(2);
	node->next = new ListNode(1);
	//node->next->next = new ListNode(5);
	//node->next->next->next = new ListNode(3);
	//node->next->next->next->next = new ListNode(5);
	auto ret = s.sortList(node);
	cout << endl;
	system("pause");
	return 0;
}