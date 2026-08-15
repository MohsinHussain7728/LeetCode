#include <bits/stdc++.h>

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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode* >que;
        int level = 0;
        int res = INT_MAX;

        que.push(root);

        while(!que.empty()){
            level+=1;
            int size = que.size();

            for(int i=0; i<size; i++){

                TreeNode* temp = que.front();
                que.pop();

                if(!temp->left && !temp->right)
                    res = min(res,level);

                if(temp->left != NULL){
                    que.push(temp->left);
                }
                if(temp->right != NULL){
                    que.push(temp->right);
                }

            }
        }

        return res;
    }
};