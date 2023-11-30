int countSquares(int n, int m, vector<vector<int>>&arr)
{
    n = arr.size();
    m = arr[0].size();

    // DP on Rectangle / Square Area Problems are easily solved through Tablulation
    vector<vector<int>>dp(n,vector<int>(m,0));
    int sum = 0;
    
    // Base Case
    for(int i=0; i<n; i++)
        sum += dp[i][0] = arr[i][0];

    for(int i=1; i<m; i++)
        sum += dp[0][i] = arr[0][i];
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 0)
                dp[i][j] = 0;
            else
                sum += dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return sum;
}
