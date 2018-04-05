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



// ���Ի���������״������һ�µ�һ������֮�󾭹��ľ��룬�Ϳ��Է��ֹ���
// �ο����ӣ�http://www.cnblogs.com/grandyang/p/4137302.html
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode *fast = head, *slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				break;
		}
		if (fast == NULL || fast->next == NULL)
			return NULL;
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
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
	auto ret = s.hasCycle(detectCycle);
	cout << endl;
	system("pause");
	return 0;
}