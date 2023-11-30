class Solution
{
    public:
    
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(long long i=0; i<n; i++)
            pq.push(arr[i]);
        
        long long cost = 0;    
        while(pq.size() > 1){
            
            long long minLen1 = pq.top();
            pq.pop();
            long long minLen2 = pq.top();
            pq.pop();
            
            long long ToConnect = minLen1 + minLen2;
            cost += ToConnect;
            pq.push(ToConnect);
            
        }
        return cost;
    }
};
