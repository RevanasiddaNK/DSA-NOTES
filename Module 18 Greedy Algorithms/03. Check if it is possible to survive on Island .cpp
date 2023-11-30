class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sundays = S/7;
        int buyingDays = S-sundays;
        int totalFood = S*M;
        int minDaystoBuy = 0;
        if(totalFood%N == 0){
            minDaystoBuy = totalFood/N;
        }
        else{
            minDaystoBuy = totalFood/N + 1;
        }
        
        if(minDaystoBuy > buyingDays)
            return -1;
        else
            return minDaystoBuy;
    }
};
