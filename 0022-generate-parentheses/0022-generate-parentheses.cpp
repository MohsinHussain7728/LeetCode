class Solution {
public:

    void helper(vector<string> &v, int n, int oc, int cc, string s){
        //Base case
        if(oc == n && cc==n){
            v.push_back(s);
            return;
        }

        if(oc<n){
            helper(v, n, oc+1, cc, s+"(");
        }

        if(cc<oc){
            helper(v, n, oc, cc+1, s+")");
        }
    }

    vector<string> generateParenthesis(int n) {//TC-->>O(2^n), SC-->>O(1)
        vector<string> ans;
        int oc=0, cc=0;
        helper(ans,n,oc,cc,"");
        return ans;
    }
};