#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveTab(int m, int n, string s1, string s2, vector<vector<int>>&dp){

// Base cases after shifting of indexes right by +1
    for(int i=0; i<=n; i++)
        dp[0][i] = 0;
    
    for(int i=0; i<=m; i++)
        dp[i][0] = 0;
    
// changing paramenters to nested loops
    for(int i1=1; i1<=m; i1++){
        for(int i2=1; i2<=n; i2++){
            if(s1[i1-1] == s2[i2-1]){
                dp[i1][i2] = 1 + dp[i1-1][i2-1]; 
            }
            else{
                dp[i1][i2] = 0 + max(dp[i1-1][i2], dp[i1][i2-1]); 
            }
        }
    }
    return dp[m][n];
}


int main(){
    string s1 = "adebc";
    string s2 = "dcadb";

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MIN));
    int len = solveTab(m,n,s1,s2,dp);
    vector<char>ans(len,'B');
    int index = len-1;
    int i=m,j=n;
    while( i > 0 && j > 0 ){

        if(s1[i-1] == s2[j-1]){
            ans[index--] = s1[i];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
                i--;
        else
                j--;
    }

    for(int i=0; i<len; i++)
        cout<<ans[i];
    cout<<endl;

    return 0;

}
