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
    // void helper(TreeNode* x, vector<int>& ans){
    //     if(x == NULL) return;

    //     if(x->left != NULL) helper(x->left,ans);
    //     ans.push_back(x->val);
    //     if(x->right != NULL) helper(x->right,ans);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // helper(root,ans);
        // return ans;

        vector<int> inorder;
        TreeNode* curr = root;
        stack<TreeNode*>st;

        while(curr!=NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            
            inorder.push_back(curr->val);
            curr = curr->right;
        }

        return inorder;
    }
};