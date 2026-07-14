class Solution {
public:

    long helper(vector<int>& prices, int idx, int buy, int n, vector<vector<int>>& dp){
        //Base Case
        if(idx == n)
            return 0;

        if(dp[idx][buy] != -1)
            return dp[idx][buy];

        long profit = 0;

        if(buy){
            profit = max(-prices[idx] + helper(prices, idx+1 , 0, n, dp) ,
             0 + helper(prices, idx+1, 1, n, dp));
        }
        else{
            profit = max(prices[idx] + helper(prices, idx+1, 1, n, dp) ,
            0 + helper(prices, idx+1, 0, n, dp));
        }

        return dp[idx][buy] = profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>ahead(2,0);

        //Form Base Cases
        // dp[n][0] = dp[n][1] = 0;
        ahead[0] = ahead[1] = 0;

        //Changing Params
        for(int idx=n-1; idx>=0; idx--){
            vector<int>curr(2,0);
            for(int buy = 0; buy<2; buy++){
                if(buy == 1){
                    // dp[idx][buy] = max(-prices[idx] + dp[idx+1][0] ,
                    // 0 + dp[idx+1][1]);
                    curr[buy] = max(-prices[idx] + ahead[0] ,
                    0 + ahead[1]);
                }else{
                    // dp[idx][buy] = max(prices[idx] + dp[idx+1][1] ,
                    // 0 + dp[idx+1][0]);
                    curr[buy] = max(prices[idx] + ahead[1] ,
                    0 + ahead[0]);
                }
            }
            ahead = curr;
        }

        // int ans = (int)helper(prices,0,1, n, dp);

        // return ans;

        // return dp[0][1];
        return ahead[1];
    }
};