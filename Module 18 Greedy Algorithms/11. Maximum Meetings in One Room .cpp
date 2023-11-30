class Solution{
public:

    class meet{
        public:
        int start;
        int end;
        int id;
    
         meet(int s,int e,int i){
            start = s;
            end = e;
            id = i;
        }
    
    };

    static bool comp(meet* a, meet* b){
        return a->end < b->end;
    }

    vector<int> maxMeetings(int N,vector<int> &S,vector<int>&F){
        vector<meet*>v;
        for(int i=0; i<N; i++){
            
            meet* temp = new meet(S[i],F[i],i+1);
        /*    
            meet* temp;
            temp->start = S[i];
            temp->end = F[i];
            temp->id = i+1;
        */    
            v.push_back(temp);
        }
        
        sort(v.begin(),v.end(),comp);
        
        vector<int>ans;
        int count = 1;
        int EndMeet = v[0]->end;
        ans.push_back(v[0]->id);
        for(int i=1; i<N; i++){
            if(v[i]->start > EndMeet){
                count++;
                EndMeet = v[i]->end;
                ans.push_back(v[i]->id);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
