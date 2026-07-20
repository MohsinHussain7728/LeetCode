class Solution {
public:

    int solve(int idx, int n, int buy, vector<int>& prices, vector<vector<int>>& dp){
        //Base Case
        if(idx >= n)
            return 0;

        if(dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx+1,n,0,prices, dp) ,
            0 + solve(idx+1,n,1,prices, dp));
        }
        else{//after selling there's a cooldown of 1 day.
            profit = max( prices[idx] + solve(idx+2, n, 1,prices, dp) ,
            0 + solve(idx+1, n, 0, prices, dp));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(/*n+1*/ n+2,vector<int>(2,0));

        //Form Base Case : No need already settled.

        //Changing Params
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                if(buy == 1){
                    dp[i][buy] = max(-prices[i] + dp[i+1][0] ,
                    0 + dp[i+1][1]);
                }else{
                    dp[i][buy] = max(prices[i] + dp[i+2][1] ,
                    0 + dp[i+1][0]); 
                }
            }
        }

        // return solve(0,n,1,prices,dp);

        return dp[0][1];
    }
};