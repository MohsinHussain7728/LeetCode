class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {//TC->O(n) ,, SC->O(n)
        int n = nums.size();
        int maxLen = INT_MIN;
        int len=0;

        unordered_map<int,int>freq;//(elem,freq)

        int l=0,r=0;

        while(r<n){
            freq[nums[r]]++;

            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }

            int len = r-l+1;
            maxLen = max(len,maxLen);

            r++;
        }

        return maxLen;
    }
};