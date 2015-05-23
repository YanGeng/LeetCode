#include <iostream>
#include <limits.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;

		long long MIN = INT_MIN;
		long long MAX = INT_MAX;

		return isValidBST(root, MIN, MAX);
    }

	bool isValidBST(TreeNode *node, long long min, long long max) {
		if (node == NULL)
			return true;

		if (node->val <= min || node->val >= max)
			return false;

		bool leftFlag = isValidBST(node->left, min, node->val);
		bool rightFlag = isValidBST(node->right, node->val, max);

		if (!leftFlag || !rightFlag)
			return false;

		return true;
	}
};

int main()
{
	return 0;
}
