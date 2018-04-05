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

	void bfs(vector<vector<int>>& ret, TreeNode *root, int height)
	{
		if (root == NULL)
			return;
		if (height >= ret.size())
		{
			ret.push_back(vector<int>(1, root->val));
		}
		else
			ret[height].push_back( root->val );
		bfs(ret, root->left, height+1);
		bfs(ret, root->right, height + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		bfs( ret, root, 0 );
		std::reverse( ret.begin(), ret.end() );
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
	root.right = new TreeNode(4);
	//l2.next = new ListNode(6);
	auto ret = s.levelOrderBottom(&root);
	cout << endl;
	system("pause");
	return 0;
}