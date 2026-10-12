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
class Solution {
public:

    pair<TreeNode*,int> solve(TreeNode* root,int depth){//TC->O(n) ,, SC->O(h)
        if(root == NULL)
            return {NULL,depth};

        pair<TreeNode*,int> l = solve(root->left,depth+1);
        pair<TreeNode*,int> r = solve(root->right,depth+1);

        if(l.second == r.second)
            return {root,l.second};
        
        return l.second>r.second ? l : r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode*,int> p = solve(root,0);

        return p.first;
    }
};