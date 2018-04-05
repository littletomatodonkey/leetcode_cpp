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
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *oddPrev = head, *evenPrev = head->next, *curr = head->next->next;
		ListNode *tmp = NULL;
		while (curr != NULL)
		{
			// 只有一个oddValue需要插入
			if (curr->next == NULL)
			{
				curr->next = oddPrev->next;
				oddPrev->next = curr;
				evenPrev->next = NULL;
				break;
			}
			// odd与even均存在
			else
			{
				tmp = curr->next;
				curr->next = oddPrev->next;
				oddPrev->next = curr;
				oddPrev = curr;

				curr = tmp;
				tmp = curr->next;
				curr->next = evenPrev->next;
				evenPrev->next = curr;
				evenPrev = curr;
				curr = tmp;
			}
		}
		evenPrev->next = NULL;
		return head;
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
	//node->next->next->next->next->next = new ListNode(6);
	auto ret = s.oddEvenList(node);
	cout << endl;
	system("pause");
	return 0;
}