#include <bits/stdc++.h> 
#include<vector>
#define mod 1000000007
int countWays(int n,vector<int>&arr){
    if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;

    if( n==1 || n == 2){
        return n;
    }

    if(arr[n] != -1)
        return arr[n];

    arr[n] = (countWays(n-1,arr)+countWays(n-2,arr))%mod;
    return arr[n];
}

int countDistinctWays(int nStairs) {
    vector<int>arr(nStairs+1,-1);
    arr[0] = 0;
    return countWays(nStairs,arr);
}
