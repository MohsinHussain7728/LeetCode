class Solution {
public:

    bool func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        //Base Case
        if(i==0 && j==0)
            return true;
        
        if(i>0 && j==0)
            return false;

        if(i==0 && j>0){
            for(int k=0; k<j; k++){
                if(s2[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];


        if(s1[i-1] == s2[j-1] || s2[j-1] == '?')
            return dp[i][j] = func(i-1,j-1,s1,s2,dp);

        if(s2[j-1] == '*')
            return dp[i][j] = func(i-1,j,s1,s2,dp) | func(i,j-1,s1,s2,dp);

        return dp[i][j] = false;//if either of char doesn't matches.
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        vector<bool>prev(m+1,0);

        //1.Form Base Case
        // dp[0][0] = true;
        prev[0] = true;

        // for(int i=1; i<=m; i++)
        //     dp[i][0] = false;

        for(int j=1; j<=m; j++){//Can the empty string match first j char of pattern??
            prev[j] = (p[j-1] == '*') && prev[j-1];
        }

        //2.Changing Params
        for(int i=1; i<=n; i++){
            vector<bool>curr(m+1,0);
            curr[0] = false;

            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    // dp[i][j] = dp[i-1][j-1];
                    curr[j] = prev[j-1];
                }

                else if(p[j-1] == '*'){
                    // dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    curr[j] = prev[j] || curr[j-1];
                }

                // else dp[i][j] = false;//if either of char doesn't matches.
                else curr[j] = false;//if either of char doesn't matches.
            }
            prev = curr;
        }

        // return func(n,m,s,p,dp);

        // return dp[n][m];

        return prev[m];
    }
};