class Solution {
public:
    int pivotIndex(vector<int>& nums) {//TC->O(n) ,, SC->O(1)
        int sum = 0;
        
        for(int &it: nums)
            sum += it;

        int left = 0;

        for(int i=0; i<nums.size(); i++){
            
            int right = sum - nums[i] - left;

            if(left == right)
                return i;

            left += nums[i];
        }

        return -1;
    }
};