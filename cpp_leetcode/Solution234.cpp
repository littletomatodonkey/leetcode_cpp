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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode *prev = NULL, *slow = head, *fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		fast = prev->next;
		prev->next = NULL;
		slow = head;
		reverseList( fast );
		while (slow != NULL && fast != NULL)
		{
			if (slow->val != fast->val)
				return false;
			slow = slow->next;
			fast = fast->next;
		}
		return true;
	}

	void reverseList(ListNode* &head) {
		if (head == NULL || head->next == NULL)
			return;
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
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(2);
	node->next->next->next->next = new ListNode(2);
	auto ret = s.isPalindrome(node);
	cout << endl;
	system("pause");
	return 0;
}