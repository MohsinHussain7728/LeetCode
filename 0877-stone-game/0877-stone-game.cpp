class Solution {
public:

    int solve(vector<int>& piles, int l, int r, vector<vector<int>>& dp){
        if(l == r)
            return piles[l];

        if(dp[l][r] != INT_MIN)
            return dp[l][r];

        int takeLeft = piles[l] - solve(piles,l+1,r,dp);
        int takeRight = piles[r] - solve(piles,l,r-1,dp);

        return dp[l][r] = max(takeLeft,takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        vector<int>front(n);
        vector<int>curr(n);

        //Base Case
        for(int i=0; i<n; i++){
            // dp[i][i] = piles[i];
            front[i] = piles[i];
        }
        
        //Changing Params
        for(int i=n-2; i>=0; i--){//(i=n-1 for normal dp)
            for(int j=i+1; j<n; j++){
                // int takeLeft = piles[i] - dp[i+1][j]; // below
                int takeLeft = piles[i] - front[j]; // below

                // int takeRight = piles[j] - dp[i][j-1]; // left
                int takeRight = piles[j] - curr[j-1]; // left

                // dp[i][j] = max(takeLeft, takeRight);
                curr[j] = max(takeLeft, takeRight);
            }
            front = curr;
        }

        // int advantage = solve(piles,0,n-1,dp);

        // return advantage>0; //Since Alice starts -> whether she can accumulate +ve diff -> WIN

        // return dp[0][n-1] > 0;
        return curr[n-1] > 0;
    }
};