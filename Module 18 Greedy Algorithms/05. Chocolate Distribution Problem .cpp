class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
        long long i = 0;
        long long mini = INT_MAX;
        
        sort(a.begin(),a.end());
        
        while(i+m-1 < n){
            long long diff = a[i+m-1] - a[i];
            mini = min(mini,diff);
            i++;
        }
        return mini;
    }   
};
