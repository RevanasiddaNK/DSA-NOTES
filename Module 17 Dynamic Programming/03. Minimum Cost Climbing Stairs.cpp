class Solution {
public:

    int solveMemoization(vector<int>& cost,int n,vector<int>&arr){
        if(n == 0)
            return cost[0];
        else if(n == 1)
            return cost[1];
        else if(arr[n] != -1)
            return arr[n];
        else if(n == cost.size()){
            arr[n] = min(solveMemoization(cost,n-1,arr),solveMemoization(cost,n-2,arr));
            return arr[n];
        }
        arr[n] = min(solveMemoization(cost,n-1,arr),solveMemoization(cost,n-2,arr))+cost[n];
        return arr[n];
    }

    int solveTabulation(vector<int>& cost,int n){
        vector<int>arr(n+1);
        arr[0] = cost[0];
        arr[1] = cost[1];
        for(int i=2; i<n; i++)
            arr[i] = min(arr[i-1],arr[i-2])+cost[i];
        arr[n] = min(arr[n-1], arr[n-2]);
        return arr[n];
    }

    int solveSpaceOptimisation(vector<int>&cost,int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i=2; i<n; i++){
            int curr = min(prev1, prev2)+cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
    /*    
        vector<int>arr(n+1,-1);
        return solve(cost,n,arr);
    */
        
        // return solveTabulation(cost,n);

        return solveSpaceOptimisation(cost,n);
    }
};
