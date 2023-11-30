class Solution
{
    public:
  
    string reverseWords(string S) 
    { 
        string ans = "";
        string temp = "";
        
        int n = S.size();
        
        for(int i=n-1; i>=0; i--){
            
            if(S[i] == '.'){
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans.push_back('.');
                temp = "";
            }
            else
                temp.push_back(S[i]);
        }
        
        reverse(temp.begin(),temp.end());
        ans += temp;
        
        return ans;
    } 
};
