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

// http://www.cnblogs.com/TenosDoIt/p/3416938.html
// 思路：先找到后半段，再反转，依次向前半段添加
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;
		ListNode *fast = head, *slow = head, *tail = NULL; 
		while (fast != NULL && fast->next != NULL)
		{
			tail = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		tail->next = NULL;
		reverseList( slow );
		fast = head;
		tail = NULL;
		while (fast != NULL)
		{
			ListNode *tmp = slow->next;
			tail = slow;
			slow->next = fast->next;
			fast->next = slow;
			fast = slow->next;
			slow = tmp;
			
		}
		if ( slow != NULL )
			tail->next = slow;
	}


	// 翻转链表
	void reverseList(ListNode* &head)
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode *pre = head, *curr = head->next;
		ListNode *tmp;
		while (curr != NULL)
		{
			tmp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = tmp;
		}
		head->next = NULL;
		head = pre;
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
	s.reorderList(node);
	cout << endl;
	system("pause");
	return 0;
}