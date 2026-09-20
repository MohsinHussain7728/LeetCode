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

    bool helper(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;

        if(s->val != t->val)
            return false;
        
        return (helper(s->left,t->left) && helper(s->right,t->right) || 
                helper(s->left,t->right) && helper(s->right,t->left));
        
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {//TC->O(min(n,m)) ,, SC->O(n)
        return helper(root1,root2);             // n & m are no. of nodes in trees
    }
};