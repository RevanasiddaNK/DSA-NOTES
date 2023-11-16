
int solveRec( int i,vector<int>&prices,int buy, int trans,int n)
{
    if(trans == 0 || i == n)
        return 0;
    
    if(buy){
        return max( (-prices[i]+solveRec(i+1,prices,0,trans,n)) , (solveRec(i+1,prices,1,trans,n)) );
    }
    else{
        return max( (prices[i]+solveRec(i+1,prices,1,trans-1,n)) , (solveRec(i+1,prices,0,trans,n)) );
    }

}

int solveMem( int i, vector<int>&prices, int buy, int trans, int& n, vector<vector<vector<int>>>&dp)
{
    if(trans == 0 || i == n)
        return 0;

    if(dp[i][buy][trans] != -1)
        return dp[i][buy][trans];
    
    if(buy){
        return dp[i][buy][trans] = max( (-prices[i]+solveMem(i+1,prices,0,trans,n,dp)) , (solveMem(i+1,prices,1,trans,n,dp)) );
    }
    else{
        return dp[i][buy][trans] = max( (prices[i]+solveMem(i+1,prices,1,trans-1,n,dp)) , (solveMem(i+1,prices,0,trans,n,dp)) );
    }

}

int solveTab(vector<int>&prices, int n)
{
    vector<vector<vector<int>>>dp(n+1 ,vector<vector<int>>(2, vector<int>(3,-1)));

    // Base Case
    for(int i=0; i<=n; i++){
        for(int buy=0; buy<2; buy++){
            for(int trans=0; trans<=2 ; trans++){
                if(trans == 0 || i == n)
                    dp[i][buy][trans] = 0;
            }
        }
    }

    for(int i=n-1; i >=0; i--){
        for(int buy=1; buy >= 0 ; buy--){
            for(int trans=2; trans > 0 ; trans--){
                 if(buy){
                    dp[i][buy][trans] = max( -prices[i] + dp[i+1][0][trans] , dp[i+1][1][trans] );
                }
                else{
                    dp[i][buy][trans] = max( prices[i] + dp[i+1][1][trans-1] , dp[i+1][0][trans] );
                }
            }
        }
    }
    return dp[0][1][2];
}

int maxProfit(vector<int>& prices)
{
    int buy = 1;
    int n = prices.size();
    return solveRec(0,prices,buy,2,n);

    vector<vector<vector<int>>>dp(n ,vector<vector<int>>(2, vector<int>(3,-1)));
    return solveMem(0,prices,buy,2,n,dp);

    return solveTab(prices,n);

}
