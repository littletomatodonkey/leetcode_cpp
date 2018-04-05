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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *tmp;
		ListNode *now = head;
		ListNode *next = head->next;
		while (now != NULL && next != NULL)
		{
			if (now->val == next->val)
			{
				tmp = now;
				while (now != NULL && next != NULL && now->val == next->val)
				{
					now = now->next;
					next = next->next;
				}
				tmp->next = next;
				if (now == NULL || next == NULL)
					break;
				else
				{
					now = next;
					next = now->next;
				}
			}
			else
			{
				now = now->next;
				next = next->next;
			}
		}
		return head;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	ListNode l1(1);
	l1.next = new ListNode(2);
	l1.next->next = new ListNode(3);
	l1.next->next->next = new ListNode(3);
	ListNode l2(5);
	//l2.next = new ListNode(6);
	auto ret = s.deleteDuplicates(&l1);
	cout << endl;
	system("pause");
	return 0;
}