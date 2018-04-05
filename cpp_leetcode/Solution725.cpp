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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> result;
		int len = genLen( root );
		int number = len / k; // 每个元素至少包括number个节点
		int addone = len % k; // addone个元素包括(number+1)个节点
		int addoneCnt = 0;
		int tmp = 0;
		int index = 0, cnt = 0;
		ListNode *head = root, *curr = root, *tmpNode = NULL;
		while (curr != NULL)
		{
			
			head = curr;
			if (addoneCnt < addone)
				tmp = 0;
			else
				tmp = 1;
			addoneCnt++;
			while (tmp < number)
			{
				tmp++;
				curr = curr->next;
			}
			tmpNode = curr->next;
			curr->next = NULL;
			result.push_back( head );
			curr = tmpNode;
		}
		while (result.size() < k)
		{
			result.push_back( NULL );
		}
		return result;
	}

	// 长度
	int genLen( ListNode* &head )
	{
		int len = 0;
		ListNode *curr = head;
		while (curr != NULL)
		{
			len++;
			curr = curr->next;
		}
		return len;
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
	auto ret = s.splitListToParts(node, 1);
	cout << endl;
	system("pause");
	return 0;
}