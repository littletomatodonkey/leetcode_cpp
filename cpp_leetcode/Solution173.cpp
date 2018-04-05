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

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root != NULL)
		{
			lefts.push( root );
			root = root -> left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !lefts.empty();
	}

	/** @return the next smallest number */
	int next() {
		
		TreeNode* node = lefts.top();
		lefts.pop();
		int ret = node->val;
		node = node->right;
		while (node != NULL)
		{
			lefts.push( node );
			node = node->left;
		}
		return ret;
	}
private:
	stack<TreeNode*> lefts;
};


int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	//Solution s;
	//vector<string> ss = { "a", "b" };
	TreeNode root(5);
	root.left = new TreeNode(4);
	root.right = new TreeNode(2);

	//l2.next = new ListNode(6);
	//auto ret = s.preorderTraversal(&root);
	cout << endl;
	system("pause");
	return 0;
}