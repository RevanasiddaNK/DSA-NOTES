/*
struct Item{
    int value;
    int weight;
};
*/

static bool comp(pair<double,Item>p,pair<double,Item>q){
    return p.first > q.first;
}

class Solution
{
    public:
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>>vect;
        
        for(int i=0; i<n; i++){
            double perUnitVal = (1.0 * arr[i].value)/arr[i].weight;
            pair<double,Item>p = make_pair(perUnitVal,arr[i]);
            vect.push_back(p);
        }
        
        sort(vect.begin(),vect.end(),comp);
        
        double TotalValue = 0;
        for(int i=0; i<n && W > 0 ; i++){
            
            if(vect[i].second.weight <= W){
                W -= vect[i].second.weight;
                TotalValue += vect[i].second.value;
            }
            else{
               TotalValue  += W*vect[i].first;
               W = 0;
            }
        }
        return  TotalValue;
    }
        
};
