/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
   
   static bool comp(Job a, Job b){
       return a.profit > b.profit;
   }
   
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,comp);
       
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
            maxi = max(maxi,arr[i].profit);
        
        vector<int>DeadlineSchedule(maxi+1,-1);
        
        int count = 0;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
           
           int CurrJobID = arr[i].id;
           int CurrJobDead = arr[i].dead;
           int CurrJobProfit = arr[i].profit;
           
           for(int k=CurrJobDead; k>0; k--){
               if(DeadlineSchedule[k] == -1){
                   DeadlineSchedule[k] = CurrJobID;
                   count++;
                   maxProfit += CurrJobProfit;
                   break;
               }
           }
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        
        return ans;
    } 
};
