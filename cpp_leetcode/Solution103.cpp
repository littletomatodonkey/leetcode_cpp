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
	void bfs(vector<vector<int>>& ret, TreeNode* root, int level)
	{
		if (root == NULL)
			return;
		if (level >= ret.size())
			ret.push_back(vector<int>(1, root->val));
		else
			ret[level].push_back( root->val );
		bfs( ret, root->left, level+1 );
		bfs(ret, root->right, level + 1);
	}


	vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int>> ret;
		bfs( ret, root, 0 );
		for (int i = 1; i < ret.size(); i += 2)
			std::reverse( ret[i].begin(), ret[i].end() );

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
	auto ret = s.zigzagLevelOrder(&root);
	cout << endl;
	system("pause");
	return 0;
}