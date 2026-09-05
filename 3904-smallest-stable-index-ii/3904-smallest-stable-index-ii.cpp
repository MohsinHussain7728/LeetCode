class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // unordered_map<int,int>mppMax;//(idx,maxValue)
        // unordered_map<int,int>mppMin;

        vector<int>arrMax(n,0);
        vector<int>arrMin(n,0);

        arrMax[0] = nums[0];
        arrMin[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            arrMax[i] = max(arrMax[i-1],nums[i]);
        }

        for(int i=n-2; i>=0; i--){
            arrMin[i] = min(arrMin[i+1],nums[i]);
        }


        for(int i=0; i<n; i++){
            // int score = arrMax[i] - arrMin[i];

            if(arrMax[i] - arrMin[i] <= k){
                return i;
            }
        }

        return -1;
    }
};