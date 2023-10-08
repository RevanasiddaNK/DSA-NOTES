#include <bits/stdc++.h> 
#include<limits.h>

int solveRec(vector<int>&cost, int amount){
    if(amount==0)
        return 0;
    if(amount < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<cost.size(); i++){
        int ans = solveRec(cost,amount-cost[i]);
        if(ans != INT_MAX){
            mini = min(ans+1,mini);
        }
    }
    return mini;
}


int solveMem(vector<int>&cost, int amount, vector<int>&arr){

    if(amount == 0)
        return 0;

    if(amount < 0)
        return INT_MAX;

    if(arr[amount] != -1)
        return arr[amount];

    int mini = INT_MAX;
    for(int i=0; i< cost.size(); i++){
        int ans = solveMem(cost,amount-cost[i],arr);
        if(ans != INT_MAX){
            mini = min(ans+1,mini);
        }
    }
    arr[amount] = mini;
    return mini;
}

int solveTab(vector<int> &cost, int amount){

    vector<int>arr(amount+1,INT_MAX);
    arr[0] = 0;

    for(int i=1; i<= amount; i++){
        for(int j=0; j<cost.size(); j++){
            if(i-cost[j] >= 0 && arr[i-cost[j]] != INT_MAX){
              arr[i] = min(arr[i], 1 + arr[i - cost[j]]);
            }
        }
    }
    return arr[amount];
}

// why we can not solve this iteratively & space optimisation method

int minimumElements(vector<int> &cost, int amount)
{
    
   // int ans = solveRec(cost,amount);

/*
    vector<int>arr(amount+1,-1);
    int ans = solveMem(cost,amount,arr);
*/

    int ans = solveTab(cost,amount);

    if(ans == INT_MAX)
        return -1;
    return ans;

}
