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

// 首先找到左右的起始节点，然后依次向后查询，最后连接2个list即可
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *node = head, *prev = NULL, *left = NULL, *right = NULL, *lnode = NULL, *rnode = NULL;
		if (node->val < x)
		{
			left = head;
			lnode = head;
			node = node->next;
			while (node != NULL && node->val < x)
			{
				lnode->next = node;
				lnode = lnode->next;
				node = node->next;
			}
		}
		else
		{
			right = head;
			rnode = head;
			node = node->next;
			while (node != NULL && node->val >= x)
			{
				rnode->next = node;
				rnode = rnode->next;
				node = node->next;
			}
		}
		if (node == NULL)
		{
			return left == NULL ? right : left;
		}
		if (node->val >= x)
		{
			right = node;
			rnode = node;
		}
		else
		{
			left = node;
			lnode = node;
		}
		node = node->next;
		while (node != NULL)
		{
			if (node->val >= x)
			{
				rnode->next = node;
				rnode = rnode->next;
			}
			else
			{
				lnode->next = node;
				lnode = lnode->next;
			}
			node = node->next;
		}
		lnode->next = right;
		rnode->next = NULL;

		return left;

	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	ListNode *node = new ListNode(1);
	node->next = new ListNode(4);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(2);
	node->next->next->next->next = new ListNode(5);
	auto ret = s.partition( node, 3 );
	cout << endl;
	system("pause");
	return 0;
}