#include<bits/stdc++.h>
bool solveRec(int i, int j, string pattern, string text)
{
   // Base Cases
   if(i < 0 && j < 0)
      return 1;

   if(i < 0 && j <= 0)
      return 0;

   if(i >= 0 && j < 0){

      for(int ii = 0; ii <=i; ii++){
         if(pattern[ii] != '*')
            return 0;
      }
      return 1;
   }
   
   if(pattern[i] == text[j])
      return solveRec(i-1,j-1,pattern,text);

   if(pattern[i] == '?')
      return solveRec(i-1,j-1,pattern,text);

   if(pattern[i] == '*'){
      bool one = solveRec(i-1,j,pattern,text);
      bool sec = solveRec(i,j-1,pattern,text);
      return one || sec;
   }

   return 0;
   
}

bool solveMem(int i, int j, string &pattern, string &text,vector<vector<int>>&dp)
{
   // Base Cases
   if(i == 0 && j == 0)
      return 1;

   if(i == 0 && j > 0)
      return 0;

   if(i > 0 && j == 0){

      for(int ii = 0; ii <i; ii++){
         if(pattern[ii] != '*')
            return 0;
      }
      return 1;
   }

   if(dp[i][j] != -1)
      return dp[i][j];
   
   if(pattern[i-1] == text[j-1])
      return dp[i][j] = solveMem(i-1,j-1,pattern,text,dp);

   if(pattern[i-1] == '?')
      return dp[i][j] =  solveMem(i-1,j-1,pattern,text,dp);

   if(pattern[i-1] == '*'){
      bool one = solveMem(i-1,j,pattern,text,dp);
      bool sec = solveMem(i,j-1,pattern,text,dp);
      return dp[i][j] =  one || sec;
   }

   return dp[i][j] =  0;
   
}

bool solveTab(string &pattern, string &text){
   
   int m = pattern.size(), n = text.size();
   vector<vector<int>>dp(m+1, vector<int>(n+1,-1));

   // base cases
   dp[0][0] = 1;

   for(int j=1; j<=n; j++)
      dp[0][j] = 0;

   for(int i=1; i<=m; i++){
      int flag = 1;
      for(int ii = 0; ii <i; ii++){
         if(pattern[ii] != '*'){
            flag = 0;
         }
      }
      dp[i][0] = flag;
   }
   
   // nested loop and changing parameters

   for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){

         if(pattern[i-1] == text[j-1])
            dp[i][j] = dp[i-1][j-1];

         else if(pattern[i-1] == '?')
            dp[i][j] =  dp[i-1][j-1];

         else if(pattern[i-1] == '*'){
            bool one = dp[i-1][j];
            bool sec = dp[i][j-1];
            dp[i][j] =  one || sec;
         }
         else
            dp[i][j] =  0;

      }
   }
   
   return dp[m][n];
}


bool solveSpaceOpt(string &pattern, string &text){
   
   int m = pattern.size(), n = text.size();
   //vector<vector<int>>dp(m+1, vector<int>(n+1,-1));

   vector<int>prev(n+1,-1);

   // base case 1
   prev[0] = 1;

   // base case 2
   for(int j=1; j<=n; j++)
      prev[j] = 0;

   
   // nested loop and changing parameters

   for(int i=1; i<=m; i++){
      vector<int>curr(n+1,-1);
      // base case 3
      int flag = 1;
      for(int ii = 0; ii <i; ii++){
         if(pattern[ii] != '*'){
            flag = 0;
         }
      }
      curr[0] = flag;

      for(int j=1; j<=n; j++){

         if(pattern[i-1] == text[j-1])
            curr[j] = prev[j-1];

         else if(pattern[i-1] == '?')
            curr[j] =  prev[j-1];

         else if(pattern[i-1] == '*'){
            bool one = prev[j];
            bool sec = curr[j-1];
            curr[j] =  one || sec;
         }
         else
            curr[j] =  0;

      }
      prev = curr;
   }

   return prev[n];
}




bool wildcardMatching(string pattern, string text)
{
   int m = pattern.size(), n = text.size();
   //return solveRec(m-1,n-1,pattern,text);

   vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
   //return solveMem(m,n,pattern,text,dp);

   //return solveTab(pattern,text);

   return solveSpaceOpt(pattern,text);

}
