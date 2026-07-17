class Solution {
public:

    int solve(int idx, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>&dp){
        //Base Case
        if(idx == n) return 0; //TC->O(n*2*3)
        if(cap == 0) return 0;  //SC->O(n*2*3) + O(n)

        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];        

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx+1,0,cap,prices,n,dp) ,
                    0 + solve(idx+1, 1, cap, prices,n,dp));
        }else{//sell
            profit = max(prices[idx] + solve(idx+1,1,cap-1,prices,n,dp) ,
                    0 + solve(idx+1, 0, cap, prices,n,dp));
        }

        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //3 States :-> (idx,buy,trades left);
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<int>>ahead(2,vector<int>(3,0));
        
        //Base Case: dp array is already initialized to 0 -> covering all the base cases.

        //Changing Params
        
        for(int idx = n-1; idx>=0; idx--){
            vector<vector<int>>curr(2,vector<int>(3,0));
            
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<3; cap++){
                    if(buy == 1){
                        curr[buy][cap] = max(-prices[idx] + ahead[0][cap] ,
                                            0 + ahead[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[idx] + ahead[1][cap-1] ,
                                            0 + ahead[0][cap]);
                    }
                }
            }
            ahead = curr;
        }
        


        return ahead[1][2];


        // return solve(0,1,2,prices,n,dp);
    }
};