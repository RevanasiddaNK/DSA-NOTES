#include <bits/stdc++.h>
#include<limits.h>

//  Recursion
int solveRec(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid){
    //  Out bond base case
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        return -1e9;

    //  Destination Base case
    if(i == r-1){
        if(j1 == j2)
            return grid[r-1][j1];
        else
            return grid[r-1][j1] + grid[r-1][j2];
    }

    // step 2 Explore all paths 
    int maxi = INT_MIN;

    for(int dj1=-1; dj1<2; dj1++){
        for(int dj2=-1; dj2<2; dj2++){
            int pathsum = INT_MIN;
            if(j1 == j2){
                pathsum = grid[i][j1] + solveRec(r,c,i+1,j1+dj1,j2+dj2,grid);
                maxi = max(maxi,pathsum);
            }
            else{
                pathsum = grid[i][j1] + grid[i][j2] + solveRec(r,c,i+1,j1+dj1,j2+dj2,grid);
                maxi = max(maxi,pathsum);
            }
        }
    }

}

// Memoization
int solveMem(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    //  Out bond base case
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        return -1e9;

    //  Destination Base case
    if(i == r-1){
        if(j1 == j2)
            return grid[r-1][j1];
        else
            return grid[r-1][j1] + grid[r-1][j2];
    }

    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // step 2 Explore all paths 
    int maxi = INT_MIN;
    for(int dj1=-1; dj1<2; dj1++){
        for(int dj2=-1; dj2<2; dj2++){
            int pathsum = INT_MIN;
            if(j1 == j2){
                pathsum = grid[i][j1] + solveMem(r,c,i+1,j1+dj1,j2+dj2,grid,dp);
                maxi = max(maxi,pathsum);
            }
            else{
                pathsum = grid[i][j1] + grid[i][j2] + solveMem(r,c,i+1,j1+dj1,j2+dj2,grid,dp);
                maxi = max(maxi,pathsum);
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}

// Tabulation 

int solveTab(int r, int c, vector<vector<int>> &grid){
    // step 1
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    // base case
    for(int j1 = 0; j1 < c; j1++){
        for(int j2 = 0; j2 < c; j2++){
            if(j1 == j2) 
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // step 2 express every states in for loops
    for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){

    // step 3 copy the recurence
                int maxi = INT_MIN;
                for(int dj1=-1; dj1<2; dj1++){
                    for(int dj2=-1; dj2<2; dj2++){
                        int pathsum = INT_MIN;
                            if(j1 == j2){

                                    if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                                        pathsum = grid[i][j1] + dp[i+1][j1+dj1][j2+dj2];
                                    else
                                        pathsum = INT_MIN;

                                maxi = max(maxi,pathsum);
                            }
                            else{

                                if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                                    pathsum = grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2];
                                else
                                    pathsum = INT_MIN;

                                maxi = max(maxi,pathsum);
                            }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}

// Space Optimization 
int solveSpaceOpt(int r, int c, vector<vector<int>> &grid){
/* 
    tabulation -> Space Optimization 
    1D -> 2 variables
    2D -> 2 1D Arrays
    3D -> 2 2D Arrays

*/

    // step 1
    vector<vector<int>>front(c,vector<int>(c, 0));
    // base case
    for(int j1 = 0; j1 < c; j1++){
        for(int j2 = 0; j2 < c; j2++){
            if(j1 == j2) 
                front[j1][j2] = grid[r-1][j1];
            else
                front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // step 2 express every states in for loops
    for(int i=r-2; i>=0; i--){
        vector<vector<int>>curr(c, vector<int>(c, 0));
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){

    // step 3 copy the recurence
                int maxi = INT_MIN;
                for(int dj1=-1; dj1<2; dj1++){
                    for(int dj2=-1; dj2<2; dj2++){
                        int pathsum = INT_MIN;
                            if(j1 == j2){

                                    if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                                        pathsum = grid[i][j1] + front[j1+dj1][j2+dj2];
                                    else
                                        pathsum = INT_MIN;

                                maxi = max(maxi,pathsum);
                            }
                            else{

                                if(j1+dj1 >= 0 && j2+dj2 >= 0 && j1+dj1 < c && j2+dj2 < c)
                                    pathsum = grid[i][j1] + grid[i][j2] + front[j1+dj1][j2+dj2];
                                else
                                    pathsum = INT_MIN;

                                maxi = max(maxi,pathsum);
                            }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][c-1];
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid){
    int i=0,j1=0,j2=c-1;
//    return solveRec(r,c,i,j1,j2,grid);
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solveMem(r,c,i,j1,j2,grid,dp);

    return solveTab(r,c,grid);
    return solveSpaceOpt(r,c,grid);

}
