#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 使用stack，维护当前的最小节点，如果没有达到ksmallest，就删除这个节点，然后加入它所有右孩子的子节点
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> stacks;
		TreeNode *node = root;
		while (node != NULL)
		{
			stacks.push( node );
			node = node->left;
		}
		while (true)
		{
			TreeNode* p = stacks.top();
			if (k == 1)
				return p->val;
			stacks.pop();
			k--;
			p = p->right;
			while (p != NULL)
			{
				stacks.push( p );
				p = p->left;
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	TreeNode root(4);
	root.left = new TreeNode(2);
	root.right = new TreeNode(5);
	auto ret = s.kthSmallest(&root, 2);
	cout << endl;
	system("pause");
	return 0;
}