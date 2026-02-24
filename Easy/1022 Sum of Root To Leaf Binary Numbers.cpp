/*
    https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
*/

// TC : O(N)
// SC : O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return 0;
        }

        val = (val * 2) + (1 * root->val);

        if (root->left == NULL && root->right == NULL)
            return val;

        return solve(root->left, val) + solve(root->right, val);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        return solve(root, 0);
    }
};
