#include<bits/stdc++.h>

#define ll long long int
int mod = 1000000007;

ll solveRec(int i, int j, int isTrue, string &exp){

    if(i>j)
        return 0;
    
    if(i == j){
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    ll ways = 0;
    for(int ind=i+1; ind <= j-1; ind = ind+2){

        ll LT = solveRec(i,ind-1,1,exp);
        ll LF = solveRec(i,ind-1,0,exp);
        ll RT = solveRec(ind+1,j,1,exp);
        ll RF = solveRec(ind+1,j,0,exp);

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways+LT * RT)%mod;
            }
            else{
                ways = (ways+(LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod )%mod;
            }
        }
        else if(exp[ind] == '|'){
            
            if(isTrue){
                ways = (ways+(LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
            }
            else{
                ways = (ways+(LF*RF)%mod);
            }
        }
        else if(exp[ind] == '^'){
            // ^ Operator
            if(isTrue){
                ways = (ways+(LT*RF)%mod + (LF*RT)%mod)%mod;
            }
            else{
                ways = (ways+(LF*RF)%mod + (LT*RT)%mod)%mod;
            }
        }
    }
    return ways%mod;
}

ll solveMem(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>>&dp){

    if(i>j)
        return 0;
    
    if(i == j){
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for(int ind=i+1; ind <= j-1; ind = ind+2){

        ll LT = solveMem(i,ind-1,1,exp,dp);
        ll LF = solveMem(i,ind-1,0,exp,dp);
        ll RT = solveMem(ind+1,j,1,exp,dp);
        ll RF = solveMem(ind+1,j,0,exp,dp);

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways+LT * RT)%mod;
            }
            else{
                ways = (ways+(LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod )%mod;
            }
        }
        else if(exp[ind] == '|'){
            
            if(isTrue){
                ways = (ways+(LT*RT)%mod + (LT*RF)%mod + (LF*RT)%mod)%mod;
            }
            else{
                ways = (ways+(LF*RF)%mod);
            }
        }
        else if(exp[ind] == '^'){
            // ^ Operator
            if(isTrue){
                ways = (ways+(LT*RF)%mod + (LF*RT)%mod)%mod;
            }
            else{
                ways = (ways+(LF*RF)%mod + (LT*RT)%mod)%mod;
            }
        }
    }
     return dp[i][j][isTrue] = ways%mod;
}

int evaluateExp(string &exp) {

    int n = exp.size();
    return solveRec(0,n-1,1,exp);

    vector<vector<vector<ll>>>dp(n+1, vector<vector<ll>>(n+1,(vector<ll>(2,-1))));
    return solveMem(0,n-1,1,exp,dp);
}
