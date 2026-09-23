class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return 1;

        int ans = -1;

        int minIdx = -1;
        int maxIdx = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxIdx = i;
                maxi = nums[i];
            }
            if(nums[i]<mini){
                minIdx = i;
                mini = nums[i];
            }
        }

        int left = min(minIdx,maxIdx);
        int right = max(minIdx,maxIdx);

        ans = min({right+1, n-left, (left+1)+(n-right)}); //from front, from back, from both

        return ans;
    }
};