#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void bfs(vector<int>& ret, TreeNode* root)
	{
		if (root == NULL)
			return;
		ret.push_back( root->val );
		bfs( ret, root->left );
		bfs( ret, root->right );
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		bfs( ret, root );
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	//vector<string> ss = { "a", "b" };
	TreeNode root(5);
	root.left = new TreeNode(4);
	root.right = new TreeNode(2);
	//l2.next = new ListNode(6);
	auto ret = s.preorderTraversal(&root);
	cout << endl;
	system("pause");
	return 0;
}