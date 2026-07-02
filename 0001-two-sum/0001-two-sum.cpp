class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        // vector<int> ans;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            int num = nums[i];
            int moreNeeded= target-num;

            if(mpp.find(moreNeeded) != mpp.end()){
                // ans.emplace_back(mpp[moreNeeded]);
                // ans.emplace_back(i);
                return {mpp[moreNeeded],i};
            }
        mpp[num]=i;
        }
        return {-1,-1};
    }
};