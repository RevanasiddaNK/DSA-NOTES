#include<map>
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int>m;

    for(int i=0; i<n; i++)
        m[arr[i]]++;

    int ans = arr[0];
    for(int i=1; i<n; i++) {
        if(m[ans] < m[arr[i]])
            ans = arr[i];
    }
    return ans;
}