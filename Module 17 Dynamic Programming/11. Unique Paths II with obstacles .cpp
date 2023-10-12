#define mod 1000000007
//#define mod 1e9+7
//long long int mod = 1e9+7;
int solveRec(int i, int j,vector<vector<int>>&mat){
// ADDition of base case to Modify the previous code
    if(i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;

    // Base Case
    if(i == 0 && j == 0)
        return 1;

    //Boundary Edge cases
    if(i<0 || j<0)
        return 0;

    int up = solveRec(i-1,j,mat);
    int left = solveRec(i,j-1,mat);

    return (up+left)%mod;
}

// Memoization
int solveMem(int i, int j, vector<vector<int>>&dp,vector<vector<int>>&mat){

// ADDition of base case to Modify the previous code
    if(i >= 0 && j >= 0 && mat[i][j] == -1 )
        return 0;

    // Base Case
    if(i == 0 && j == 0)
        return 1;

    //Boundary Edge cases
    if(i<0 || j<0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int up = solveMem(i-1,j,dp,mat);
    int left = solveMem(i,j-1,dp,mat);

    return dp[i][j] = (up+left)%mod;
}

int solveTab(int m,int n,vector<vector<int>>&mat){
    vector<vector<int>>dp(m,vector<int>(n,0));
    // Bottom Up Aproach
    //base case
    dp[0][0] = 1;

    // for loops by analysing recursive calls
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int left=0,up=0;
// ADDition of base case to Modify the previous code
            if(i >= 0 && j >= 0 && mat[i][j] == -1 ){
                 dp[i][j] = 0;
                 continue;
             }

            // Base Case 
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i > 0)
                up = dp[i-1][j];
            if(j > 0)
                left = dp[i][j-1];

            dp[i][j] = (up+left)%mod;
        }
    }
    return dp[m-1][n-1];
}

int solveSpaceOpt(int m, int n, vector<vector<int>>&mat){
    vector<int>prevRow(n,0);
    // Bottom Up Aproach
    // base case
    // prevRow[0] = 1;

    // for loops by analysing recursive calls
    for(int i=0; i<m; i++){
        vector<int>curr(n,0);
        for(int j=0; j<n; j++){

            int left=0,up=0;
        // ADDition of base case to Modify the previous code
            if(i >= 0 && j >= 0 && mat[i][j] == -1 ){
                 curr[j] = 0;
                 continue;
             }

            // Base Case 
            if(i == 0 && j == 0){
                //dp[i][j] = 1;
                curr[j] = 1;
                continue;
            }

            if(i != 0){
                // up = dp[i-1][j];
                up = prevRow[j];
            }
            if(j != 0){
               // left = dp[i][j-1];
                left = curr[j-1];
            }
            // dp[i][j] = up+left;
            curr[j] = (up+left)%mod;

        }
        prevRow = curr;
    }
    // return dp[m-1][n-1];
    return prevRow[n-1];
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {

    //return solveRec(n-1,m-1,mat);
    vector<vector<int>>dp(n,vector<int>(m,-1));
    //return solveMem(n-1,m-1,dp,mat);
    //return solveTab(n,m,mat);
    return solveSpaceOpt(n,m,mat);
}
