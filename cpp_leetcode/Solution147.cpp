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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *pre = head;
		ListNode *curr = head->next;
		while (curr != NULL)
		{
			ListNode *tmp = curr->next;
			ListNode *insert = head;
			ListNode *innerPre = NULL;
			while ( insert != curr && insert->val <= curr->val)
			{
				innerPre = insert;
				insert = insert->next;
			}
			// 不是末尾，则需要进行链表指针的处理
			if (insert != curr)
			{
				if (innerPre != NULL)
				{
					curr->next = innerPre->next;
					innerPre->next = curr;
					curr->next = insert;
				}
				else
				{
					curr->next = head;
					head = curr;
				}
				pre->next = tmp;
			}
			else
				pre = pre->next;
			curr = tmp;
		}
		
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
	node->next = new ListNode(3);
	node->next->next = new ListNode(1);
	node->next->next->next = new ListNode(1);
	node->next->next->next->next = new ListNode(1);
	auto ret = s.insertionSortList(node);
	cout << endl;
	system("pause");
	return 0;
}