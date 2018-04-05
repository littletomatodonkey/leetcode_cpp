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

// 首先记录下两个节点的path，然后再依次比较，得到最开始共同的path
class Solution {
public:
	vector<int> getPath(TreeNode* root, TreeNode* p)
	{
		vector<int> path;
		while (true)
		{
			if (root == NULL)
			{
				path.clear();
				break;
			}
			if (root->val == p->val)
				break;
			else if (root->val > p->val)
			{
				root = root->left;
				path.push_back( 0 );
			}
			else
			{
				root = root->right;
				path.push_back(1);
			}
		}
		return path;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;
		TreeNode *node = root;
		auto pPath = getPath( node, p );
		node = root;
		auto qPath = getPath(node, q);
		int index = 0;
		while (index < pPath.size() && index < qPath.size())
		{
			if (pPath[index] != qPath[index])
				break;
			if (pPath[index] == 0)
				root = root->left;
			else
				root = root->right;
			index++;
		}
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
	TreeNode* p = root.left;
	TreeNode* q = root.right;
	auto ret = s.lowestCommonAncestor(&root, &root, q);
	cout << endl;
	system("pause");
	return 0;
}