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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int index = 0;
		ListNode *result = new ListNode(-1); // 加一个head，防止null的处理
		result->next = head;
		ListNode *prev = result;
		ListNode *node = result;
		ListNode *tmp;
		while (index < m)
		{
			prev = node;
			node = node->next;
			index++;
		}
		while (index < n)
		{
			tmp = prev->next;
			prev->next = node->next;
			node->next = node->next->next;
			prev->next->next = tmp;
			index++;
		}
		tmp = result->next;
		free( result );
		return tmp;
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
	auto ret = s.reverseBetween(node, 1, 5);
	cout << endl;
	system("pause");
	return 0;
}