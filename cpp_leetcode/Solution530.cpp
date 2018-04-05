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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> nums;
	void dfs(TreeNode* root)
	{
		if (root == NULL)
			return;
		dfs(root->left);
		nums.push_back(root->val);
		dfs(root->right);
	}

	int getMinimumDifference(TreeNode* root) {
		int minVal = INT_MAX;
		dfs(root);
		//std::sort( nums.begin(), nums.end() );
		for (int i = 0; i < nums.size() - 1; i++)
		{
			minVal = min(minVal, nums[i + 1] - nums[i]);
		}
		return minVal;
	}
};

int main()
{
	vector<int> nums = { 1, 3, 4, 4 };// { 73, 55, 36, 5, 55, 14, 9, 7, 72, 52 };
	//vector<vector<int>> nums = { { 1, 2, 3, 4 }, { 5, 1, 2, 3 }, { 9, 5, 1, 2 } };// {{11, 74, 0, 93 }, { 40, 11, 74, 7 }};
	//vector<string> strs = { "s" };
	Solution s;
	TreeNode node(3);
	node.left = new TreeNode(1);
	node.right = new TreeNode(5);
	auto ret = s.getMinimumDifference(&node);
	cout << endl;
	system("pause");
	return 0;
}