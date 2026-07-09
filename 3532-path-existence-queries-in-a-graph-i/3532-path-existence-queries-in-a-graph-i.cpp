class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n);//DSU, used increasing order to help find same comp
        comp[0]=0;

        for(int i=1; i<n; i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                comp[i] = comp[i-1];
            }else{
                comp[i] = comp[i-1] + 1;
            }
        }

        vector<bool> ans;

        for(auto &it: queries){
            if(comp[it[0]] == comp[it[1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};