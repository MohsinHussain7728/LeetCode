class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int N = n*m;

        k = k%N;

        if(k == 0)
            return grid;

        //Lambda function
        auto reverse = [&](int i, int j){//& : allows to access by reference the constituents of nums
            while(i<j){      // for idx: row=i/col ,, col=i%col;
                swap(grid[i/m][i%m] , grid[j/m][j%m]); //swap(nums[i],nums[j])
                i++;
                j--;
            }
        };


        reverse(0,N-1);
        reverse(0,k-1);
        reverse(k,N-1);

        return grid;
    }
};





