class Solution {
public:

    void solve(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, unordered_set<int>& st){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        //1.do something 2.Explore 3.Revert back
        

        for(int i=0; i<nums.size(); i++){ 

            if(st.find(nums[i]) == st.end()){
                ds.push_back(nums[i]);

                st.insert(nums[i]);

                solve(nums,ds,ans,st);
                ds.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {//TC->O(n!*n)  ,, SC->O(1).
        vector<vector<int>>ans;

        vector<int>ds;
        
        unordered_set<int>st;

        solve(nums,ds,ans,st);

        return ans;
    }
};