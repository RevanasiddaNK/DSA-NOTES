class Solution {
  public:
  
    vector<int> solveTab(int n, vector<int>& arr){
        vector<int>dp(n,1),BackTrack(n);
        
        int maxi = 0 , LastInd = 0;
        
        for(int ind=0; ind<n; ind++){
            BackTrack[ind] = ind;
            for(int pre=0; pre<ind; pre++){
                if(arr[ind] > arr[pre] && dp[ind] < 1+dp[pre]){
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
  
  
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
       return solveTab(n,arr);
    }
};
