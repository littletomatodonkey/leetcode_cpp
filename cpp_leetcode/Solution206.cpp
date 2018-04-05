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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *prev = head, *curr = head->next;
		ListNode *tmp;
		while (curr != NULL)
		{
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		head->next = NULL;
		head = prev;
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
	node->next->next = new ListNode(5);
	node->next->next->next = new ListNode(3);
	node->next->next->next->next = new ListNode(5);
	auto ret = s.reverseList(node);
	cout << endl;
	system("pause");
	return 0;
}