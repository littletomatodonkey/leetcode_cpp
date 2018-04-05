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

// 完全二叉树，可以借鉴二分查找的思想，减小时间复杂度
class Solution {
public:
	int getHeight(TreeNode* root)
	{
		int ret = 0;
		while (root != NULL)
		{
			ret++;
			root = root->left;
		}
		return ret;
	}

	int countNodes(TreeNode* root) {
		
		if (root == NULL)
			return 0;
		int ret = 1;
		TreeNode *node = root;
		int left = getHeight( root->left );
		int right = getHeight( root->right );
		if (left == right)
		{
			ret += ( 1 << left ) - 1;
			ret += countNodes( root->right );
		}
		else
		{
			ret += (1 << right) - 1;
			ret += countNodes(root->left);
		}
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
	//root.right = new TreeNode(2);

	auto ret = s.countNodes(&root);
	cout << endl;
	system("pause");
	return 0;
}