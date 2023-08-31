class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long, vector<long long>, greater<long long> >minPQ;
       
        for(long long i=0; i < n ; i++)
            minPQ.push(arr[i]);
        
        long long ans = 0;
        while(minPQ.size() > 1) {
            
            long long num1 = minPQ.top();
            minPQ.pop();
            long long num2 = minPQ.top();
            minPQ.pop();
            
            long long sum = num1+num2;
            ans = ans + sum;
            
            minPQ.push(sum);
        }
        return ans;
    }
};
