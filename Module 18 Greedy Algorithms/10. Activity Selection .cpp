class Solution
{
    public:
    
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int>start, vector<int>end, int n)
    {
       vector<pair<int,int>>vect;
       for(int i=0; i<n; i++){
           vect.push_back(make_pair(start[i],end[i]));
       }
       
       sort(vect.begin(),vect.end(),cmp);
       
       int count = 1;
       int lastMeet = vect[0].second;
       for(int i=1; i<n; i++){
           if(lastMeet < vect[i].first ){
               count++;
               lastMeet = vect[i].second;
           }
       }
       return count;
    }
};
