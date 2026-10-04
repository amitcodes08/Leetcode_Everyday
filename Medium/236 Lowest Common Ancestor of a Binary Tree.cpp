/*
    LeetCode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

//Approach - Use DFS and find
//T.C : O(n)
//S.C : O(n) for System Stack used for Recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r)
            return root;
        
        return l?l:r;
    }
};