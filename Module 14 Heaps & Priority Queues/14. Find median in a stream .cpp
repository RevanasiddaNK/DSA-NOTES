/*
Time Complexity : O(nlogn)
Auxilliary Space : O(n)
*/

class Solution
{
    public:
    
    priority_queue<double>maxi;
    priority_queue<double, vector<double>, greater<double> >mini;
    double median = 0;
    
    int signum(){
    
        double a = maxi.size();
        double b = mini.size();
    
        if(a == b)
            return 0;
        else if(a > b)
            return 1;
        else
            return -1;
        
    }
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        switch(signum()){
            
            case 0 : 
            
                if(x > median){
                    mini.push(x);
                    median = mini.top();
                }
                else{
                    maxi.push(x);
                    median = maxi.top();
                }
                
                break;
            
            case 1 :
                
                if(x > median){
                    mini.push(x);
                    // even size case
                    median = (mini.top()+maxi.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(x);
                    // even size case 
                    median = (mini.top()+maxi.top())/2;
                }
                
                break;
            
            case -1 :
                
                if(x > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(x);
                    median = (mini.top()+maxi.top())/2;
                }
                else{
                    maxi.push(x);
                    median = (mini.top()+maxi.top())/2;
                }
                
                break;
                
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};
