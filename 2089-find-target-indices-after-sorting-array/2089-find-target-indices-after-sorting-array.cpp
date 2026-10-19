class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;

        sort(nums.begin(),nums.end());
        int i = 0;

        while(i<nums.size() && nums[i] != target){
            i++;
        }

        if(i == nums.size())
            return ans;

        while(true){
            ans.push_back(i);
            if(i+1 < nums.size() && nums[i+1] == target){
                i++;
            }
            else
                break;
        }

        return ans;
    }
};