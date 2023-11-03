#include <bits/stdc++.h> 
int solveTabLongCommonSubSeq(string s1, string s2, int m, int n, vector<vector<int>>&dp);
string shortestSupersequence(string s1, string s2);


int solveTabLongCommonSubSeq(string s1, string s2, int m, int n, vector<vector<int>>&dp){

	// base case
	for(int i=0; i<=m; i++)
		dp[i][0] = 0;
	
	for(int j=0; j<=n; j++)
		dp[0][j] = 0;
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];

}


string shortestSupersequence(string s1, string s2)
{

	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
	int len = solveTabLongCommonSubSeq(s1,s2,m,n,dp);

//	Getting shortestSupersequence string
	string ans = "";
	int i=m,j=n;
	
	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			ans.push_back(s1[i-1]);
			i--;
		}
		else{
			ans.push_back(s2[j-1]);
			j--;
		}
	}

	// add remaining Strings
	while(i > 0){
		ans.push_back(s1[i-1]);
		i--;
	}
	
	while(j > 0){
		ans.push_back(s2[j-1]);
		j--;
	}
	
	// we get reversed shortestSupersequence string bcz we r traversing from end (m,n)
	reverse(ans.begin(), ans.end());

	return ans;

}
