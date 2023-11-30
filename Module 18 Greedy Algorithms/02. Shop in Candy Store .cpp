class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
       sort(candies,candies+N);
       
       int mini = 0;
       int buy =0,fre=N-1;
       while(buy<=fre){
           mini += candies[buy++];
           fre -= k;
       }
       
       int maxi = 0;
       buy=N-1,fre=0;
       while(buy >= fre){
           maxi += candies[buy--];
           fre += k;
       }
       
       vector<int>ans;
       ans.push_back(mini);
       ans.push_back(maxi);
       
       return ans;
    }
};
