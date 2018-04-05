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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recurse( TreeNode *root )
	{
		if (root == NULL)
			return;
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		recurse( root->left );
		recurse(root->right);
	}

	TreeNode* invertTree(TreeNode* root) {
		recurse(root);
		return root;
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
	auto ret = s.invertTree(&root);
	cout << endl;
	system("pause");
	return 0;
}