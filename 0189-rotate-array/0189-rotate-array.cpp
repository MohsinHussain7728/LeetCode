class Solution {
public:
    void rotate(vector<int>& nums, int k) {//TC->O(n) ,, SC->O(1)
        int n = nums.size();

        k = k%n;

        //lambda function
        auto reverse = [&](int i, int j){
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        };


        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);        
        
    }
};

// for(int i=0; i<k; i++){
//             int temp = nums[n-1];
            
//             for(int j=n-2; j>=0; j--){
//                 nums[j+1] = nums[j];
//             }
//             nums[0] = temp; 
//         }