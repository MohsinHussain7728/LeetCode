class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mppMax;//(idx,maxValue)
        unordered_map<int,int>mppMin;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            mppMax[i] = maxi;
        }

        for(int i=n-1; i>=0; i--){
            mini = min(mini,nums[i]);
            mppMin[i] = mini;
        }


        for(int i=0; i<n; i++){
            long score = mppMax[i] - mppMin[i];

            if(score <= k){
                return i;
            }
        }

        return -1;
    }
};