#include<limits.h>

int solveRec(int day,int last,vector<vector<int>>&points){

    if(day == 0){
        int maxi = INT_MIN;
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for(int i=0; i<3; i++){
        if(i != last){
            int temp = points[day][i] + solveRec(day-1,i,points);
            maxi = max(maxi,temp);
        }
    }
    return maxi;
}


int solveMem(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){

    if(dp[day][last] != -1)
        return dp[day][last];

    if(day == 0){
        int maxi = INT_MIN;
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = INT_MIN;
    for(int i=0; i<3; i++){
        if(i != last){
            int temp = points[day][i] + solveMem(day-1,i,points,dp);
            maxi = max(maxi,temp);
        }
    }
    return dp[day][last] = maxi;
}

int solveTab(int n, vector<vector<int>> &points){
    vector<vector<int>>dp(n,vector<int>(4,0));
    // Base Cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);  
    dp[0][3] = max(points[0][1],max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            int maxi = INT_MIN;
            for(int task=0; task <3; task++){
                if(task != last){
                    int temp = dp[day-1][task] +points[day][task];
                    maxi = max(maxi,temp);
                    // dp[day][last] = maxi;
                }
            }
           dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}

int solveSpaceOpt(int n, vector<vector<int>> &points){

    vector<int>prev(4,0);
    // Base Cases
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);  
    prev[3] = max(points[0][1],max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++){
        vector<int>arr(4,0);
        for(int last=0; last<4; last++){
            int maxi = INT_MIN;
            for(int task=0; task <3; task++){
                if(task != last){
                    int temp = prev[task] +points[day][task];
                    maxi = max(maxi,temp);
                }
            }
           arr[last] = maxi;
        }
        prev = arr;
    }
    return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //return solveRec(n-1,3,points);

    vector<vector<int>>dp(n,vector<int>(4,-1));
    //return solveMem(n-1,3,points,dp);

    //return solveTab(n,points);

    return solveSpaceOpt(n,points);

}
