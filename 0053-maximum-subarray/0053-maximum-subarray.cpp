class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending  = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){//best ending at index i...
            int c1 = bestending + nums[i];
            int c2 = nums[i];

            bestending = max(c1,c2);

            ans = max(ans,bestending);
        }

        return ans;
    }
};