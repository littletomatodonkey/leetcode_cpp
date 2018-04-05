#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;
		RandomListNode *pold = head, *result = NULL, *poldNext = NULL;
		// 插入新节点
		do
		{
			poldNext = pold->next;
			pold->next = new RandomListNode(pold->label);
			pold->next->next = poldNext;

			pold = poldNext;
		} while (pold != NULL);
		pold = head;
		RandomListNode *pnew = head->next, *pnewNext = NULL;
		result = pnew;
		// 赋值random节点
		do
		{
			if (pold->random == NULL)
				pnew->random = NULL;
			else
				pnew->random = pold->random->next;
			if (pnew->next == NULL)
				break;
			
			pold = pold->next->next;
			pnew = pnew->next->next;

		} while (pnew != NULL);
		
		pold = head;
		pnew = head->next;
		// 提取出旧链表与新链表
		do
		{
			pold->next = pold->next->next;

			if (pnew->next == NULL)
				break;

			pnew->next = pnew->next->next;

			pold = pold->next;
			pnew = pnew->next;
		} while (pold != NULL);

		return result;
	}
};

int main()
{
	vector<int> nums = { -2, 5, -1 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	RandomListNode *head = new RandomListNode(5);
	head->next = new RandomListNode(4);
	head->next->random = head;
	auto ret = s.copyRandomList(head);
	cout << endl;
	system("pause");
	return 0;
}