class Solution {
public:

    int helper(int idx, int n, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        //Base Case
        if(idx == n)
            return 0;

        if(dp[idx][buy] != -1)
            return dp[idx][buy];

        if(buy){
            return dp[idx][buy] = max(-prices[idx] + helper(idx+1, n, 0, fee, prices, dp) ,
            0 + helper(idx+1 , n, 1, fee, prices, dp));
        }
        else{
            return dp[idx][buy] = max(prices[idx] - fee + helper(idx+1, n, 1, fee, prices, dp),
            0 + helper(idx+1, n, 0, fee, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>ahead(2,0);
        vector<int>curr(2,0);

        //Base Case already formed
        //Changing Params
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy == 1){
                    // dp[i][buy] = max(-prices[i] + dp[i+1][0] ,
                    // 0 + dp[i+1][1]);
                    curr[buy] = max(-prices[i] + ahead[0] ,
                    0 + ahead[1]);
                }
                else{
                    // dp[i][buy] = max(prices[i] - fee + dp[i+1][1] ,
                    // 0 + dp[i+1][0]);
                    curr[buy] = max(prices[i] - fee + ahead[1] ,
                    0 + ahead[0]);
                }
            }
            ahead = curr;
        }

        // return helper(0,n,1,fee,prices,dp);

        // return dp[0][1];

        return ahead[1];
    }
};