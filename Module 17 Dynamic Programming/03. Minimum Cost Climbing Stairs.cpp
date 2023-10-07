class Solution {
public:

    int solve(vector<int>& cost,int n,vector<int>&arr){
        if(n == 0)
            return cost[0];
        else if(n == 1)
            return cost[1];
        else if(arr[n] != -1)
            return arr[n];
        else if(n == cost.size()){
            arr[n] = min(solve(cost,n-1,arr),solve(cost,n-2,arr));
            return arr[n];
        }
        arr[n] = min(solve(cost,n-1,arr),solve(cost,n-2,arr))+cost[n];
        return arr[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>arr(n+1,-1);
        return solve(cost,n,arr);
    }
};
