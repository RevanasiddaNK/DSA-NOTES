#include<bits/stdc++.h>

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}


bool compareStrings(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    if( m != 1 + n)
        return 0;

    int i=0,j=0;
    while(i<m){
        if(j < n && s1[i] == s2[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    
    if(i == m && j == n)
        return 1;
    else
        return 0;
}

int longestStrChain(vector<string> &words){
    sort(words.begin(),words.end() ,comp);
    int n = words.size();
    vector<int>dp(n,1);
    int maxi = 1;
    for(int i=1; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if( compareStrings(words[i], words[prev]) && dp[i] < 1 + dp[prev]){
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}
