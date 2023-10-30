// Problem : Coin Change 2 | Infinite Supply Problems | DP on Subsequences

#include<vector>
#include<limits.h>
/*
 // why this is wrong ?

(1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)

that is why we need to go through the concept of subsequences

long solverec(int *denominations, int n, int value){

  if(value == 0)
    return 1;

  long ans = 0;
  for(int i=0; i<n;i++){ 
    if( 0 <= value-denominations[i])
      ans += solverec(denominations,n, value-denominations[i]);
  }
  return ans;
}
*/

long solveRecursioin(int *arr, int index, int target){
  // base case
  if(index == 0){
    return (target%arr[0] == 0);
  }

  // explore all paths
  long nottake = solveRecursioin(arr,index-1,target);
  long take = 0;
  if(arr[index] <= target){
    // dont decrement index bcz. we can use same index as many as times
    // infinite supply of coins
    take = solveRecursioin(arr,index,target-arr[index]);
  }
  return nottake + take;
}






// memoization
long solveMem(int *arr, int index, int target,vector<vector<long>>&dp){
  // base case
  if(index == 0){
    return (target%arr[0] == 0);
  }

  if(dp[index][target] != -1)
    return dp[index][target]; 

  // explore all paths
  long nottake = solveMem(arr,index-1,target,dp);
  long take = 0;
  if(arr[index] <= target){
    // dont decrement index bcz. we can use same index as many as times
    // infinite supply of coins
    take = solveMem(arr,index,target-arr[index],dp);
  }
  return dp[index][target] = nottake + take;
}





long solveTab (int *arr, int n, int T){
  // step 1
  vector<vector<long>>dp(n, vector<long>(T+1,0));
  // Base Case 
  for(int target=0; target<=T;target++){
    dp[0][target] = (target%arr[0] == 0);
  }

  // step 2 nested for loops from changing parameters
  // bottom up approach
  for(int index = 1; index <n; index++){
    for(int target=0; target <= T; target++){
      // step 3 copy recurence processing
      long nottake =dp[index-1][target];
      long take = 0;
      if(arr[index] <= target){
    // dont decrement index bcz. we can use same index as many as times
    // infinite supply of coins
        take = dp[index][target-arr[index]];
      }
      dp[index][target] = nottake + take;
    }
  }
  return dp[n-1][T];
}






long solveSpaceOpt(int *arr, int n, int T){
  // step 1
  vector<long>prev(T+1,INT_MIN);
  // Base Case 
  for(int target=0; target<=T;target++){
    prev[target] = (target%arr[0] == 0);
  }

  // step 2 nested for loops from changing parameters
  // bottom up approach
  for(int index = 1; index <n; index++){
    vector<long>curr(T+1,INT_MIN);
    for(int target=0; target <= T; target++){
      // step 3 copy recurence processing
      long nottake =prev[target];
      long take = 0;
      if(arr[index] <= target){
    // dont decrement index bcz. we can use same index as many as times
    // infinite supply of coins
        take = curr[target-arr[index]];
      }
      curr[target] = nottake + take;
    }
    prev = curr;
  }
  return prev[T];
}



long countWaysToMakeChange(int *denominations, int n, int target)
{
  //return solverec(denominations,n, value); //wrong
  
  return solveRecursioin(denominations,n-1,target);

  vector<vector<long>>dp(n, vector<long>(target+1,-1));
  return solveMem(denominations,n-1,target,dp);

  return solveTab(denominations,n,target);

  return solveSpaceOpt(denominations,n,target);
}
