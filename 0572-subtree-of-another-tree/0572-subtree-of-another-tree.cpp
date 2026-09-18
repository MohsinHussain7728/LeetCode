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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL)
            return false;
        
        if(root->val == subRoot->val){
            if(isSameTree(root,subRoot) == true)
                return true;
        }
        
        if(isSubtree(root->left,subRoot) == true)
            return true;
        if(isSubtree(root->right,subRoot) == true)
            return true;
    
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        //if nodes are not equal i.e.NULL
        if(p == NULL || q == NULL) return false;

        return ((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }


};