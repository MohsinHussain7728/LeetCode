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

    int cnt = 0;

    void helper(TreeNode* node,unordered_map<long long,int>&mpp,long long preSum,int target){
        if(node == NULL){
            return;
        }

        preSum += node->val;
        long long reqd = preSum - target;

        if(mpp.find(reqd) != mpp.end()){
            cnt += mpp[reqd];
        }

        mpp[preSum]+=1; 
        

        if(node->left) helper(node->left, mpp, preSum, target);
        if(node->right) helper(node->right, mpp, preSum, target);

        mpp[preSum]-=1;
        if(mpp[preSum] == 0)
            mpp.erase(preSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        // vector<TreeNode*>temp;
        unordered_map<long long,int>mpp;
        mpp[0] = 1;

        helper(root,mpp,0,targetSum);


        return cnt;
    }
};