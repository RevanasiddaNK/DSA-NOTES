#include<bits/stdc++.h>
#include<vector>
using namespace std;

int fibMemoization(int n, vector<int>&arr){
        if(n == 1 || n== 0){
            arr[n] = n;    
            return arr[n];
        }
        if(arr[n] != -1)
            return arr[n];
            
        arr[n] = fibMemoization(n-1,arr)+fibMemoization(n-2,arr);
        return arr[n];
}

void fibTabulation(int n, vector<int>&arr){
        arr[0] = 0;
        arr[1] = 1;
        for(int i=2; i<=n; i++){
                arr[i] = arr[i-1]+arr[i-2];
        }
}

int fibSpaceOptimisation(int n){
        if(n <= 1)
                return n;
        int prev2 = 0;
        int prev1 = 1;
        for(int i=2; i<=n; i++){
                int curr = prev1+prev2;
                prev2 = prev1;
                prev1 = curr;
        }
        return prev1;
}

int main()
{
        int n;
        cin>>n;

        vector<int>arr(n+1,-1);
        for(int i=0; i<n+1; i++)
            arr[i] = -1;

        // cout<<fibMemoization(n,arr)<<endl;
/*
        fibTabulation(n,arr);
        cout<<arr[n]<<endl;
*/
        cout<<fibSpaceOptimisation(n)<<endl;
        
}