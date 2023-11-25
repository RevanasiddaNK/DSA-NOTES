#include<bits/stdc++.h>

vector<int> solve(vector<int>&arr){
    int n = arr.size();
    vector<int>dp(n,1),BackTrack(n);  
    int maxi = 0 , LastInd = 0;
    sort(arr.begin(),arr.end());
    for(int ind=0; ind<n; ind++){
        BackTrack[ind] = ind;
        for(int pre=0; pre<ind; pre++){
            if(arr[ind] % arr[pre] == 0 && dp[ind] < 1+dp[pre]){
                dp[ind] = 1 + dp[pre];
                BackTrack[ind] = pre;
            }
        }
            
        if(maxi < dp[ind]){
            maxi = dp[ind];
            LastInd = ind;
        }
    }
        
    vector<int>ans;
    int ind = LastInd;
        
    while(BackTrack[ind] != ind){
        ans.push_back(arr[ind]);
        ind = BackTrack[ind];
    }
    ans.push_back(arr[ind]);
    reverse(ans.begin(),ans.end());
        
    return ans;
        
}

vector<int> divisibleSet(vector<int> &arr)
{
    return solve(arr);
}
