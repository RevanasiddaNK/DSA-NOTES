#include<bits/stdc++.h>

int solveBinarySearch(int arr[], int n){
    vector<int>temp;
    temp.push_back(arr[0]);
    int len = 0;
    for(int ind=1; ind<n; ind++){
        if(arr[ind] > temp.back()){
            temp.push_back(arr[ind]);
            len++;
        }
        else{
            auto iterato = lower_bound(temp.begin(),temp.end(),arr[ind]);
            int i = iterato - temp.begin();
            temp[i] = arr[ind];
        }
    }
    return temp.size();
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return solveBinarySearch(arr,n);
}
