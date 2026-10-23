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
    TreeNode* insertIntoBST(TreeNode* root, int val) { //TC->O(log2n) ,, SC->O(1)
        if(root == NULL) return new TreeNode(val);

        TreeNode* curr = root;

        while(true){
            if(curr->val <= val){//move on right
                if(curr->right != NULL){
                    curr = curr->right;
                }else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != NULL)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};