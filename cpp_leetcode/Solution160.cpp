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

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		int oldLenB = getLen( headB );
		ReverseList( headA );
		ListNode *tmp = headB, *prevB = NULL;
		int newLenB = 0;
		while (tmp != NULL)
		{
			newLenB++;
			prevB = tmp;
			tmp = tmp->next;
		}
		ReverseList(headA);
		if (prevB != headA)
			return NULL;
		int lenA = getLen( headA );
		int lenS = (lenA - 1 - oldLenB + newLenB) >> 1;
		auto curr = headA;
		while (lenS > 0)
		{
			lenS--;
			curr = curr->next;
		}

		return curr;
	}

	void ReverseList( ListNode* &head )
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode *tmp, *prev = head, *curr = head->next;
		while (curr != NULL)
		{
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		head->next = NULL;
		head = prev;
	}

	int getLen(ListNode* &head)
	{
		int len = 0;
		auto node = head;
		while (node != NULL)
		{
			len++;
			node = node->next;
		}
		return len;
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	ListNode *node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(4);
	node->next->next->next->next = new ListNode(5);
	ListNode *node2 = new ListNode(10);
	node2->next = node->next->next;
	auto ret = s.getIntersectionNode(node, node2);
	cout << endl;
	system("pause");
	return 0;
}