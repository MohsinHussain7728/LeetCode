class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int minm = -1;

        while(low<=high){
            int mid = low + (high-low)/2;//Guess

            if(nums[mid] > nums[n-1]){//Means part2 me hu->move right
                low = mid+1;
            }else{//Part1 me hu->move left
                minm = nums[mid];
                high = mid-1;
            }
        }

        return minm;
    }
};