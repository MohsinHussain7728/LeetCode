class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n =nums.size();
        vector<int>ans;

        vector<int>temp1;
        vector<int>temp2;

        for(int i=0; i<2; i++){
            if((i % 2) == 0)
                temp1.push_back(nums[i]);
            else
                temp2.push_back(nums[i]);
        }

        for(int i=2; i<n; i++){
            if(temp1.back() > temp2.back())
                temp1.push_back(nums[i]);
            else
                temp2.push_back(nums[i]);
        }

        for(auto &i : temp1)
            ans.push_back(i);

        for(auto &j : temp2)
            ans.push_back(j);

        return ans;
    }
};